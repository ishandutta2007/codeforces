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

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

const int N = 2e5 + 7;

vector<int> g[N];
int x[N], y[N];
int w[N];

int sz[N];
bool used[N];

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--; y[i]--;
		sz[x[i]]++;
		sz[y[i]]++;
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
	}
	queue<int> qu;
	for (int i = 0; i < n; i++) {
		if (sz[i] <= w[i])
			qu.push(i);
	}
	vector<int> ans;
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		for (int i : g[v]) {
			if (used[i])
				continue;
			ans.push_back(i);
			used[i] = true;
			if (x[i] == v) {
				sz[y[i]]--;
				if (sz[y[i]] == w[y[i]])
					qu.push(y[i]);
			}
			else {
				sz[x[i]]--;
				if (sz[x[i]] == w[x[i]])
					qu.push(x[i]);
			}
		}
	}
	if (ans.size() < m)
		cout << "DEAD\n";
	else {
		cout << "ALIVE\n";
		reverse(all(ans));
		for (int i : ans)
			cout << i + 1 << " ";
		cout << endl;
	}
	return;
}