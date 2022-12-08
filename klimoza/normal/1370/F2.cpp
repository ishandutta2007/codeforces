/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 1e3 + 1;

vector<int> g[N];
int d[N];

int n;

void bfs(int s) {
	fill(d, d + n, 2e9);
	d[s] = 0;
	queue<int> qu;
	qu.push(s);
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		for (int u : g[v]) {
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				qu.push(u);
			}
		}
	}
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			g[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int s;
		cout << "? " << n << " ";
		for (int i = 1; i <= n; i++)
			cout << i << " ";
		cout << endl;
		cin >> s;
		assert(s != -1);
		s--;
		int dist; cin >> dist;
		int l = dist / 2 - 1, r = dist + 1;
		bfs(s);
		int a = -1;
		while (true) {
			int m = l + r >> 1;
			vector<int> cur;
			for (int j = 0; j < n; j++)
				if (d[j] == m)
					cur.push_back(j);
			if (cur.empty()) {
				r = m;
				continue;
			}
			cout << "? " << cur.size() << " ";
			for (int j : cur)
				cout << j + 1 << " ";
			cout << endl;
			int x, y;
			cin >> x >> y;
			assert(x != -1);
			x--;
			if (y == dist) {
				a = x;
				l = m;
			}
			else {
				r = m;
			}
			if (r - l <= 1)
				break;
		}
		assert(a != -1);
		bfs(a);
		vector<int> cur;
		for (int i = 0; i < n; i++) {
			if (d[i] == dist)
				cur.push_back(i);
		}
		//assert(!cur.empty());
		cout << "? " << cur.size() << " ";
		for (int j : cur)
			cout << j + 1 << " ";
		cout << endl;
		int b; cin >> b;
		assert(b != -1);
		b--;
		cin >> dist;
		cout << "! " << a + 1 << " " << b + 1 << endl;
		string mem; cin >> mem;
		//cout << mem << endl;
		assert(mem == "Correct");
	}
	return;
}