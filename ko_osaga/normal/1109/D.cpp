#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

lint fact[MAXN], invf[MAXN];

lint bino(int x, int y){ return fact[x] * (invf[y] * invf[x-y] % mod) % mod; }

lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

int f(int x, int y){
	return 1ll * ipow(x + y, x + mod - 2) * y % mod;
}

int main(){
	fact[0] = invf[0] = 1;
	for(int i=1; i<MAXN; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	int n, m;
	cin >> n >> m;
	lint ret = 0;
	for(int d=1; d<n&&d<=m; d++){
		lint pos = bino(m-1, d-1) * ipow(m, n - 1 - d) % mod;
		pos *= bino(n - 2, d - 1) * fact[d - 1] % mod;
		pos %= mod;
		pos *= f(n - d - 1, d + 1);
		pos %= mod;
		ret += pos;
	}
	ret %= mod;
	cout << ret << endl;
}