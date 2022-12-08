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
const ll mod = 1e9 + 7;

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
	ll n;
	cin >> n;
	string st;
	cin >> st;
	ll ans = n * (n + 1) / 2;
	vector<ll> f;
	for (int i = 0; i < n; i++) {
		if (i == 0) f.push_back(1);
		else if (st[i] == st[i - 1]) f.back()++;
		else f.push_back(1);
	}
	ans -= n;
	for (int i = 0; i < f.size() - 1; i++) {
		ans -= (f[i] + f[i + 1] - 1);
	}
	cout << ans << endl;
}