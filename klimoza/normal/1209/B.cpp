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
	vector<int> cur(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		cur[i] = c - '0';
	}
	vector<pair<int, int>> ab(n);
	for (int i = 0; i < n; i++) {
		cin >> ab[i].first >> ab[i].second;
	}
	int ans = 0;
	for (int time = 0; time <= 125; time++) {
		int t = 0;
		for (int i = 0; i < n; i++) {
			if (time >= ab[i].second && (time % ab[i].first == ab[i].second % ab[i].first)) {
				cur[i] ^= 1;
			}
			if (cur[i]) t++;
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
}