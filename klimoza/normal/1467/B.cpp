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

#define int long long

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

int n;

int check(vector<int>& b, int i) {
	if ((i - 1) < 0 || (i - 1) >= n || i < 0 || i >= n)
		return 0;
	if (b[i - 1] < 0 && b[i] > 0)
		return 1;
	if (b[i - 1] > 0 && b[i] < 0)
		return 1;
	return 0;
}

int checkr(vector<int>& b, int i, ll x) {
	if ((i + 1) < 0 || (i + 1) >= n)
		return 0;
	if (b[i + 1] < 0 && x > 0)
		return 1;
	if (b[i + 1] > 0 && x < 0)
		return 1;
	return 0;
}

int checkl(vector<int>& b, int i, ll x) {
	if ((i - 1) < 0 || (i - 1) >= n)
		return 0;
	if (b[i - 1] < 0 && x > 0)
		return 1;
	if (b[i - 1] > 0 && x < 0)
		return 1;
	return 0;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> b;
		for (int i = 1; i < n; i++)
			b.push_back(a[i] - a[i - 1]);
		n = b.size();
		int ans = 0;
		int s = 0;
		for (int i = 1; i < n; i++) {
			if (b[i] > 0 && b[i - 1] < 0)
				s++;
			else if (b[i] < 0 && b[i - 1] > 0)
				s++;
		}
		ans = s;
		for (int i = 1; i < n; i++) {
			//cout << i << " " << b[i - 1] << " " << b[i] << endl;
			int cur = s;
			cur -= check(b, i + 1);
			cur -= check(b, i);
			cur -= check(b, i - 1);
			int x = b[i] + b[i - 1];
			ans = min(ans, cur + checkr(b, i, x));
			x = b[i - 1] + b[i];
			ans = min(ans, cur + checkl(b, i - 1, x));
		}
		if (check(b, 1))
			ans = min(ans, s - 1);
		if (check(b, n - 1))
			ans = min(ans, s - 1);
		cout << ans << endl;
	}
	return;
}