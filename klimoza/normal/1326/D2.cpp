#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
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

const ll mod1 = 777777773;
const ll mod2 = 1e9 + 7;

const ll P1 = 47;
const ll P2 = 239;

const int N = 1e6 + 7;

ll h1[N], h2[N];
ll r1[N], r2[N];
ll p1[N], p2[N];

int n;

void build(string s) {
	p1[0] = 1;
	p2[0] = 1;
	for (int i = 1; i <= n; i++) {
		p1[i] = p1[i - 1] * P1 % mod1;
		p2[i] = p2[i - 1] * P2 % mod2;
	}
	h1[0] = s[0] - 'a' + 1;
	h2[0] = s[0] - 'a' + 1;
	for (int i = 1; i < s.size(); i++) {
		h1[i] = (h1[i - 1] * P1 % mod1 + s[i] - 'a' + 1) % mod1;
		h2[i] = (h2[i - 1] * P2 % mod2 + s[i] - 'a' + 1) % mod2;
	}
	r1[n - 1] = s[n - 1] - 'a' + 1;
	r2[n - 1] = s[n - 1] - 'a' + 1;
	for (int i = n - 2; i >= 0; i--) {
		r1[i] = (r1[i + 1] * P1 % mod1 + s[i] - 'a' + 1) % mod1;
		r2[i] = (r2[i + 1] * P2 % mod2 + s[i] - 'a' + 1) % mod2;
	}
}

pair<ll, ll> gethash(int l, int r) {
	if (!l) return { h1[r], h2[r] };
	return { (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1, (h2[r] - h2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2 };
}

pair<ll, ll> getrev(int l, int r) {
	if (r == n - 1) return { r1[l], r2[l] };
	return { (r1[l] - r1[r + 1] * p1[r - l + 1] % mod1 + mod1) % mod1, (r2[l] - r2[r + 1] * p2[r - l + 1] % mod2 + mod2) % mod2 };
}

void solve() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		n = s.size();
		build(s);
		int f1 = 0, f2 = n - 1;
		while (f1 <= f2 && s[f1] == s[f2])
			f1++, f2--;
		if (f1 > f2) cout << s << endl;
		else {
			int a = f1;
			int b = f2;
			for (int len = 1; len <= n; len++) {
				if (f1 + n - f2 - 1 + len > n) break;
				pair<ll, ll> t1 = gethash(f1, f1 + len - 1);
				pair<ll, ll> t2 = getrev(f1, f1 + len - 1);
				/*if (len == 3) {
					cout << t1.first << " " << t1.second << endl;
					cout << t2.first << " " << t2.second << endl;
				}*/
				if (t1 == t2) {
					a = f1 + len;
					b = f2;
					continue;
				}
				t1 = gethash(f2 - len + 1, f2);
				t2 = getrev(f2 - len + 1, f2);
				if (t1 == t2) {
					a = f1;
					b = f2 - len;
				}
			}
			for (int i = 0; i < a; i++) cout << s[i];
			for (int i =b + 1; i < n; i++) cout << s[i];
			cout << endl;
		}
	}
	return;
}