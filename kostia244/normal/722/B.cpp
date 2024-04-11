#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
string V = "aeiouy";

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;cin >> n;
	vector<int> f(n);for(auto &i : f) cin >> i;
	string tmp;getline(cin, tmp);
	for(int i = 0; i < n; i++) {
		getline(cin, tmp);
		for(auto c : V) f[i] -= count(all(tmp), c);
		if(f[i]) return cout << "NO\n", 0;
	}
	cout << "YES\n";
}