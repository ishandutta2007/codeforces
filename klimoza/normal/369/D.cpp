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

const int N = 3e3 + 8;

int id(int x, int y) {
	return x * N + y;	
}

pair<int, int> rv(int k) {
	return { k / N, k % N };
}

pair<bool, bool> foo(int x) {
	pair<bool, bool> ans;
	if (x) ans.first = true;
	if (x == 100) ans.second = true;
	return ans;
}

const int M = N * N;

int n;

int d[M];
int p[N];
pair<int, int> suff[N];

void bfs(int s) {
	fill(d, d + M, 2e9);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		pair<int, int> kek = rv(v);
		int i = kek.first;
		int j = kek.second;
		if (i >= n || j >= n) continue;
		if (p[i] && !suff[j].second) {
			int u = id(i, j + 1);
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
		if (p[i] != 100 && suff[j].first){
			int u = id(j, j + 1);
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
		if (p[i] && suff[j].first) {
			int u = id(j + 1, j + 2);
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
}

void solve() {
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	suff[n - 1] = foo(p[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		suff[i].first = suff[i + 1].first || foo(p[i]).first;
		suff[i].second = suff[i + 1].second || foo(p[i]).second;
	}
	bfs(id(0, 1));
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (d[i] <= k) {
			ans++;
			pair<int, int> x = rv(i);
			//cout << x.first << " " << x.second << endl;
		}
	}
	cout << ans << endl;
	return;
}