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
const double eps = 1e-8;
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

const int L = 20;
const int N = 3e5 + 7;

int can[L][L];
int dd[N][L];

void solve() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			can[i][j] = -1e9;
		}
	}
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < L; j++) dd[i][j] = -1e9;
		for (int j = 0; j < L; j++) {
			if (!((1 << j) & a[i])) continue;
			dd[i][j] = i;
			for (int k = 0; k < L; k++) {
				dd[i][k] = max(dd[i][k], can[j][k]);
			}
		}
		for (int j = 0; j < L; j++) {
			if (!((1 << j) & a[i])) continue;
			for (int k = 0; k < L; k++) {
				can[j][k] = max(can[j][k], dd[i][k]);
			}
		}
	}
	while (q--) {
		int u, v; cin >> u >> v; u--; v--;
		bool fl = false;
		for (int i = 0; i < L; i++) {
			if ((1 << i) & a[u]) {
				if (dd[v][i] >= u) {
					fl = true;
					break;
				}
			}
		}
		if (fl) cout << "Shi\n";
		else cout << "Fou\n";
	}
}