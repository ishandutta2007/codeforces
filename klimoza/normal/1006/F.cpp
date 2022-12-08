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

const int N = 20;
ll a[N][N];

map<ll, ll> kek[N][N];

void solve() {
	//cout << (2 ^ 7 ^ 12 ^ 6 ^ 4) << endl;
	int n, m; cin >> n >> m;
	ll k; cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	if (n == 1 && m == 1) {
		if (a[0][0] == k) cout << 1 << endl;
		else cout << 0 << endl;
		return;
	}
	int m1 = (n + m - 2) / 2;
	int m2 = (n + m - 2) - m1 - 1;
	for (int mask = 0; mask < (1 << m1); mask++) {
		int cx = 0, cy = 0;
		ll ck = a[0][0];
		bool fl = true;
		for (int i = 0; i < m1; i++) {
			if (mask & (1 << i)) cx++;
			else cy++;
			if (cx >= n || cy >= m) {
				fl = false;
				break;
			}
			ck ^= a[cx][cy];
		}
		if (!fl) continue;
		//cout << cx << " " << cy << " " << ck << endl;
		kek[cx][cy][ck] += 1;
	}
	ll ans = 0;
	//cout << m1 << " " << m2 << endl;
	for (int mask = 0; mask < (1 << m2); mask++) {
		int cx = n - 1, cy = m - 1;
		ll ck = a[n - 1][m - 1];
		bool fl = true;
		for (int i = 0; i < m2; i++) {
			if (mask & (1 << i)) cx--;
			else cy--;
			if (cx < 0 || cy < 0) {
				fl = false;
				break;
			}
			ck ^= a[cx][cy];
		}
		if (!fl) continue;
		//cout << cx << " " << cy << " " << ck << " lol\n";
		if (cx) ans += kek[cx - 1][cy][k ^ ck];
		if (cy) ans += kek[cx][cy - 1][k ^ ck];
	}
	cout << ans << endl;
	return;
}