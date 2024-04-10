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
 
#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
//#define endl '\n'
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
mt19937 mrand(random_device{}());
 
double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;
 
void solve();
void scan();
 
signed main() {
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}
 
void solve() {
	string s = "";
	int x1 = 0, x2 = 0;
	int cnt = 0;
	cout << "a" << endl;
	cin >> x1;
	cnt++;
	if (!x1) return;
	if (x1 == 300) {
		for (int i = 0; i < x1; i++) s += "b";
		cout << s << endl;
		cin >> x1;
		return;
	}
	for (int i = 0; i <= x1; i++) s += "a";
	cout << s << endl;
	cin >> x2;
	cnt++;
	if (!x2) return;
	if (x2 == (x1 + 1)) {
		s = "";
		for (int i = 0; i < x1; i++) s += "b";
		cout << s << endl;
		cnt++;
		cin >> x1;
		return;
	}
	int l = x1 + 1;
	int b = x2;
	vector<bool> used(l, false);
	for (int i = 0; i < l; i++) {
		string s = "";
		for (int j = 0; j < l; j++) {
			if (j == i || used[j]) s += "b";
			else s += "a";
		}
		cout << s << endl;
		cin >> x1;
		cnt++;
		assert(cnt <= (l + 2));
		if (!x1) break;
		if (x1 < b) {
			used[i] = true;
			b = x1;
		}
	}
	return;
}