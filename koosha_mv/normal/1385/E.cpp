#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,m,c,T,ans,type,topo[N],mark[N];
pair<int,int> edge[N];
vector<int> g[N];

void dfs(int u){
	mark[u]=2;
	f(i,0,g[u].size()){
		if(!mark[g[u][i]])
			dfs(g[u][i]);
		if(mark[g[u][i]]==2)
			ans=1;
	}
	mark[u]=1;
	topo[u]=++c;
}
void solve(){
	f(i,1,n+1) g[i].clear(),mark[i]=0;
	ans=0,c=0;
	cin>>n>>m;
	f(i,0,m){
		cin>>type>>edge[i].F>>edge[i].S;
		if(type) g[edge[i].F].pb(edge[i].S);	
	}
	f(i,1,n+1)
		if(!mark[i])
			dfs(i);
	if(ans)
		cout<<"NO"<<'\n';
	else{
		cout<<"YES"<<'\n';
		f(i,0,m){
			if(topo[edge[i].F]<topo[edge[i].S])
				swap(edge[i].F,edge[i].S);
			cout<<edge[i].F<<" "<<edge[i].S<<'\n';
		}
	}
}
int main(){
	cin>>T;
	while(T--)
		solve();
}