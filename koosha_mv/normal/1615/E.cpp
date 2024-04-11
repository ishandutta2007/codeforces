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
#define pi pair<int,int>

const int N=1e6+99;

int n,m,k,cnt=1,st[N],ft[N],pt[N],a[N],par[N],mark[N],lazy[N];
pair<int,int> seg[N];
vector<int> g[N];
ll ans=-1e18;

pi merge(pi u,pi v){
	return max(u,v);
}
void shift(int id){
   seg[id*2+0].F+=lazy[id];
   seg[id*2+1].F+=lazy[id];
   lazy[id*2+0]+=lazy[id];
   lazy[id*2+1]+=lazy[id];
   lazy[id]=0;
}
void build(int id=1,int l=1,int r=n+1){
	if(l+1==r){
		seg[id]={a[pt[l]],pt[l]};
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
void add(int L,int R,int val,int id=1, int l=1,int r=n+1){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id].F+=val;
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}

void dfs1(int u,int p){
	//eror(a[u]);
	par[u]=p;
	pt[cnt]=u;
	st[u]=cnt++;
	for(auto v : g[u]){
		if(v==p) continue ;
		a[v]=a[u]+1;
		dfs1(v,u);
	}
	if(u==1 || g[u].size()>1) a[u]=-N;
	ft[u]=cnt;
}
ll calc(int u,int v,int x){
	int l=-1,r=x;
	while(l+1<r){
		int mid=(l+r)/2;
		if(1ll*(u-mid)*(v-mid)>= 1ll*(u-mid-1)*(v-mid-1)) l=mid;
		else r=mid;
	}
	//eror(l);
	//cout<<u<<" "<<v<<" "<<x<<" : "<<1ll*(u-r)*(v-r)<<endl;
	return 1ll*(u-r)*(v-r);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	a[1]=1;
	cin>>n>>k; m=n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,0);
	build();
	ans=calc(0,n,n);
	f(i,1,k+1){
		//erorp(seg[1]);
		int u=seg[1].S;
		while(!mark[u] && u>0 && u<=n){
			mark[u]=1; m--;
			add(st[u],ft[u],-1);
			u=par[u];
		}
		maxm(ans,calc(i,n-i,m));
	}
	//eror(m);
	cout<<ans;
}
/*
7 7
7 3
1 2
1 3
4 2
3 5
6 3
*/