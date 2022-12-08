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
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= -1) a[i] = -1;
		if (a[i] >= 1) a[i] = 1;
	}
	vector<int> cntPl(n), cntMn(n);
	vector<int> pref(n);
	pref[0] = a[0];
	cntPl[0] = 1;
	if (a[0] > 0) cntPl[0] += 1;
	else cntMn[0] = 1;
	for (int i = 1; i < n; i++) {
		cntPl[i] = cntPl[i - 1];
		cntMn[i] = cntMn[i - 1];
		pref[i] = pref[i - 1] * a[i];
		if (pref[i] == 1) cntPl[i]++;
		else cntMn[i]++;
	}
	ll ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		if (pref[i] == 1) {
			ans1 += cntMn[i];
			ans2 += (cntPl[i] - 1);
		}
		else {
			ans1 += cntPl[i];
			ans2 += (cntMn[i] - 1);
		}
	}
	cout << ans1 << " " << ans2 << endl;
}