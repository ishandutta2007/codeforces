#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
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

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<bool> used(n);
	vector<int> c(m);
	for (int i = 0; i < m; i++) cin >> c[i];
	int cur = 0;
	vector<int> f(n);
	int cnt = 1;
	vector<int> suff(m + 1);
	suff[m] = 0;
	for (int i = m - 1; i >= 0; i--) suff[i] = (suff[i + 1] + c[i]);
	for (int i = 0; i < n; i++) {
		if (f[i]) {
			cnt = 1;
			continue;
		}
		if (cnt == (d + 1) && cur == m) {
			cout << "NO\n";
			return;
		}
		if (cnt == d + 1 || (cur < m && n - i - c[cur] < suff[cur + 1])){
			for (int j = i - 1; j < (i + c[cur] - 1); j++) {
				f[j] = cur + 1;
			}
			if (c[cur] >= 2) cnt = 1;
			else cnt = 2;
			cur++;
			continue;
		}
		cnt++;
	}
	if (cnt == (d + 1) || cur != m) {
		if (cur == m - 1) f[n - 1] = m;
		else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i : f) cout << i << " ";
}