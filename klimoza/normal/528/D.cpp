/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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

int rev(int ind, int bit) {
	int res = 0;
	for (int i = 0; i < bit; i++) {
		if (ind & (1 << i)) {
			res |= (1 << (bit - i - 1));
		}
	}
	return res;
}

void fft(vcd& a, int flag) {
	int n = (int)a.size();
	int bit = 0;
	while ((1 << bit) < n) bit++;
	for (int i = 0; i < n; i++) {
		if (i < rev(i, bit))
			swap(a[i], a[rev(i, bit)]);
	}
	for (int step = 2; step <= n; step *= 2) {
		cd wl(cos(2 * PI / step), flag * sin(2 * PI / step));
		for (int i = 0; i < n; i += step) {
			cd w(1, 0);
			for (int j = 0; j < step / 2; j++) {
				cd u = a[i + j], v = a[i + j + step / 2] * w;
				a[i + j] = u + v;
				a[i + j + step / 2] = u - v;
				w *= wl;
			}
		}
	}
	if (flag == -1) {
		for (cd& i : a) i /= n;
	}
}

vector<ll> operator*(vector<ll> a, vector<ll> b) {
	vcd a1(a.begin(), a.end());
	vcd b1(b.begin(), b.end());
	int n = 1;
	while (n <= a.size() + b.size()) n <<= 1;
	a1.resize(n);
	b1.resize(n);
	fft(a1, 1);
	fft(b1, 1);
	for (int i = 0; i < n; i++) {
		a1[i] *= b1[i];
	}
	fft(a1, -1);
	a.clear(); a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i] = (ll)(a1[i].real() + 0.5) % mod;
	}
	return a;
}

char l[4] = { 'A', 'T', 'G', 'C' };

void add(vector<ll>& a, vector<ll> b) {
	for (int i = 0; i < a.size(); i++)
		a[i] += b[i];
}

void solve() {
	string s, t;
	int k;
	int n, m;
	cin >> n >> m >> k;
	cin >> s >> t;
	int lst[4] = { -1, -1, -1, -1 };
	vector<vector<ll>> mem(4, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == l[j])
				lst[j] = i;
			if (lst[j] != -1 && (i - lst[j]) <= k)
				mem[j][i] = 1;
		}
	}
	for (int j = 0; j < 4; j++)
		lst[j] = n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == l[j])
				lst[j] = i;
			if (lst[j] != n && (lst[j] - i) <= k)
				mem[j][i] = 1;
		}
	}
	//cout << "lol\n";
	vector<vector<ll>> kek(4, vector<ll>(n + 1));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			if (t[i] == l[j])
				kek[j][n - i] = 1;
		}
	}
	/*for (int i = 0; i < 4; i++) {
		for (ll j : mem[i])
			cout << j;
		cout << endl;
		for (ll j : kek[i])
			cout << j;
		cout << endl;
	}*/
	vector<ll> ans(2 * n + 1);
	for (int i = 0; i < 4; i++) {
		add(ans, mem[i] * kek[i]);
		//for (int i = 0; i <= 2 * n; i++) cout << i << " " << ans[i] << endl;
	}
	int an = 0;
	for (int i = n; i <= 2 * n; i++)
		if (ans[i] == m)
			an++;
	cout << an << endl;
	return;
}