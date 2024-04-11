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

const int N=5004;

int an=0,n,m,n1,n2,n3,u,v,c=1,t[2],col[N*2],mark[N],dist[N],ans[N],s[N*2];
pair<int,int> dp[N][N];
vector<int> g[N];

void dfs(int x,int dis){
	dist[x]=dis,mark[x]=1;
	col[x]=c+dis%2;
	t[dis%2]++;
	f(i,0,g[x].size())
		if(mark[g[x][i]] && dist[g[x][i]]%2==dist[x]%2){
			cout<<"NO";
			exit(0);
		}
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i],dis+1);
	
}
int main(){
	f(i,0,N) f(j,0,N) dp[i][j].F=-1;
	dp[0][0].F=0;
	
	cin>>n>>m>>n1>>n2>>n3;
	f(i,0,m){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1){
		if(!mark[i]){
			t[0]=t[1]=0;
			an++;
			dfs(i,0);
			f_(k,n,0){
				if(dp[an-1][k-t[1]].F>=0){
					dp[an][k].F=k-t[1],dp[an][k].S=c+1;
				}
				else{
					if(dp[an-1][k-t[0]].F>=0) dp[an][k].F=k-t[0],dp[an][k].S=c;
					else dp[an][k].F=-1;
				}
			}
			c+=2;
		}
	}
	if(dp[an][n2].F==-1) return cout<<"NO",0;
	cout<<"YES"<<endl;
	int now1=n2,now2=an;
	while(now1>0){
		s[dp[now2][now1].S]=1;
		now1=dp[now2][now1].F;
		now2--;
	}
	f(i,1,n+1) if(s[col[i]]) ans[i]=2;
	f(i,1,n+1){
		if(ans[i]==0){
			if(n1>0) n1--,ans[i]=1;
			else ans[i]=3;
		}
	}
	f(i,1,n+1) cout<<ans[i];
}