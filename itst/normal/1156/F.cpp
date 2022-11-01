#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
int dp[5003][5003] , inv[5003] , sum[5003] , N;
map < int , int > cnt;

int main(){
	cin >> N; for(int i = 1 , x ; i <= N ; ++i){cin >> x; ++cnt[x];}
	inv[1] = 1; for(int i = 2 ; i <= N ; ++i) inv[i] = M - 1ll * (M / i) * inv[M % i] % M;
	int num = 0 , ans = 0;
	for(auto t : cnt){
		++num; dp[1][num] = 1ll * t.second * inv[N] % M;
		for(int i = 2 ; i <= num ; ++i) dp[i][num] = 1ll * sum[i - 1] * inv[N - i + 1] % M * t.second % M;
		for(int i = 1 ; i <= num ; ++i){
			sum[i] = (sum[i] + dp[i][num]) % M;
			ans = (ans + 1ll * dp[i][num] * inv[N - i] % M * (t.second - 1)) % M;
		}
	}
	cout << ans; return 0;
}