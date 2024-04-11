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

const int N=205,M=17;

int n,ans,mod,a[N],C[N][N],dp[N][N*M],pd[N][N*M];


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>mod;
	f(i,0,N){
		C[0][i]=1;
		f(j,1,i+1){
			C[j][i]=(C[j-1][i-1]+C[j][i-1])%mod;
		}
	}
	int last=0,l=max(2,n-M);
	f(i,1,n){
		dp[i][0]=C[i][n];
	}
	f_(ep,n,l){
		f_(i,n-1,1){
			f_(j,N,0){
				int x=0;
				if(j-i>=0) x=dp[i][j-i];
				dp[i][j]=x;
			}
		}
		//cout<<dp[1][1]<<endl;
		f_(i,n-1,1){
			f(j,0,N){
				for(int k=1;k+i<=n;k++){
					if(n-i<ep || (n-i==ep && i+k==n)){
						Add(dp[i+k][j],1ll*dp[i][j]*C[k][n-i]%mod);
						if(i+k==n && j<=ep){
							Add(ans,1ll*dp[i][j]*C[k][n-i]%mod);
						}
					}
				}
			}
		}

	}
	cout<<(ans+2)%mod;
}

// 1000000007