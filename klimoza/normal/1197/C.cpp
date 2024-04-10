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

#define all(v) (v).begin(), (v).end()
#define size(v) (v).size()

using namespace std;
typedef long long ll;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

void solve();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);

	solve();
	return 0;
}





void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<int> nw;
	ll ans = a[n - 1] - a[0];
	for (int i = 0; i < n - 1; i++) {
		nw.push_back(+a[i] - a[i + 1]);
	}
	sort(all(nw));
	for (int i = 0; i < k - 1; i++) ans += nw[i];
	cout << ans << endl;
}