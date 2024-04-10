#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 1e6 + 7 , MOD = 998244353;
int inv[_] , p[_] , N; vector < int > pot[_];

int main(){
	inv[1] = 1; for(int i = 2 ; i <= 1e6 ; ++i) inv[i] = MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD;
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int K = read() , val = 1ll * inv[N] * inv[K] % MOD;
		while(K--){int x = read(); pot[i].push_back(x); p[x] = (p[x] + val) % MOD;}
	}
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		int sum = 0; for(auto t : pot[i]) sum = (sum + p[t]) % MOD;
		ans = (ans + 1ll * sum * inv[N]) % MOD;
	}
	cout << ans;
	return 0;
}