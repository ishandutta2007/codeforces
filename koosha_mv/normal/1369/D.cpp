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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second

const int N=2e6+99,mod=1e9+7;

int n,t,dp[N],F[N];

main(){
	dp[3]=dp[4]=4;
	F[4]=4;
	f(i,5,N){
		F[i]=(dp[i-1]+dp[i-2]*2ll)%mod;
		dp[i]=max(1ll*F[i],(F[i-2]*2ll+F[i-1]+4ll)%mod);
	}
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n]<<endl;
	}
}