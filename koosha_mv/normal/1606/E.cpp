#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=505,mod=998244353;

int n,k,dp[N][N],C[N][N],Pow[N][N];

int main(){
	f(i,0,N){
		Pow[i][0]=1;
		C[0][i]=1;
		f(j,1,N){
			C[j][i]=(C[j-1][i-1]+C[j][i-1])%mod;
			Pow[i][j]=1ll*i*Pow[i][j-1]%mod;
		}
	}
	cin>>n>>k;
	f(i,1,k+1) dp[0][i]=1;
	f(i,2,n+1){
		f(j,1,k+1){
			if(j<i){
				dp[i][j]=Pow[j][i];
			}
			else{
				f(p,0,i+1){
					Add(dp[i][j],1ll*dp[i-p][j-(i-1)]*C[p][i]%mod*Pow[i-1][p]%mod);
				}
			}
		}
	}
	cout<<dp[n][k];
}