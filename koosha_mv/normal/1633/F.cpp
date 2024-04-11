#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99;
 
int n,t,last,cnt=1,a[N],X[N],Y[N],up[N],sz[N],ts[N],st[N],ft[N],lazy[N<<2],par[N],mark[N];
vector<int> ans,g[N];
 
void shift(int ,int ,int );
bool cmp(int i,int j){
	return sz[i]>sz[j];
}
struct node{
	int cnt0,cnt1,sum0,sum1;
	node(){
		cnt0=cnt1=sum0=sum1=0;
	}
} seg[N<<2];
 
 
void finda(){
	f(i,1,n){
		if(sz[X[i]]>sz[Y[i]]){
			a[Y[i]]=i;
		}
		else{
			a[X[i]]=i;
		}
	}
}
node merge(node u,node v){
	u.cnt0+=v.cnt0;
	u.cnt1+=v.cnt1;
	u.sum0+=v.sum0;
	u.sum1+=v.sum1;
	return u;
}
void build(int id=1,int l=0,int r=n){
	if(l+1==r){
		if(l==0){
			seg[id].cnt1=1;
		}
		else{
			seg[id].cnt0=1;
			seg[id].sum0=a[ts[l]];
			//if(l==3) eror(seg[id].sum0);
		}
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
void change(int L,int R,int id=1, int l=0,int r=n){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]^=1;
      swap(seg[id].cnt0,seg[id].cnt1);
      swap(seg[id].sum0,seg[id].sum1);
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id,l,r);
   change(L,R,id*2+0,l,mid);
   change(L,R,id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
void shift(int id,int l,int r){
	if(lazy[id]==0) return ;
	int mid=(l+r)>>1;
   change(l,mid,id<<1,l,mid);
   change(mid,r,id<<1|1,mid,r);
   lazy[id]=0;
}
void dfs1(int u,int p){
	sz[u]=1;
	par[u]=p;
	for(auto v : g[u]){
		if(v==p) continue ;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
	f(i,0,g[u].size()){
		if(g[u][i]==p){
			g[u].erase(g[u].begin()+i);
			break;
		}
	}
	sort(all(g[u]),cmp);
}
void dfs2(int u){
	st[u]=t;
	ts[t++]=u;
	f(i,0,g[u].size()){
		if(i==0){
			up[g[u][i]]=up[u];
		}
		else{
			up[g[u][i]]=g[u][i];
		}
		dfs2(g[u][i]);
	}
	ft[u]=t;
}
void dfs3(int u){
	sz[u]=mark[u];
	for(auto v : g[u]){
		dfs3(v);
		sz[u]+=sz[v];
	}
	if(sz[u]&1){
		ans.pb(a[u]);
	}
	//cout<<u<<" -> "<<sz[u]<<endl;
}
void rev(int u){
	mark[u]=1;
	cnt++;
	int pert=0;
	while(u>0){
		pert++;
		change(st[up[u]],st[u]+1);
		u=par[up[u]];
	}	
}
void Print(){
	if(last==0){
		cout<<0<<endl;
		return ;
	}
	ans.clear();
	dfs3(1);
	sort(all(ans));
	cout<<ans.size()<<" "; f(i,0,ans.size()) cout<<ans[i]<<" ";
	cout<<endl;
}
 
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mark[1]=1;
	cin>>n;
	f(i,1,n){
		cin>>X[i]>>Y[i];
		g[X[i]].pb(Y[i]);
		g[Y[i]].pb(X[i]);
	}
	up[1]=1;
	dfs1(1,0);
	dfs2(1);
	finda();
	build();
	while(1){
		int type;
		cin>>type;
		if(type==1){
			int u;
			cin>>u;
			rev(u);
			if(2*seg[1].cnt1==cnt){
				cout<<seg[1].sum1<<endl;
				last=1;
			}
			else{
				cout<<0<<endl;
				last=0;
			}
		}
		else{
			if(type==3) break;
			Print();
		}
	}
}