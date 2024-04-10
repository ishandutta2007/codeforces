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
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.size();
		vector<int> id(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				id[i] = i;
			}
			else {
				if (i == 0) id[i] = -1;
				else id[i] = id[i - 1];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cur = 0;
			for (int j = i; j > max(-1, i - 30); j--) {
				cur += (s[j] - '0') * (1 << (i - j));
				if (s[j] == '0') continue;
				int cl = (i - j + 1);
				if (cl > cur) continue;
				if (cl == cur) {
					ans++;
					continue;
				}
				int h = 0;
				if (j) h = max(0, id[j - 1] + 1);
				if (cur - cl <= j - h) {
				//	cout << i << " " << j << endl;
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}