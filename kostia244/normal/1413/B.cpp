#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, mod = 998244353, inv2 = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> x(n, vector<int>(m)), y(m, vector<int>(n));
		vector<int> pos(n*m+1);
		for(auto &i : x) {
			for(auto &j : i) cin >> j;
		}
		for(auto &i : y) {
			int p = 0;
			for(auto &j : i) cin >> j, pos[j] = p++;
		}
		sort(all(x), [&](auto &i, auto &j) {
			return pos[i[0]] < pos[j[0]];
		});
		for(auto &i : x) {
			for(auto &j : i) cout << j << " ";
			cout << '\n';
		}
	}
}