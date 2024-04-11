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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=70009;

int n,s,u,sum,dp[N],par[N],mark[N];
pair<int,int> a[N];
vector<int> v1,v2,ans[N];

int main(){
	dp[0]=1;
	cin>>n>>s;
	f(i,0,n){ gett(a[i].F);a[i].S=i; }
	sort(a,a+n);
	s-=a[n-1].F;
	if(s<0) return cout<<-1,0;
	f(i,0,n-1){
		f_(j,min(s,sum+a[i].F),a[i].F)
			if(dp[j]==0 && dp[j-a[i].F]==1)
				dp[j]=1,par[j]=i;
		if(dp[s]) break;
		sum+=a[i].F;
	}
	if(dp[s]==0) return cout<<-1,0;
	u=s;
	mark[n-1]=1;
	while(u){
		mark[par[u]]=1;
		u-=a[par[u]].F;
	}
	f(i,0,n){
		if(mark[i] && i!=n-1) v1.pb(i);
		else v2.pb(i);
	}
	f(i,0,v1.size())
		ans[a[v1[i]].S].pb(a[v1[i]].F),ans[a[v1[i]].S].pb(0);
	ans[a[v2[0]].S].pb(a[v2[0]].F),ans[a[v2[0]].S].pb(0);
	f(i,1,v2.size())
		ans[a[v2[i]].S].pb(a[v2[i]].F-a[v2[i-1]].F),ans[a[v2[i]].S].pb(1),ans[a[v2[i]].S].pb(a[v2[i-1]].S+1);
	f(i,0,n){
		f(j,0,ans[i].size())
			cout<<ans[i][j]<<" ";
		cout<<'\n';
	}
}