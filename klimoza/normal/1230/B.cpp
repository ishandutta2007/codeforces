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

ostream& operator<<(ostream& out, vector<char>& a) {
	for (char c : a) out << c;
	return out;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<char> a(n);
	for (char& c : a) cin >> c;
	if (!k) {
		cout << a << endl;
		return;
	}
	if (a.size() == 1) {
		cout << 0 << endl;
		return;
	}
	if (a[0] != '1') {
		a[0] = '1';
		k--;
	}
	for (int i = 1; i < n; i++) {
		if (!k) break;
		if (a[i] != '0') {
			a[i] = '0';
			k--;
		}
	}
	cout << a << endl;
}