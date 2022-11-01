#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int mat[103][103] , s[103] , t[103] , val[103] , sum[103] , N;
int upd(int x){return x + (x >> 31 & MOD);}

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

int solve(int val){
	memset(mat , 0 , sizeof(mat));
	for(int i = 1 ; i < N ; ++i){mat[s[i]][t[i]] = mat[t[i]][s[i]] = MOD - val; mat[s[i]][s[i]] += val; mat[t[i]][t[i]] += val;}
	for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j) if(!mat[i][j]){mat[i][j] = mat[j][i] = MOD - 1; ++mat[i][i]; ++mat[j][j];}
	int ans = 1; bool flg = 0;
	for(int i = 2 ; i <= N ; ++i){
		bool swp = 0; int inv = 0;
		for(int j = i ; j <= N ; ++j)
			if(mat[j][i])
				if(!swp){flg ^= i != j; swap(mat[i] , mat[j]); swp = 1; inv = poww(mat[i][i] , MOD - 2) % MOD;}
				else for(int k = N ; k >= i ; --k) mat[j][k] = (mat[j][k] - 1ll * mat[i][k] * inv % MOD * mat[j][i] % MOD + MOD) % MOD;
		ans = 1ll * ans * mat[i][i] % MOD;
	}
	return flg ? upd(-ans) : ans;
}

int main(){
	cin >> N; for(int i = 1 ; i < N ; ++i) cin >> s[i] >> t[i];
	for(int i = 1 ; i <= N ; ++i){
		static int poly[103] , cnt , coef; coef = solve(i); cnt = 0;
		memset(poly , 0 , sizeof(poly)); poly[0] = 1;
		for(int j = 1 ; j <= N ; ++j)
			if(i != j){
				coef = 1ll * poww(upd(i - j) , MOD - 2) * coef % MOD;
				for(int k = cnt++ ; ~k ; --k){poly[k + 1] = upd(poly[k + 1] + poly[k] - MOD); poly[k] = 1ll * poly[k] * (MOD - j) % MOD;}
			}
		for(int i = 0 ; i <= cnt ; ++i) sum[i] = (sum[i] + 1ll * coef * poly[i]) % MOD;
	}
	for(int i = 0 ; i < N ; ++i) cout << sum[i] << ' ';
	return 0;
}