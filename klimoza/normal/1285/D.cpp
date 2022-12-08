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
const ll mod1 = 1e9 + 7;
const ll mod2 = 777777773;
//const ll mod2 = 998244353;

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

pair<ll, ll> ans = { inf, -1 };

const int N = 1e5 + 7;

ll a[N];

void rec(int l, int r, int bit = 29, ll tmp = 0) {
	//cout << l << " " << r << " " << tmp << " " << bit << endl;
	if (bit == -1) {
		ans = min(ans, { a[l] ^ tmp, tmp });
		return;
	}
	sort(a + l, a + r + 1, [&](int x, int y) {
		return (x & (1 << bit)) < (y & (1 << bit));
	});
	if ((a[l] & (1LL << bit)) == (a[r] & (1LL << bit))) {
		if ((a[l] & (1LL << bit)) == 0)
			rec(l, r, bit - 1, tmp);
		else
			rec(l, r, bit - 1, tmp ^ (1LL << bit));
	}
	else {
		int f1 = l;
		int f2 = l;
		while ((a[f2] & (1LL << bit)) == 0)
			f2++;
		f2--;
		l = f2 + 1;
		//if (bit == 1) cout << l << " " << r << " "<< f1 << " "<< f2 << " kek" << endl;
		rec(f1, f2, bit - 1, tmp ^ (1LL << bit));
		rec(l, r, bit - 1, tmp);
	}
	return;
}

void solve() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	rec(0, n - 1);
	cout << ans.first << endl;
	return;
}