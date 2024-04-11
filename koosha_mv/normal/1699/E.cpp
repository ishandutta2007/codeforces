#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e6+99;

int n,m,t,a[N],dp[N],Max[N],mark[N],last[N];
vector<int> A;

void Main(){	
	int Min=N;
	cin>>n>>m;
	f(i,1,m+1) last[i]=Max[i]=mark[i]=0,dp[i]=i;
	f(i,0,n){
		cin>>a[i];
		mark[a[i]]=1;
		minm(Min,a[i]);
	}
	f_(i,m,1){
		for(int j=min(1ll*i*i,1ll*N);j<=m;j+=i){
			if(mark[j]){
				maxm(Max[i+1],dp[j]);
			}
			minm(dp[j],dp[j/i]);
		}
	}
	f(i,0,n) maxm(Max[1],dp[a[i]]);
	int mx=0,ans=N;
	f(i,1,Min+1){
		maxm(mx,Max[i]);
		minm(ans,mx-i);
	}
	cout<<ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
2 35
6 35
*/