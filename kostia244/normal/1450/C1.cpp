#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		vector<vector<char>> a(n, vector<char>(n));
		for(auto &i : a) for(auto &j : i) cin >> j;
		array<int, 3> c{0, 0, 0};
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				c[(i+j)%3] += a[i][j] == 'X';
			}
		int rem = min_element(all(c))-begin(c);
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = 0; j < n; j++) {
				if(a[i][j] == 'X' && (i+j)%3 == rem) a[i][j] = 'O';
				cout << a[i][j];
			}
	}
}