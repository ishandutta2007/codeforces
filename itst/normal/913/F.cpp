#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int N , A , B , p[2003][2003] , f[2003] , g[2003] , q[2003];

int poww(long long a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = tms * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return tms;
}

int main(){
	cin >> N >> A >> B; A = 1ll * A * poww(B , MOD - 2) % MOD; p[0][0] = 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 0 ; j < i ; ++j){
			p[i][j] = (p[i][j] + 1ll * p[i - 1][j] * poww(MOD + 1 - A , j)) % MOD;
			p[i][j + 1] = (p[i][j + 1] + 1ll * p[i - 1][j] * poww(A , i - 1 - j)) % MOD;
		}
	g[1] = 1;
	for(int i = 2 ; i <= N ; ++i){
		g[i] = 1; for(int j = 1 ; j < i ; ++j) g[i] = (g[i] - 1ll * p[i][j] * g[j] % MOD + MOD) % MOD;
	}
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j < i ; ++j)
			f[i] = (f[i] + 1ll * g[j] * p[i][j] % MOD * (f[j] + q[i - j])) % MOD;
		f[i] = (f[i] + i * (i - 1ll) / 2) * poww(MOD + 1 - g[i] , MOD - 2) % MOD;
		for(int j = 1 ; j <= i ; ++j) q[i] = (q[i] + 1ll * g[j] * p[i][j] % MOD * (f[j] + q[i - j])) % MOD;
	}
	cout << f[N]; return 0;
}