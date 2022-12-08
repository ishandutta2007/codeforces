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
const ll mod = 998244353;

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
	int n;
	string st1, st2;
	cin >> n >> st1 >> st2;
	set<pair<char, char>> f;
	int a[26];
	fill(a, a + 26, 0);
	for (char c : st1) {
		a[c - 'a']++;
	}
	for (char c : st2) {
		a[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] % 2 == 1) {
			cout << -1 << endl;
			return;
		}
	}
	vector<int> tp[2];
	for (int i = 0; i < n; i++) {
		if (st1[i] == 'a' && st2[i] == 'b') tp[0].push_back(i);
		if (st1[i] == 'b' && st2[i] == 'a') tp[1].push_back(i);
	}
	if (tp[0].size() % 2 == 0) {
		cout << (tp[0].size() + tp[1].size()) / 2 << endl;
	}
	else {
		cout << tp[0].size() / 2 + tp[1].size() / 2 + 2 << endl;
	}
	for (int i = 1; i < tp[0].size(); i += 2) {
		cout << tp[0][i - 1] + 1 << " " << tp[0][i] + 1 << endl;
	}
	for (int i = 1; i < tp[1].size(); i += 2) {
		cout << tp[1][i - 1] + 1 << " " << tp[1][i] + 1 << endl;
	}
	if (tp[0].size() % 2 == 1) {
		cout << tp[0].back() + 1 << " " << tp[0].back() + 1 << endl;
		cout << tp[0].back() + 1 << " " << tp[1].back() + 1 << endl;
	}
}