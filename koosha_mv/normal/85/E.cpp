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

const int N=5005,mod=1e9+7;

int n,ans,mid,l=-1,r=N+N,mark[N],dist[N],a[N][2];
vector<int> g[N];

void make_graph(int x){
	f(i,1,n+1) g[i].clear();
	f(i,1,n+1)
		f(j,1,n+1)
			if(i!=j && abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1])>x)
				g[i].pb(j);
}
void dfs(int x,int fa){
	mark[x]=1,dist[x]=fa;
	f(i,0,g[x].size())
		if(mark[g[x][i]] && dist[g[x][i]]==dist[x])
			ans=0;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i],1-fa);
}
int check(){
	fill(mark,mark+N,0);
	ans=1;
	f(i,1,n+1)
		if(!mark[i])
			dfs(i,0),ans=ans*2ll%mod;
	return ans;
}

int main(){
	cin>>n;
	f(i,1,n+1)
		cin>>a[i][0]>>a[i][1];
	while(l+1<r){
		mid=(l+r)/2;
		make_graph(mid);
		if(check()) r=mid;
		else l=mid;
	}
	make_graph(r);
	cout<<r<<endl<<check();
}