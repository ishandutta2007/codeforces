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

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

int f[1 << 14];

void solve() {
	vector<int> a(100);
	for (int i = 0; i < 100; i++) a[i] = i;
	for (int j = 0; j < 100; j++) {
		for (int i = j + 1; i < 100; i++) {
			f[a[i] ^ a[j]] = 1;
		}
	}
	vector<int> b;
	for (int i = 101; i < (1 << 14); i++) {
		if (b.size() == 100) break;
		bool fl = true;
		for (int j : b) {
			if (f[i ^ j]) {
				fl = false;
				break;
			}
		}
		if (fl) {
			b.push_back(i);
		}
	}
	cout << "? ";
	for (int i : a) cout << i << " ";
	cout << endl;
	int t1; cin >> t1;
	for (int& i : a) i ^= t1;
	cout << "? ";
	for (int i : b) cout << i << " ";
	cout << endl;
	int t2; cin >> t2;
	for (int& i : b) i ^= t2;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (a[i] == b[j]) {
				cout << "! " << a[i] << endl;
				return;
			}
		}
	}
}