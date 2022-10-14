#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 304, mod = 1e9 + 7, i2 = (mod+1)/2;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll z, zo, oz, o;
	cin >> z >> zo >> oz >> o;
	if(z == 0 && o == 0 && zo == 0 && oz == 0) return cout << "1\n", 0;
	ll c0 = -1, c1 = -1;
	for(ll i = 1; i < 1<<17; i++) {
		if(i*(i-1)/2 == z) c0 = i;
		if(i*(i-1)/2 == o) c1 = i;
	}
	if(z == 0 && zo == 0 && oz == 0 && c1 != -1) return cout << string(c1, '1'), 0;
	if(o == 0 && zo == 0 && oz == 0 && c0 != -1) return cout << string(c0, '0'), 0;
	if(c0 == -1 || c1 == -1 || zo+oz != c0*c1) return cout << "Impossible", 0;
	string ans = "";
	while(true) {
		while(oz >= c0 && c1){
			 oz -= c0;
			 ans += '1';
			 c1--;
		}
		if(c0) {
			ans += '0';
			c0--;
		} else break;
	}
	if(oz) return cout << "Impossible", 0;
	cout << ans;
	return 0;
}