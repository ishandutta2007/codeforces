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

const int L = 20;
const int K = 1 << L;

bool bad[K];

void solve() {
	fill(bad, bad + K, false);
	int n, m, d;
	cin >> n >> m >> d;
	vector<vector<int>> a(m, vector<int>());
	vector<int> t(n);
	for (int i = 0; i < m; i++) {
		int s; cin >> s;
		a[i].resize(s);
		for (int& j : a[i]) {
			cin >> j;
			j--;
			t[j] = i;
		}
	}
	int mask = 0;
	vector<int> cnt(m);
	for (int i = 0; i < d; i++) {
		mask |= (1 << t[i]);
		cnt[t[i]]++;
	}
	int all = (1 << m) - 1;
	bad[all ^ mask] = true;
	for (int i = d; i < n; i++) {
		cnt[t[i - d]]--;
		if (!cnt[t[i - d]]) mask ^= (1 << (t[i - d]));
		if (!cnt[t[i]]) mask ^= (1 << (t[i]));
		cnt[t[i]]++;
		bad[all ^ mask] = true;
	}
	int ans = 2e9;
	for (int i = (1 << m) - 1; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			bad[i] |= bad[i | (1 << j)];
			if (i & (1 << j))
				cnt++;
		}
		//cout << i << " " << bad[i] << " " << cnt <<  endl;
		if (!bad[i])
			ans = min(ans, cnt);
	}
	cout << ans << endl;
	return;
}