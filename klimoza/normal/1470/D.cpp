//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;

}

const int N = 3e5 + 2;
vector<int> g[N];
int d[N];
bool used[N];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	d[s] = 0;
	used[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v]) {
			if (used[u])
				continue;
			d[u] = d[v] + 1;
			used[u] = true;
			q.push(u);
		}
	}
}
	
void solve() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			g[i].clear();
			d[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		fill(used, used + n, false);
		bfs(0);
		bool fl = true;
		for (int i = 0; i < n; i++) {
			if (d[i] == -1) {
				fl = false;
				break;
			}
		}
		if (!fl) {
			cout << "NO\n";
			continue;
		}
		vector<vector<int>> kek(n);
		for (int i = 0; i < n; i++)
			kek[d[i]].push_back(i);
		vector<bool> markd(n, false);
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			for (int v : kek[i]) {
				if (markd[v]) continue;
				ans.push_back(v);
				for (int u : g[v])
					markd[u] = true;
			}
		}
		cout << "YES\n";
		cout << ans.size() << endl;
		for (int i : ans)
			cout << i + 1 << " ";
		cout << endl;
	}
	return;
}