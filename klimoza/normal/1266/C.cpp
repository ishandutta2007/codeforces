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

#define endl '\n'

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
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

void solve() {
	int n, m; cin >> n >> m;
	if (n == 1 && m == 1) cout << 0 << endl;
	else if (n == 1) {
		for (int i = 0; i < m; i++) {
			cout << (i + 2) << " ";
		}
	}
	else if (m == 1) {
		for (int i = 0; i < n; i++) {
			cout << (i + 2) << endl;
		}
	}
	else {
		ll cur = m;
		vector<vector<int>> a(n, vector<int>(m));
		vector<ll> b(n + m);
		for (int i = 0; i < n; i++) {
			cur++;
			for (int j = 0; j < m; j++) {
				cout << lcm(cur, (ll)j + 1) << " ";
			}
			cout << endl;
		}
	}
	return;
}