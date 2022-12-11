#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

string sum(const string& a, const string& b) {
	string ans = "";
	int i = sz(a) - 1, j = sz(b) - 1;
	int c = 0;
	while (i >= 0 && j >= 0) {
		c += (a[i] - '0') + (b[j] - '0');
		ans += char(c % 10 + '0');
		c /= 10;
		--i, --j;
	}
	while (i >= 0) {
		c += (a[i] - '0');
		ans += char(c % 10 + '0');
		c /= 10;
		--i;
	}
	while (j >= 0) {
		c += (b[j] - '0');
		ans += char(c % 10 + '0');
		c /= 10;
		--j;
	}
	if (c) {
		ans += char(c + '0');
	}
	reverse(all(ans));
	return ans;
}

string s;

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

void add(int& a, int b, int mod) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void mul(int& a, int b, int mod) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

vector<pii> t;

const int nmax = 1e6 + 100;

int deg1[nmax];
int deg2[nmax];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = {s[tl] - '0', s[tl] - '0'};
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	int x = t[v * 2].first;
	mul(x, deg1[tr - tm], mod1);
	add(x, t[v * 2 + 1].first, mod1);
	t[v].first = x;

	int y = t[v * 2].second;
	mul(y, deg2[tr - tm], mod2);
	add(y, t[v * 2 + 1].second, mod2);
	t[v].second = y;
}

int n;

pii get(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	if (r <= tm) {
		return get(v * 2, tl, tm, l, r);
	}
	if (l > tm) {
		return get(v * 2 + 1, tm + 1, tr, l, r);
	}
	pii ans = get(v * 2, tl, tm, l, tm);
	mul(ans.first, deg1[r - tm], mod1);
	mul(ans.second, deg2[r - tm], mod2);
	pii b = get(v * 2 + 1, tm + 1, tr, tm + 1, r);
	add(ans.first, b.first, mod1);
	add(ans.second, b.second, mod2);
	return ans;
}

void check(int i, int j) {
	if (i > 1 && s[0] == '0') {
		return;
	}
	if (j - i > 1 && s[i] == '0') {
		return;
	}
	if (sz(s) - j > 1 && s[j] == '0') {
		return;
	}
	pii x = get(1, 0, n - 1, 0, i - 1);
	pii y = get(1, 0, n - 1, i, j - 1);
	pii z = get(1, 0, n - 1, j, n - 1);
	add(x.first, y.first, mod1);
	add(x.second, y.second, mod2);
	if (x.first != z.first || x.second != z.second) {
		return;
	}
	string a = s.substr(0, i);
	string b = s.substr(i, j - i);
	string c = s.substr(j, sz(s) - j);
	string t = sum(a, b);
	if (t == c) {
		cout << a << "+" << b << "=" << c << "\n";
		exit(0);
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	deg1[0] = deg2[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		deg1[i] = deg1[i - 1];
		mul(deg1[i], 10, mod1);
		deg2[i] = deg2[i - 1];
		mul(deg2[i], 10, mod2);
	}

	cin >> s;
	n = sz(s);

	t.resize(4 * n);
	build(1, 0, n - 1);

	for (int x = n / 3 - 2; x <= n / 2 + 2; ++x) {
		if (x > 0 && x < n) {
			for (int y = x - 2; y <= x; ++y) {
				if (y > 0 && n - x - y > 0) {
					check(n - x - y, n - x);
					check(y, n - x);
				}
			}
		}
	}

}