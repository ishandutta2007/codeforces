#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e6+9;
ll t,n,m,x,y,cnt,mark[N],dp[N],ans,mark1[N],mark2[N];
vector<int> g[N],g1[N];
void dfs(int x){
	mark[x]=1,cnt++;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]) dfs(g[x][i]);	
	}
}
void dfs2(int x){
	mark2[x]=1;
	f(i,0,g1[x].size()) if(!mark2[g1[x][i]]) dfs2(g1[x][i]);
}
void dfs1(int x){
	mark1[x]=1,cnt++;
	f(i,0,g[x].size()) if(!mark1[g[x][i]]) dfs1(g[x][i]);
}
int main(){
	cin>>t;
	f(q,0,t){
		Get(n,m)
		f(i,1,n+1) g[i].clear(),mark[i]=0,mark1[i]=0,mark2[i]=0,g1[i].clear();
		f(i,0,m){
			Get(x,y);
			if(x!=y) g[x].pb(y),g1[y].pb(x);
		}
		cnt=0,ans=1;
		dfs(1);dfs2(1);
		f(i,1,n+1)
			if(mark2[i]==0) ans=i;
		if(cnt<n || ans!=1){
			cout<<"YES"<<endl;
			cnt=0;dfs1(ans);
			cout<<cnt<<" "<<n-cnt<<endl;
			f(i,1,n+1)
				if(mark1[i]) cout<<i<<" ";
			cout<<endl;
			f(i,1,n+1)
				if(!mark1[i]) cout<<i<<" ";
			cout<<endl;
		}
		else cout<<"NO"<<endl;
	}
}