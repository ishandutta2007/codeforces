#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define BS bitset < 128 >
unordered_map < BS , int > id; int N , cnt , P[7][7] , dp[2][70003] , trans[70003][128] , prob[128] , iv100;

int poww(long long a , int b){int times = 1; while(b){if(b & 1) times = times * a % MOD; a = a * a % MOD; b >>= 1;} return times;}

int dfs(BS &x){
	if(id.find(x) != id.end()) return id[x];
	int nd = id[x] = ++cnt; BS tmp[7] , tp;
	for(int i = 0 ; i < N ; ++i) for(int j = 0 ; j < 1 << N ; ++j) tmp[i][j | (1 << i)] = tmp[i][j | (1 << i)] | x[j];
	for(int i = 0 ; i < 1 << N ; ++i){
		tp = x; for(int j = 0 ; j < N ; ++j) if(i >> j & 1) tp |= tmp[j];
		trans[nd][i] = dfs(tp); 
	}
	return nd;
}

int main(){
	cin >> N; BS tmp; tmp.set(0); dfs(tmp); iv100 = poww(100 , MOD - 2); cerr << id.size() << endl;
	for(int i = 0 ; i < N ; ++i) for(int j = 0 ; j < N ; ++j) cin >> P[i][j];
	dp[0][1] = 1; int x = 0;

	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < 1 << N ; ++j){
			prob[j] = 1;
			for(int k = 0 ; k < N ; ++k)
				prob[j] = 1ll * prob[j] * iv100 % MOD * (j >> k & 1 ? P[i][k] : 100 - P[i][k]) % MOD;
		}
		
		memset(dp[x ^= 1] , 0 , sizeof(dp[x]));
		for(int j = 1 ; j <= cnt ; ++j)
			if(dp[x ^ 1][j])
				for(int k = 0 ; k < 1 << N ; ++k)
					dp[x][trans[j][k]] = (dp[x][trans[j][k]] + 1ll * dp[x ^ 1][j] * prob[k]) % MOD;
	}
	for(int i = 0 ; i < 1 << N ; ++i) tmp.set(i);
	cout << dp[x][id[tmp]] << endl; return 0;
}