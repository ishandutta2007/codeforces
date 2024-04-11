#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1e5 + 55, mod = 998244353;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(0);
	ll t, a, b, x, y;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int t = count(all(s), '0');
		if(t == 0) {
			cout << string(s.size(), '1') << '\n';
			continue;
		}
		if(t == s.size()) {
			cout << string(s.size(), '0') << '\n';
			continue;
		}
		string a = "";
		for(int i = 0; i < s.size(); i++) {
			if(a.size() && a.back() == s[i]) a.push_back(s[i]^'0'^'1');
			a += s[i];
		}
		cout << a << '\n';
	}
}