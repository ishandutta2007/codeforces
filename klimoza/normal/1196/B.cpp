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
typedef long double ld;

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
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& i : a) {
			cin >> i;
		}
		vector<int> ans;
		for (int i = 0; i < n; i++){
			if (size(ans) == k - 1) break;
			if (a[i] % 2 == 1) ans.push_back(i + 1);
		}
		if (size(ans) < k - 1) cout << "NO\n";
		else {
			ll ss = 0;
			int ind = 0;
			if (!ans.empty()) ind = ans.back();
			//cout << ind << endl;
			for (int i = ind; i < n; i++) {
				ss += a[i];
			}
			if (ss % 2 == 0) cout << "NO\n";
			else {
				ans.push_back(n);
				cout << "YES\n";
				for (int i : ans) cout << i << " ";
				cout << endl;
			}
		}
	}
}