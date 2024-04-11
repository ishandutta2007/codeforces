#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+9;
int n,x,y,mark[N],sub[N],a,u,mx,dis[N];
vector<int> g[N];
void found_centroid(int x,int c){
	mark[x]=c;
	sub[x]=1;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			found_centroid(g[x][i],c);
			sub[x]+=sub[g[x][i]];
		}
	}
}
void dfs(int x,int dist,int c,int e){
	mark[x]=0;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==c)
			dfs(g[x][i],dist+1,c,e);
	}
	if(sub[x]>=e && dist>mx)
		mx=dist,u=x;
}
void solve(int x,int h,int c){
	mx=-1;
	found_centroid(x,c);
	dfs(x,0,c,sub[x]/2);
	cout<<"d "<<u<<endl;
	cin>>a;
	if(a==0){
		cout<<"! "<<u<<endl;
		exit(0);
	}
	mark[u]=1;
	if(a+mx==h){
		cout<<"s "<<u<<endl;
		cin>>a;
		solve(a,h-mx-1,c+1);
	}
	else
		solve(x,h,c+1);
}
int main(){
	cin>>n;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	cout<<"d "<<1<<endl;
	cin>>a;
	solve(1,a,1);
}