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
	int n; cin >> n;
	vector<int> a1(n), a2(n);
	for (int i = 0; i < n; i++) cin >> a1[i];
	for (int i = 0; i < n; i++) cin >> a2[i];
	vector<int> p(n + 1);
	for (int i = 0; i < n; i++) p[a1[i]] = i;
	int l = 0;
	int r = 0;
	int ans = 0;
	vector<bool> usd(n + 1);
	for (; r < n; r++) {
		usd[a2[r]] = true;
		if (a1[l] == a2[r]) {
			while (l < n && usd[a1[l]]) l++;
			continue;
		}
		if (p[a2[r]] > l) {
			ans++;
			//cout << l << " " << r << " " << a2[r] << endl;
		}
	}
	cout << ans << endl;
}