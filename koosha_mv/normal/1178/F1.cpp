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

const int M=1e6+9,N=1003,mod=998244353;

int n,m,x,p,mn,last,c[M],t[N],cnt[N],dp[N][N];

int calc(int l,int r){
	int mn_el=N,mn_an=N,mx_an=0,last_an=-1;
	int res=1,ans1=0,ans2=0;
	if(l>=r) return 1;
	if(dp[l][r]!=-1) return dp[l][r];
	f(i,l,r+1){
		minm(mn_el,c[i]);
		cnt[c[i]]=0;
	}
	f(i,l,r+1)
		cnt[c[i]]++;
	f(i,l,r+1)
		if(cnt[c[i]]!=t[c[i]])
			return dp[l][r]=0;
	f(i,l,r+1)
		if(c[i]==mn_el){
			if(last_an!=-1)
				res=1ll*res*calc(last_an+1,i-1)%mod;
			last_an=i;
			maxm(mx_an,i);
			minm(mn_an,i);
		}
	f(i,l-1,mn_an)
		ans1=(ans1+1ll*calc(l,i)*calc(i+1,mn_an-1)%mod)%mod;
	f(i,mx_an,r+1)
		ans2=(ans2+1ll*calc(mx_an+1,i)*calc(i+1,r)%mod)%mod;
	dp[l][r]=1ll*res*ans1%mod*ans2%mod;
	return dp[l][r];
}
int main(){
	f(i,0,N) f(j,0,N) dp[i][j]=-1;
	cin>>n>>m;
	f(i,0,m){
		gett(x);
		if(x!=last)
			c[p++]=x;
		last=x;
	}m=p;
	
	if(n*2<=m)
		return cout<<0,0;
	f(i,0,m){
		t[c[i]]++;
		mn=N;
		f(j,i+2,m){
			minm(mn,c[j-1]);
			if(c[i]==c[j] && mn<c[i]) return cout<<0,0;
		}
	}
	cout<<calc(0,m-1);
}