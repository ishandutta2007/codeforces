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
		vector<int> f1;
		vector<int> f2;
		for (int i = 0; i < n; i++) {
			if ((s[i] - '0') % 2 == 0) f1.push_back(s[i] - '0');
			else f2.push_back(s[i] - '0');
		}
		vector<int> ans;
		int h = 0;
		for (int i = 0; i < f1.size(); i++) {
			if (h == f2.size()) ans.push_back(f1[i]);
			else if (f1[i] > f2[h]) {
				while (h < f2.size() && f1[i] > f2[h]) {
					ans.push_back(f2[h]);
					h++;
				}
				ans.push_back(f1[i]);
			}
			else
				ans.push_back(f1[i]);
		}
		while (h < f2.size()) ans.push_back(f2[h++]);
		for (int i : ans) cout << i;
		cout << endl;
	}
}