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

const int N=5e5+99;

int n,k,m,u,v,s,d[2],dist[N],mark[N],masir[N];
vector<int> g[N];

void dfs(int x,int par,int fa){
	mark[x]=1,dist[x]=fa;
	d[fa%2]++,masir[fa]=x;
	f(i,0,g[x].size())
		if(mark[g[x][i]] && g[x][i]!=par && dist[x]-dist[g[x][i]]<k){
			cout<<2<<endl;
			cout<<dist[x]-dist[g[x][i]]+1<<endl;
			f_(j,fa,0){
				cout<<masir[j]<<" ";
				if(masir[j]==g[x][i])
					exit(0);
			}
		}
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i],x,fa+1);
}
void dfs1(int x){
	mark[x]=1,masir[dist[x]]=x;
	f(i,0,g[x].size())
		if(dist[g[x][i]]<dist[x]-1 && mark[g[x][i]]){
			for(int j=dist[x];k;j-=2,k--)
				cout<<masir[j]<<" ";
		}
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs1(g[x][i]);
}
int main(){
	cin>>n>>m>>k;
	f(i,0,m){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0,0);
	k=(k/2)+k%2;
	cout<<1<<endl;
	if(m==n-1){
		if(d[0]>d[1]) s=0;
		else s=1;
		for(int i=1;k;i++)
			if(dist[i]%2==s){
				cout<<i<<" ";
				k--;
			}
	}
	fill(mark,mark+N,0);
	dfs1(1);
	
}