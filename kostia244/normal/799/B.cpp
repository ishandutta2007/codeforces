#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, p[maxn], a[maxn], b[maxn];
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	set<pair<int, int>> c[3];
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		a[i]--, b[i]--;
		c[a[i]].insert({p[i], i});
		c[b[i]].insert({p[i], i});
	}
	cin >> m;
	for(int t, i = 0; i < m; i++) {
		cin >> t, t--;
		int ans = INT_MAX;
		if(!c[t].empty()) {
			pair<int, int> x = *c[t].begin();
			ans = x.first;
			c[a[x.second]].erase(x);
			c[b[x.second]].erase(x);
		}
		if(ans == INT_MAX) ans = -1;
		cout << ans << " ";
	}
}