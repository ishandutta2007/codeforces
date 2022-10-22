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

int n,m,x,y,t,b[N],mark[N];
vector<int> g[N];
pair<int,int> a[N];

int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,1,n+1){ gett(a[i].F); a[i].S=i; b[i]=a[i].F; }
	sort(a+1,a+1+n);
	f(i,1,n+1){
		int u=a[i].S;
		if(a[i].F>g[u].size()+1) return cout<<-1,0;
		f(j,0,g[u].size())
			mark[b[g[u][j]]]=i;
		if(mark[a[i].F]==i) return cout<<-1,0;
		f(j,1,a[i].F)
			if(mark[j]!=i)
				return cout<<-1,0;
	}
	f(i,1,n+1)
		cout<<a[i].S<<" ";
}