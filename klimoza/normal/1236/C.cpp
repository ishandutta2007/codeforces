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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

void solve() {
	int n; cin >> n;
	if (n % 2 == 0) {
		int l = 1, r = n * n;
		int t1 = n / 2;
		int t2 = (n + 1) / 2;
		for (int i = 0; i < n; i++) {
			for (int j = l; j < l + t1; j++) cout << j << " ";
			l += t1;
			for (int j = r; j > r - t2; j--) cout << j << " ";
			r -= t2;
			cout << endl;
		}
	}
	else {
		vector<int> ans(n * n);
		for (int i = 0; i < (n * n); i += n) {
			if (i % 2 == 0) {
				for (int j = i; j < (i + n); j++) {
					ans[j] = n - (j - i);
				}
			}
			else {
				for (int j = i; j < (i + n); j++) {
					ans[j] = (j - i + 1);
				}
			}
		}
		vector<vector<int>> an(n);
		for (int i = 0; i < n * n; i++) {
			an[ans[i] - 1].push_back(i + 1);
		}
		for (auto u : an) {
			for (int i : u) cout << i << " ";
			cout << endl;
		}
	}
}