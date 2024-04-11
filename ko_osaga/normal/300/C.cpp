#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

lint fact[1000005], invf[1000005];

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret;
}

int a, b, n;
vector<int> l;

void bktk(int k){
	if(b * n < k) return;
	if(a * n <= k) l.push_back(k);
	bktk(k * 10 + a);
	bktk(k * 10 + b);
}

lint bino(int x, int y){
	return fact[x] * (invf[x-y] * invf[y] % mod) % mod;
}

int main(){
	cin >> a >> b >> n;
	fact[0] = invf[0] = 1;
	for(int i=1; i<=n; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	bktk(0);
	lint ret = 0;
	for(auto &i : l){
		for(int j=0; j<=n; j++){
			if(a * j + b * (n-j) == i){
				ret += bino(n, j);
				ret %= mod;
			}
		}
	}
	cout << ret;
}