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

bool used[N];
int tp[N], a[N], d[N];

vector<int> g[N];
int n;

int rec(int v){
	if (d[v] != -1) return d[v];
	if (used[v]) return d[v] = 1;
	used[v] = true;
	if (a[v] == -1 || tp[a[v]] == 1 || g[a[v]].size() > 1)
		return d[v] = 1;
	return d[v] = rec(a[v]) + 1;
}

vector<int> ans;

void pr(int v) {
	ans.push_back(v);
	if (a[v] == -1 || tp[a[v]] || g[a[v]].size() > 1)
		return;
	pr(a[v]);
}

void solve() {
	fill(d, d + N, -1);
	for (int i = 0; i < N; i++)
		g[i] = vector<int>();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tp[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		if (a[i] != -1)
			g[a[i]].push_back(i);
	}
	int mx = -1;
	for (int i = 0; i < n; i++) {
		rec(i);
	}

	for (int i = 0; i < n; i++) {
		if (tp[i] == 1) {	
			if (mx == -1 || d[mx] < d[i])
				mx = i;
		}
	}
	pr(mx);
	reverse(all(ans));
	cout << ans.size() << endl;
	for (int i : ans)
		cout << i + 1 << " ";
	cout << endl;
	return;

}