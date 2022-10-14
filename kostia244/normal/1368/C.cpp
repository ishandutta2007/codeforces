#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, mod = 1e9 + 7, i2 = (mod+1)/2;
vector<pair<int, int>> pos;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	pos.pb({0, 0});
	for(int i = 0; i <= n; i++) {
		pos.pb({i+1, i});
		pos.pb({i, i+1});
		pos.pb({i+1, i+1});
	}
	cout << pos.size() << '\n';
	for(auto i : pos) cout << i.first << " " << i.second << '\n';
	return 0;
}