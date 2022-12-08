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
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

const int N = 1e5 + 6;

vector<int> g[N];

deque<int> ans;

int d[N];
bool used[N];

deque<int> cur = { 0 };

bool dfs(int v, int last = -1) {
	used[v] = true;
	if (last == -1) d[v] = 0;
	else d[v] = d[last] + 1;
	bool fl = false;
	for (int u : g[v]) {
		if (u != last && used[u])
			fl = true;
	}
	if (fl) {
		int kek = -1;
		//cout << v + 1 << " " << u + 1 <<  " " << last + 1 << endl;
		for (int j : g[v])
			if (used[j] && j != last && (kek == -1 || d[j] > d[kek]))
				kek = j;
		while (cur.front() != kek)
			cur.pop_front();
		ans = cur;
		return true;
	}
	for (int u : g[v]) {
		//cout << v + 1 << " " << u + 1 <<  " " << last + 1 << endl;
		if (u == last)
			continue;
		cur.push_back(u);
		if (dfs(u, v))
			return true;
		cur.pop_back();
	}
	return false;
}

void solve() {
	fill(used, used + N, false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (dfs(0)) {
		/*for (int i : ans)
			cout << i << " ";
		cout << endl;*/
		if (ans.size() <= k) {
			cout << 2 << endl;
			cout << ans.size() << endl;
			for (int i : ans)
				cout << i + 1 << " ";
		}
		else {
			vector<int> mem;
			for (int i = 0; i < ans.size(); i += 2) {
				if (mem.size() == (k + 1) / 2) break;
				mem.push_back(ans[i]);
			}
			cout << 1 << endl;
			for (int i : mem)
				cout << i + 1 << " ";
		}
	}
	else {
		vector<int> a, b;
		for (int i = 0; i < n; i++) {
			if (d[i] & 1) a.push_back(i);
			else b.push_back(i);
		}
		if (a.size() < b.size())
			swap(a, b);
		cout << 1 << endl;
		for (int i = 0; i < (k + 1) / 2; i++)
			cout << a[i] + 1 << " ";
	}
	return;
}