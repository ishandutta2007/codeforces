#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+9;
const ll inf=-1e18,e=-1e17;

int n,m,c,l,r,x,a[N],p[N],b[N],mark[N],ans[N];
ll sum,dp[N];
vector<pair<int,ll> > tree[N*2];

void merge(int x,int u,int v){
	int p1=0,p2=0;
	ll sum1=0,sum2=0;
	while(p1<tree[u].size() || p2<tree[v].size()){
		if(p1==tree[u].size() || (p2<tree[v].size() && tree[v][p2].F<tree[u][p1].F)) tree[x].pb(mp(tree[v][p2].F,sum1+tree[v][p2].S)),sum2=tree[v][p2++].S;
		else tree[x].pb(mp(tree[u][p1].F,sum2+tree[u][p1].S)),sum1=tree[u][p1++].S;
	}
}
void build(int id = 1,int l = 0,int r = n){
	f(i,n,2*n)
		tree[i].pb(mp(a[i-n+1],max(p[i-n+1],0)));
	f_(i,n-1,1)
		merge(i,i*2,i*2+1);
}
ll binary_search(int an,int x){
	int l=-1,r=tree[an].size(),mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(tree[an][mid].F<=x) l=mid;
		else r=mid;
	}
	return(l==-1 ? 0:tree[an][l].S);
}
ll query(int l, int r,int x) {
	ll res=0;
	--l;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1)
   		res+=binary_search(l++,x);
   	if (r&1)
   		res+=binary_search(--r,x);
	}
  	return res;
}

int main(){
	cin>>n;
	f(i,1,n+1) gett(a[i]);
	f(i,1,n+1){ gett(p[i]); sum+=p[i]; }
	cin>>m;
	f(i,1,m+1) dp[i]=inf;
	f(i,1,m+1){ gett(b[i]); mark[b[i]]=i; }
	build();
	f(i,1,n+1)
		if(mark[a[i]]){
			ll res=0;
			res=dp[mark[a[i]]-1]+query(i+1,n,a[i])-query(i,n,b[mark[a[i]]-1])+p[i];
			maxm(dp[mark[a[i]]],res);
		}
	cout<<(dp[m]<=e ? "NO" : "YES")<<endl;
	if(dp[m]>e) cout<<sum-dp[m];
}