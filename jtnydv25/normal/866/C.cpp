#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

const int N = 55;
ld dp[N][N * 2 * N];
ld P[N];
int p[N], F[N], S[N];
const ld INF = 1e9;
int main(){
	int n, R;
	cin >> n >> R;
	long long smS = 0, smF = 0;
	for(int i = 1; i <= n; i++){
		cin >> F[i] >> S[i] >> p[i];
		P[i] = p[i] / 100.0;
		smF += F[i];
		smS += S[i];
	}

	ld x = smF;
	ll k = smF;
	int iter = 0;
	double rem = 1.5;
	ld mn =smF, mx = 1e10;
	ld eps = mn * (1e-9);
	while(abs(mn - mx) > eps){
		ld x = (mn + mx) / 2.;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N * N * 2; j++)
				dp[i][j] = x;
		for(int i = 0; i <= R; i++) dp[n + 1][i] = 0.;	
		for(int i = n; i >= 1; i--){
			for(int r = 0; r <= R; r++){
				if(i == 1 && r == 0){
					dp[i][r] = (dp[i + 1][r + F[i]] + F[i]) * P[i] + (dp[i + 1][r + S[i]] + S[i]) * (1. - P[i]);
				}
				else{
					dp[i][r] = min(x, (dp[i + 1][r + F[i]] + F[i]) * P[i] + (dp[i + 1][r + S[i]] + S[i]) * (1. - P[i]));
				}
			}
		}
		if(dp[1][0] > x){
			mn = x;
		}
		else mx = x;
	}
	cout << setprecision(10) << fixed << (mn + mx)/2.;
}