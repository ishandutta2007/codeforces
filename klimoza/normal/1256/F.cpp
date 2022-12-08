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
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		string s, t; cin >> s >> t;
		vector<int> a(26);
		vector<int> b(26);
		for (char c : s) a[c - 'a']++;
		for (char c : t) b[c - 'a']++;
		bool fl = true;
		bool bl = false;
		for (int i = 0; i < 26; i++) {
			if (a[i] != b[i]) {
				cout << "NO\n";
				fl = false;
				break;
			}
			if (a[i] >= 2) bl = true;
		}
		if (!fl) continue;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) cnt++;
		}
		if (bl) cout << "YES\n";
		else {
			string h = s;
			sort(all(h));
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					if (s[j] == h[i]) {
						for (int k = j - 1; k >= i; k--) {
							swap(s[k], s[k + 1]);
							swap(t[n - 2], t[n - 1]);
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					if (t[j] == h[i]) {
						for (int k = j - 1; k >= i; k--) {
							swap(t[k], t[k + 1]);
							swap(s[n - 2], s[n - 1]);
						}
					}
				}
			}
			if (t == s) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}