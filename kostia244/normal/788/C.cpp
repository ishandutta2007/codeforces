#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 2040, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, k, c[maxn];
queue<int> q;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	vector<int> g(k);
	for(auto &i : g) cin >> i, i -= n;
	sort(all(g)); g.erase(unique(all(g)), g.end());
	memset(c, 0x3f, sizeof c);
	for(auto i : g) {
		q.push(i);
		c[1003 + i] = 1;
	}
	while(!q.empty()) {
		int v = q.front(); q.pop();
		if(v == 0) {
			cout << c[1003] << endl;
			exit(0);
		}
		for(auto i : g) if(v+i <= 1000 && v+i >= -1000) {
			if(c[1003+v+i] > c[1003+v]+1) {
				c[1003+v+i] = c[1003+v]+1;
				q.push(v+i);
			}
		}
	}
	cout << "-1\n";
}