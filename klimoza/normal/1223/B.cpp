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
	int q; cin >> q;
	while (q--) {
		string s1, s2;
		cin >> s1 >> s2;
		bool c1[26], c2[26];
		fill(c1, c1 + 26, false);
		fill(c2, c2 + 26, false);
		for (int i = 0; i < s1.size(); i++) {
			c1[s1[i] - 'a'] = true;
			c2[s2[i] - 'a'] = true;
		}
		bool fl = false;
		for (int i = 0; i < 26; i++) {
			if (c1[i] && c2[i]) {
				cout << "YES\n";
				fl = true; break;
			}
		}
		if (fl) continue;
		cout << "NO\n";
	}
}