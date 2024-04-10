#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll mod;
ll dp[501];
ll w[501];
ll C[501][501];
ll dp2[502][502];
ll w2[502][502];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> mod;
	C[0][0]=1;
	for(int i=1; i<=n ;i++){
		C[i][0]=1;
		for(int j=1; j<=n ;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	w[0]=1;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=i ;j++){
			ll cur=C[i-1][j-1]*w[j-1]%mod*w[i-j]%mod;
			w[i]=(w[i]+cur*(i+1))%mod;
			//cout << cur << ' ' << ((i-j)*(i-j+1)/2+(j)*(j-1)/2) << endl;
			dp[i]=(dp[i]+C[i-1][j-1]*(dp[j-1]*w[i-j]%mod+w[j-1]*dp[i-j]%mod)%mod*(i+1)+cur*((i-j)*(i-j+1)/2+(j)*(j-1)/2))%mod;
			//cout << i <<' ' << j << ' ' << C[i-1][j-1]*(dp[j-1]*w[i-j]%mod+w[j-1]*dp[i-j]%mod)%mod*(i+1)+cur*((i-j)*(i-j+1)/2+(j)*(j-1)/2)  << endl;
		}
	}
	w2[0][0]=1;
	for(int i=1; i<=n+1 ;i++){
		for(int k=0; k<=m ;k++){
			for(int j=1; j<=min(i-1,k) ;j++){
				int pi=i-j-1;
				int pk=k-j;
				//cout << i << ' ' << k << ' ' << pi << ' ' << pk << endl;
				ll cw=C[k][j];
				w2[i][k]=(w2[i][k]+cw*w2[pi][pk]%mod*w[j]%mod)%mod;
				dp2[i][k]=(dp2[i][k]+cw*w2[pi][pk]%mod*dp[j]+cw*dp2[pi][pk]%mod*w[j])%mod;
			}
		}
		for(int j=0; j<=m ;j++){
			dp2[i][j]=(dp2[i][j]+dp2[i-1][j])%mod;
			w2[i][j]=(w2[i][j]+w2[i-1][j])%mod;
		}
	}
	cout<< dp2[n+1][m] << '\n';
}