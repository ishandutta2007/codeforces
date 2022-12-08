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

#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
//const ll mod = 777777773;
const ll mod = 998244353;
const ll MOD = mod * mod;

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
}

void solve() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	vector<int> cnt(26, 0);
	vector<vector<int>> ans(26, vector<int>(26, 0));
	for (char c : s) {
		for (int i = 0; i < 26; i++) {
			ans[i][c - 'a'] += cnt[i];
		}
		cnt[c - 'a']++;
	}
	int kek = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++)
			kek = max(kek, ans[i][j]);
	}
	for (int i = 0; i < 26; i++)
		kek = max(kek, cnt[i]);
	cout << kek << endl;
	return;
}