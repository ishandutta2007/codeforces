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
	int a, b, k1, k2, n;
	cin >> a >> b >> k1 >> k2 >> n;
	int cnt = (k1 - 1) * a + (k2 - 1) * b;
	if (cnt >= n) cout << 0 << " ";
	else cout << n - cnt << " ";
	if (k1 > k2) {
		swap(a, b);
		swap(k1, k2);
	}
	cnt = 0;
	while (a > 0&& n >= k1) {
		a--;
		n -= k1;
		cnt++;
	}
	while (b > 0 && n >= k2) {
		b--;
		n -= k2;
		cnt++;
	}
	cout << cnt << endl;
}