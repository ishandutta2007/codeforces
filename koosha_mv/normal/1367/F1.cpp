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
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=4000;

int n,t,ans,a[N],b[N];
map<int,int> adj,dp;

int main(){
	cin>>t;
	f(q,0,t){
		adj.clear(),dp.clear();
		ans=0;
		cin>>n;
		b[0]=-1;
		f(i,1,n+1){ cin>>a[i]; b[i]=a[i]; }
		sort(b+1,b+1+n);
		f(i,1,n+1) adj[b[i]]=b[i-1];
		f(i,1,n+1){
			dp[a[i]]=dp[adj[a[i]]]+1;
			maxm(ans,dp[a[i]]);
		}
		cout<<n-ans<<endl;
	}
}