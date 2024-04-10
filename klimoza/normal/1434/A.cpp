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

mt19937 mrand(random_device{}());
//mt19937 mrand(228);

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

ll a[6];

const int N = 1e5 + 2;

int p[N][6];

void solve() {
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	int n; cin >> n;
	vector<ll> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<pair<ll, int>> kek;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			p[i][j] = b[i] - a[j];
			kek.push_back(mp(p[i][j], i));
		}
	}
	sort(all(kek));
	vector<int> cnt(n, 0);
	int m = kek.size();
	int s = 1;
	int l = 0, r = 0;
	cnt[kek[0].second] = 1;
	ll ans = inf;
	for (; l < m; l++) {
		while ((r + 1) < m && (s < n)) {
			r++;
			cnt[kek[r].second]++;
			if (cnt[kek[r].second] == 1)
				s++;
		}
		if (s < n)
			break;
		//cout << l << " " << r << " " << kek[l].first << " " << kek[r].first << " " << s << endl;
		//for (int i : cnt) cout << i << endl;
		ans = min(ans, kek[r].first - kek[l].first);
		cnt[kek[l].second]--;
		if (cnt[kek[l].second] == 0)
			s--;
	}
	cout << ans << endl;
	return;
}