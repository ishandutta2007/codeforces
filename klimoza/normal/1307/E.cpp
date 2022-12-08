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
const ll mod = 1e9 + 7;
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

	int n, m;
	cin >> n >> m;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	vector<pair<int, int>> a(m);
	vector<bool> bad(m, false);
	vector<vector<int>> kek(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<int> pos1(m, n), pos2(m, -1);
	for (int i = 0; i < m; i++) {
		int cnt = a[i].second;
		for (int j = 0; j < n; j++) {
			if (s[j] == a[i].first)
				cnt--;
			if (!cnt) {
				pos1[i] = j;
				break;
			}
		}
		if (pos1[i] == n)
			bad[i] = true;
		cnt = a[i].second;
		for (int j = n - 1; j >= 0; j--) {
			if (s[j] == a[i].first)
				cnt--;
			if (!cnt) {
				pos2[i] = j;
				break;
			}
		}
	}
	/*for (int i = 0; i < m; i++)
		cout << pos1[i] << " ";
	cout << endl;
	for (int i = 0; i < m; i++)
		cout << pos2[i] << " ";
	cout << endl;*/
	int tmp = 0;
	for (int i = 0; i < m; i++) {
		if (bad[i]) continue;
		tmp++;
		kek[a[i].first].push_back(i);
	}
	if (!tmp) {
		cout << "0 1\n";
		return;
	}
	int ans = 0;
	ll cnt = 1;
	for (int i = -1; i <= n; i++) {
		//cout << i << endl;
		int cur = 0;
		ll tt = 1;
		if (i == -1) {
			for (int j = 0; j <= n; j++) {
				if (kek[j].empty()) continue;
				ll a = 0, b = 0, c = 0;
				for (int k : kek[j]) {
					if (pos1[k] <= i && pos2[k] > i)
						a++;
					else if (pos1[k] <= i)
						b++;
					else if (pos2[k] > i)
						c++;
				}
				//cout << i << " " << j << " " << a << " " << b << " " << c << endl;
				if (a + b + c == 0) continue;
				else if (a + b == 0) {
					cur++;
					tt = (tt * c) % mod;
				}
				else if (a + c == 0) {
					cur++;
					tt = (tt * b) % mod;
				}
				else if (b + c == 0) {
					if (a == 1) {
						cur++;
						tt = (tt * 2) % mod;
					}
					else {
						cur += 2;
						tt = (tt * a * (a - 1)) % mod;
					}
				}
				else {
					cur += 2;
					ll lol = b * c + a * (b + c) + a * (a - 1);
					lol %= mod;
					tt = (tt * lol) % mod;
				}
			}
			if (cur > ans) {
				ans = cur;
				cnt = tt;
			}
			else if (cur == ans) {
				cnt = (cnt + tt) % mod;
			}
		}
		else {
			bool bl = false;
			for (int j = 0; j <= n; j++) {
				if (kek[j].empty()) continue;
				ll a = 0, b = 0, c = 0;
				int h = -1;
				for (int k : kek[j]) {
					if (pos1[k] == i)
						h = k;
					if (pos1[k] <= i && pos2[k] > i)
						a++;
					else if (pos1[k] <= i)
						b++;
					else if (pos2[k] > i)
						c++;
				}
				if (h != -1) {
					bl = true;
					if (pos2[h] > i)
						a--;
					if (a + c == 0) {
						cur++;
					}
					else {
						cur += 2;
						tt = tt * (a + c) % mod;
					}
					continue;
				}
				//cout << i << " " << j << " " << a << " " << b << " " << c << endl;
				if (a + b + c == 0) continue;
				else if (a + b == 0) {
					cur++;
					tt = (tt * c) % mod;
				}
				else if (a + c == 0) {
					cur++;
					tt = (tt * b) % mod;
				}
				else if (b + c == 0) {
					if (a == 1) {
						cur++;
						tt = (tt * 2) % mod;
					}
					else {
						cur += 2;
						tt = (tt * a * (a - 1)) % mod;
					}
				}
				else {
					cur += 2;
					ll lol = b * c + a * (b + c) + a * (a - 1);
					lol %= mod;
					tt = (tt * lol) % mod;
				}
			}
			if (!bl) continue;
			if (cur > ans) {
				ans = cur;
				cnt = tt;
			}
			else if (cur == ans) {
				cnt = (cnt + tt) % mod;
			}
		}
		//cout << ans << endl;
	}
	cout << ans << " " << cnt % mod << endl;
	return;
}