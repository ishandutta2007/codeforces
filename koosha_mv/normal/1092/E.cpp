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
const int N=1003;
int n,m,ans,x,y,cnt,mark[N],dp[N],a[N];
vector<int> g[N];
pair<int,int> cmp[N];
void dfs1(int x,int par){
	vector<int> v;v.pb(0);v.pb(0),v.pb(0);
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs1(g[x][i],x);
			v[0]=dp[g[x][i]]+1;
			sort(v.begin(),v.end());
			maxm(dp[x],dp[g[x][i]]+1);
		}
	}
	maxm(ans,v[1]+v[2]);
}
void dfs2(int x,int par,int fp){
	mark[x]=1;
	vector<int> v;v.pb(0),v.pb(0),v.pb(fp);
	int mx=0;
	f_(i,g[x].size()-1,0){
		if(g[x][i]!=par){
			a[g[x][i]]=mx;
			maxm(mx,dp[g[x][i]]+1);
		}
	}
	mx=fp;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs2(g[x][i],x,max(mx+1,a[g[x][i]]+1));
			maxm(mx,dp[g[x][i]]+1);
		}
	}
	if(max(fp,dp[x])<cmp[cnt].F)
		cmp[cnt].F=max(fp,dp[x]),cmp[cnt].S=x;
}
int main(){
	Gett(n,m);
	f(i,0,m){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,1,n+1){
		if(!mark[i]){
			cmp[cnt].F=N;
			dfs1(i,0);
			dfs2(i,0,0);
			cnt++;
		}
	}
	sort(cmp,cmp+cnt);
	if(cnt>1) maxm(ans,cmp[cnt-1].F+cmp[cnt-2].F+1);
	if(cnt>2) maxm(ans,cmp[cnt-2].F+cmp[cnt-3].F+2);
	cout<<ans<<endl;
	f(i,0,cnt-1)
		cout<<cmp[i].S<<" "<<cmp[cnt-1].S<<endl;
}