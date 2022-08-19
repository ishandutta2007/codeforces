#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int mod = 1e9 + 7;

lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret % mod;
}

int n;
lint a[22], inv[22], s;

lint bino(lint x, lint y){
	if(x < y) return 0;
	if(x >= mod) return bino(x / mod, y / mod) * bino(x % mod, y % mod) % mod;
	lint ret = 1;
	for(int i=0; i<y; i++){
		ret *= (x-i) * inv[i+1] % mod;
		ret %= mod;
	}
	return ret;
}

int main(){
	cin >> n >> s;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) inv[i] = ipow(i, mod-2);
	lint ret = 0;
	for(int i=0; i<(1<<n); i++){
		lint sm = 0, bt = 1;
		for(int j=0; j<n; j++){
			if((i >> j) & 1){
				sm += a[j] + 1;
				bt *= -1;
			}
		}
		ret += (mod + bt) * bino(s - sm + n - 1, n - 1);
		ret %= mod;
	}
	cout << ret;
}