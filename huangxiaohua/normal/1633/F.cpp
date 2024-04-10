#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 200500
int i,j,k,n,m,t,siz[N],w[N],w2[N],son[N],top[N],dep[N],it,fa[N],rt,tot,chk;
int l[N],r[N],vis[N],vis2[N];
ll res;
vector<pair<int,int> > v[N];
set<int> s;
void dfs(int x,int f){
	siz[x]++;fa[x]=f;
	dep[x]=dep[f]+1;
	for(auto [i,j]:v[x]){
		if(i==f)continue;
		dfs(i,x);siz[x]+=siz[i];
		if(siz[i]>siz[son[x]])son[x]=i;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;
	l[x]=++it;w[it]=siz[x];
	if(son[x])dfs2(son[x],tp);
	for(auto [i,j]:v[x]){
		if(i==fa[x]){
			w2[l[x]]=j;continue;
		}
		if(i==son[x])continue;
		dfs2(i,i);
	}
	r[x]=it;
}
void dfs3(int x,int fa){
	for(auto [i,j]:v[x]){
		if(i==fa||!vis2[i])continue;
		dfs3(i,x);
	}
	if(!vis[x]){
		vis[x]=vis[fa]=1;s.insert(w2[l[x]]);
	}
}
#define fi first
#define se second
pair<ll,ll> operator +(const pair<ll,ll> &a,const pair<ll,ll> &b){return {a.fi+b.fi,a.se+b.se};}
pair<ll,ll> operator *(const pair<ll,ll> &a,int b){return {a.fi*b,a.se*b};}
struct SB{
	#define md ((l+r)>>1)
	#define ls (id<<1)
	#define rs (ls+1)
	#define hb() f[id]=f[ls]+f[rs]
	pair<ll,ll> f[N*4];
	bool t[N*4];
	void build(int id,int l,int r){
		if(l==r){
			if(l==1)f[id]={w2[l],1};
			else f[id]={-w2[l],-1};
			return;
		}
		build(ls,l,md);build(rs,md+1,r);hb();
	}
	void push(int id,int l,int r){
		if(!t[id])return;
		t[ls]^=1;t[rs]^=1;
		f[ls]=f[ls]*-1;f[rs]=f[rs]*-1;
		t[id]=0;
	}
	void add(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			t[id]^=1;
			f[id]=f[id]*-1;return;
		}
		push(id,l,r);
		if(x<=md)add(ls,l,md,x,y);
		if(y>md)add(rs,md+1,r,x,y);
		hb();
	}
	pair<ll,ll> get(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			return f[id];
		}
		push(id,l,r);
		if(y<=md)return get(ls,l,md,x,y);
		if(x>md)return get(rs,md+1,r,x,y);
		return get(ls,l,md,x,y)+get(rs,md+1,r,x,y);
	}
}sb;
void hld_add(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		sb.add(1,1,n,l[top[y]],l[y]);
		y=fa[top[y]];
	}
	if(dep[x]>dep[y])swap(x,y);
	sb.add(1,1,n,l[x],l[y]);
}
pair<ll,ll> hld_get(int x,int y,pair<ll,ll> res={0,0}){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		res=res+sb.get(1,1,n,l[top[y]],l[y]);
		y=fa[top[y]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res=res+sb.get(1,1,n,l[x],l[y]);
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back({k,i});
		v[k].push_back({j,i});
	}
	dfs(1,0);
	dfs2(1,1);
	sb.build(1,1,n);
	pair<ll,ll> ans={0,1};
	vis2[1]=1;tot=1;
	while(1){
		int ty;cin>>ty;
		if(!ty)return 1;
		if(ty==3)return 0;
		if(ty==1){
			cin>>k;
			vis2[k]=1;
			tot++;
			hld_add(1,k);
			ans=ans+hld_get(1,k);
			chk=((ans.se+ans.se)==tot);
			cout<<(ans.fi*chk)<<endl;
		}
		else{
			if(!chk){cout<<0<<endl;continue;}
			memset(vis,0,sizeof(vis));s.clear();
			cout<<ans.se<<' ';
			dfs3(1,0);
			for(auto i:s){cout<<i<<' ';}cout<<endl;
		}
	}
}