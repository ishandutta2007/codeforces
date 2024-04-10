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
const ld eps = 1e-7;
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

map<vector<int>, int> kek;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int f = 1 << 15;
	for (int i = 0; i < f; i++) {
		vector<int> cur;
		int last = 0;
		for (int j = 0; j < n; j++) {
			a[j] ^= i;
			int cnt = 0;
			for (int k = 0; k < 15; k++) {
				if (a[j] & (1 << k)) cnt++;
			}
			if (j) cur.push_back(cnt - last);
			last = cnt;
			a[j] ^= i;
		}
		if(kek.find(cur) == kek.end())
			kek[cur] = i;
	}
	for (int i = 0; i < n; i++)
		a[i] >>= 15;
	for (int i = 0; i < f; i++) {
		vector<int> cur;
		int last = 0;
		for (int j = 0; j < n; j++) {
			a[j] ^= i;
			int cnt = 0;
			for (int k = 0; k < 15; k++) {
				if (a[j] & (1 << k)) cnt++;
			}
			if (j) cur.push_back(cnt - last);
			last = cnt;
			a[j] ^= i;
		}
		for (int j = 0; j < n - 1; j++)
			cur[j] *= -1;
		if (kek.find(cur) != kek.end()) {
			cout << (i << 15) + kek[cur] << endl;
			return;
		}
	}
	cout << -1 << endl;
	return;
}