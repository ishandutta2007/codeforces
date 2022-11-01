#include<bits/stdc++.h>
using namespace std;

int N , M , num[503] , V[503] , C[503][503] , P , dp[503][503] , ans[503][503];

signed main(){
	cin >> N >> M >> P; num[0] = 1;
	for(int i = 0 ; i <= M ; ++i){C[i][0] = 1; for(int j = 1 ; j <= i ; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;}
	
	for(int i = 1 ; i <= M ; ++i)
		for(int j = 1 ; j <= i ; ++j){
			num[i] = (num[i] + 1ll * num[j - 1] * num[i - j] % P * (i + 1) % P * C[i - 1][j - 1]) % P;
			int sum = 0; for(int k= 1 ; k <= i ; ++k) sum += abs(j - k);
			V[i] = (V[i] + 1ll * V[j - 1] * num[i - j] % P * (i + 1) % P * C[i - 1][j - 1] +
					1ll * V[i - j] * num[j - 1] % P * (i + 1) % P * C[i - 1][j - 1] +
					1ll * num[i - j] * num[j - 1] % P * sum % P * C[i - 1][j - 1]) % P;
		}

	dp[0][0] = 1;
	for(int i = 0 ; i <= N ; ++i)
		for(int j = 0 ; j <= i ; ++j)
			for(int k = 0 ; k + i + 1 <= N + 1 && k + j <= M ; ++k){
				dp[i + k + 1][j + k] = (dp[i + k + 1][j + k] + 1ll * dp[i][j] * C[M - j][k] % P * num[k]) % P;
				ans[i + k + 1][j + k] = (ans[i + k + 1][j + k] + 1ll * ans[i][j] * C[M - j][k] % P * num[k] + 1ll * dp[i][j] * C[M - j][k] % P * V[k]) % P;
			}
	cout << ans[N + 1][M]; return 0;
}