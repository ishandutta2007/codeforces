#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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

const int N=102;

int n,u,v,tf,mn,ans,res,val,mark[5],edge[N][3];
vector<pair<int,int> > g[5];

void dfs(int x){
	mark[x]=1;
	if(g[x].size()%2) tf++;
	f(i,0,g[x].size()){
		res+=g[x][i].S,minm(mn,g[x][i].S);
		if(!mark[g[x][i].F])
			dfs(g[x][i].F);
	}
}
void calc(){
	mark[1]=mark[2]=mark[3]=mark[4]=0;
	f(i,1,5)
		if(!mark[i]){
			res=0,tf=0;
			dfs(i);
			if(tf<3)
				maxm(ans,res/2);
		}
}
void solve(){
	f(i,0,n+1)
		f(j,0,i+1){
			f(p,0,5) g[p].clear();
			f(k,0,n){
				if(k!=i && k!=j)
					g[edge[k][0]].pb(mp(edge[k][1],edge[k][2])),g[edge[k][1]].pb(mp(edge[k][0],edge[k][2]));
			}
			calc();
		}
}

int main(){
	cin>>n;
	f(i,0,n){
		cin>>u>>val>>v;
		edge[i][0]=u,edge[i][1]=v,edge[i][2]=val;
	}
	solve();
	cout<<ans;
}