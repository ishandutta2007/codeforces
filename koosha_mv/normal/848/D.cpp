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

const int N=54,M=52,mod=1e9+7;

int n,m,ifac[N],ans[N][N],F[N][N],dp[N][N];

ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}

void make(){
	ifac[0]=1;
	f(i,1,N)
		ifac[i]=1ll*ifac[i-1]*i%mod;
	ifac[N-1]=pow(ifac[N-1],mod-2,mod);
	f_(i,N-2,1)
		ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;
}
int C(int k,int n){
	int res=1;
	n+=k-1;
	f_(i,n,n-k+1)
		res=1ll*res*i%mod;
	return 1ll*res*ifac[k]%mod;
}
void add(int n,int m){
	f_(i,M-1,n)
		f_(j,M-1,m)
			for(int k=1;k*n<=i && k*m<=j;k++){
				dp[i][j]=(dp[i][j]+1ll*C(k,F[n][m])*dp[i-k*n][j-k*m]%mod)%mod;
			}
}
void calc_F(int n,int m){
	f(i,0,n)	
		f(j,m,i+2){
			int n1=i,m1=j,n2=n-1-i,m2=m;
			//if(n==8 && m==1) cout<<n1<<" "<<m1<<" "<<n2<<" "<<m2<<endl<<dp[n1][m1]<<" "<<dp[n2][m2]<<endl;
			if(m1==m2)
				F[n][m]=(F[n][m]+1ll*dp[n1][m1]*dp[n2][m2]%mod)%mod;
			else
				F[n][m]=(F[n][m]+2ll*dp[n1][m1]*dp[n2][m2]%mod)%mod;
		}
	add(n,m);
}

main(){
	cin>>n>>m;
	make();
	F[0][0]=dp[0][1]=1;
	f(i,1,M)
		f(j,1,M)
			calc_F(i,j);
	cout<<dp[n][m]<<endl;
}