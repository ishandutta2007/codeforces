#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, mod = 1e9 + 7, i2 = (mod+1)/2;
ll n, a[11];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	while(true) {
		ll cnt = 1, mn = 1<<30;
		for(int i = 0; i < 10; i++) cnt *= a[i], mn = min(mn, a[i]);
		if(cnt >= n) break;
		for(int i = 0; i < 10; i++) {
			if(a[i] == mn) {a[i]++;break;}
		}
	}
	string s = "codeforces";
	for(int i = 0; i < 10; i++) while(a[i]--) cout << s[i];cout << '\n';
	return 0;
}