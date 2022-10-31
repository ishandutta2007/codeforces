#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,siz[100500],w2[100500],w[100500],son[100500],top[100500],dep[100500],it,fa[100500],rt;
int l[100500],r[100500];
ll res,len[100500],inv[100500],r2;
ll x,y,z;

ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
vector<int> v[100500],q1[100500],q2[100500];

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

void dfs(int x,int f){
	siz[x]++;fa[x]=f;
	dep[x]=dep[f]+1;
	for(auto i:v[x]){
		if(i==f)continue;
		dfs(i,x);
		if(siz[i]>siz[son[x]])son[x]=i;
	}
}

void dfs2(int x,int tp){
	top[x]=tp;
	l[x]=++it;w2[it]=w[x];
	if(son[x])dfs2(son[x],tp);
	for(auto i:v[x]){
		if(i==son[x]||i==fa[x])continue;
		dfs2(i,i);
	}
	r[x]=it;
}

struct SB{
	#define md ((l+r)>>1)
	#define ls (id<<1)
	#define rs (ls+1)
	#define hb() f[id]=su(f[ls],f[rs])
	
	ll f[400500],t[400500];
	
	void build(int id,int l,int r){
		if(l==r){f[id]=w2[l];return;}
		build(ls,l,md);build(rs,md+1,r);hb();
	}
	
	void push(int id,int l,int r){
		t[ls]=su(t[ls],t[id]);t[rs]=su(t[rs],t[id]);
		f[ls]=su(f[ls],(md-l+1)*t[id]%M);f[rs]=su(f[rs],(r-md)*t[id]%M);
		t[id]=0;
	}
	
	void add(int id,int l,int r,int x,int y,ll w){
		if(x<=l&&r<=y){
			t[id]=su(t[id],w);
			f[id]=su(f[id],(r-l+1)*w%M);return;
		}
		push(id,l,r);
		if(x<=md)add(ls,l,md,x,y,w);
		if(y>md)add(rs,md+1,r,x,y,w);hb();
	}
	
	ll get(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			return f[id];
		}
		push(id,l,r);
		if(y<=md)return get(ls,l,md,x,y);
		if(x>md)return get(rs,md+1,r,x,y);
		return su(get(ls,l,md,x,y),get(rs,md+1,r,x,y));
	}
}sb;

void hld_add(int x,int y,ll w){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		sb.add(1,1,n,l[top[y]],l[y],w);
		y=fa[top[y]];
	}
	if(dep[x]>dep[y])swap(x,y);
	sb.add(1,1,n,l[x],l[y],w);
}

ll hld_get(int x,int y,ll res=0){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		res=su(res,sb.get(1,1,n,l[top[y]],l[y]));
		y=fa[top[y]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res=su(res,sb.get(1,1,n,l[x],l[y]));
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j>>k;
		q1[j].push_back(i);
		q2[k].push_back(i);
		len[i]=k-j+1;
		inv[i]=ksm(len[i],M-2);
	}
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0);
	dfs2(1,1);
	
	for(t=1;t<=100000;t++){
		for(auto i:q1[t]){
			x=su(x,dep[i]*inv[i]%M);
			y=su(y,inv[i]);
			z=su(z,dep[i]*inv[i]%M*inv[i]%M);
			
			r2=su(r2,hld_get(1,i)*inv[i]%M);
			hld_add(1,i,inv[i]);
		}
		
		res=su(res,su(x*y%M,M-z) );
		res=su(res,M-r2*2%M);
		
		
		for(auto i:q2[t]){
			x=su(x,M-dep[i]*inv[i]%M);
			y=su(y,M-inv[i]);
			z=su(z,M-dep[i]*inv[i]%M*inv[i]%M);
			
			hld_add(1,i,M-inv[i]);
			r2=su(r2,M-hld_get(1,i)*inv[i]%M);
		}
	}
	
	for(i=1;i<=n;i++)res=res*len[i]%M;
	
	cout<<res;
}