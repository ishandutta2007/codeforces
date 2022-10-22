#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+99;
ll n,a[N],cnt,mark[N],dst[N],x,y,q,k,ans1,ans2,ans3,a1,b1;
vector<int> g[N],dist[N];
void dfs(int x,int dis){
	mark[x]=1,dst[x]=dis,a[x]=cnt++;
	dist[dis].pb(x);
	f(i,0,g[x].size())
		if(mark[g[x][i]]==0) dfs(g[x][i],dis+1);
}
bool check(ll p,ll x,ll y){
	ll l1=-1,r1=dist[p].size(),mid1;
	while(l1+1<r1){
		mid1=(l1+r1)/2;
		if(a[dist[p][mid1]]<=x) l1=mid1;
		else r1=mid1;}
	if(a[dist[p][l1]]<=y) return 1;
	else return 0;
}
ll min_dis(ll x,ll y){
	ll l=0,r=min(dst[x],dst[y])+1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid,max(a[x],a[y]),min(a[x],a[y]))) l=mid;
		else r=mid;
	}
	return dst[x]+dst[y]-l*2;
}
int main(){
	cin>>n;
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	cin>>q;
	f(i,0,q){
		cin>>x>>y>>a1>>b1>>k;
		ans1=min_dis(a1,b1),ans2=min_dis(a1,x)+min_dis(b1,y)+1,ans3=min_dis(a1,y)+min_dis(b1,x)+1;
		if((ans1<=k && ans1%2==k%2) ||(ans2<=k && ans2%2==k%2) || (ans3<=k && ans3%2==k%2)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}