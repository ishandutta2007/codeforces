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

set<int> f[26];

void solve() {
	string st;
	cin >> st;
	int n = st.size();
	vector<char> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = st[i];
		f[a[i] - 'a'].insert(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int pos; char c;
			cin >> pos >> c;
			pos--;
			int h = c - 'a';
			f[a[pos] - 'a'].erase(f[a[pos] - 'a'].find(pos));
			a[pos] = c;
			f[h].insert(pos);
		}
		else {
			int l, r; cin >> l >> r;
			l--; r--;
			int ans = 0;
			//cout << "NEW\n";
			for (int i = 0; i < 26; i++) {
				set<int> ::iterator it;
				it = f[i].lower_bound(l);
				if (it == f[i].end()) continue;
				//cout << "jopa\n";
				if (*it <= r) {
					ans++;
					//cout << *it << endl;
					//cout << (char)(i + 'a') << endl;
				}
			}
			cout << ans << endl;
		}
	}
}