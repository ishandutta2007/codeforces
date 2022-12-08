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

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(2 * n);
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
			if (a[i] == 1) cnt1++;
			else cnt2++;
		}
		int bal = cnt2 - cnt1;
		map<int, int> f;
		int cur = 0;
		f[0] = 0;
		int ans = inf0;
		if (!bal) ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == 1) cur--;
			else cur++;
			if (bal == cur) ans = min(ans, n - i);
			if (f.find(cur) == f.end()) f[cur] = n - i;
		}
		cur = 0;
		for (int i = n; i < 2 * n; i++) {
			if (a[i] == 1) cur--;
			else cur++;
			int t = bal - cur;
			//cout << t << " " << i << endl;
			if (f.find(t) != f.end())
				ans = min(ans, (i - n + 1) + f[t]);
		}
		cout << ans << endl;
	}
	return;
}