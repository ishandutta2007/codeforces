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

const int N = 2e5 + 7;

const ll mod1 = 1e9 + 7;
const ll mod2 = 777777773;
const ll P1 = 47;
const ll P2 = 239;

int pref[N];

ll p1[N], p2[N];
pair<ll, ll> h[N];

int get(int l, int r) {
	if (!l) return pref[r];
	return pref[r] - pref[l - 1];
}

vector<pair<pair<int, int>, char>> f;

int id[N];

void build(string s) {
	int n = s.size();
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= n; i++) {
		p1[i] = p1[i - 1] * P1 % mod1;
		p2[i] = p2[i - 1] * P2 % mod2;
	}
	h[0] = { s[0] - '0' + 1, s[0] - '0' + 1 };
	for (int i = 1; i < n; i++)
		h[i] = { ((h[i - 1].first * P1) % mod1 + s[i] - '0' + 1) % mod1, ((h[i - 1].second * P2) % mod2 + s[i] - '0' + 1) % mod2 };
}

int prv[N], nxt[N];

pair<ll, ll> geth(int l, int r) {
	if (!l) return h[r];
	else {
		return { (h[r].first - (h[l - 1].first * p1[r - l + 1]) % mod1 + mod1) % mod1, (h[r].second - (h[l - 1].second * p2[r - l + 1]) % mod2 + mod2) % mod2 };
	}
}

void solve() {
	fill(id, id + N, -1);
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		if (f.empty() || f.back().second != s[i]) f.push_back({ {i, i}, s[i] });
		else f.back().first.second++;
	}
	string t = "";
	for (auto u : f) {
		if (u.second == '1') {
			int len = u.first.second - u.first.first + 1;
			if (len & 1)
				t += "1";
		}
		else {
			for (int i = u.first.first; i <= u.first.second; i++) {
				id[i] = t.size();
				t += "0";
			}
		}
	}
	build(t);
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') prv[i] = i;
		else if(i) prv[i] = prv[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') nxt[i] = i;
		else if (i != (n - 1)) nxt[i] = nxt[i + 1];
	}
	for (int i = 0; i < n; i++) {
		if (i) pref[i] = pref[i - 1];
		if (s[i] == '1') pref[i]++;
	}
	int q; cin >> q;
	while (q--) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len; 
		l1--; l2--;
		int r1 = l1 + len - 1, r2 = l2 + len - 1;
		if (get(l1, r1) != get(l2, r2)) cout << "No\n";
		else if (get(l1, r1) == r1 - l1 + 1) cout << "Yes\n";
		else {
			int le1 = nxt[l1], re1 = prv[r1];
			int le2 = nxt[l2], re2 = prv[r2];
			if ((le1 - l1) % 2 != (le2 - l2) % 2) cout << "No\n";
			else if ((r1 - re1) % 2 != (r2 - re2) % 2) cout << "No\n";
			else {
				le1 = id[le1], le2 = id[le2], re1 = id[re1], re2 = id[re2];
				if (geth(le1, re1) == geth(le2, re2)) cout << "Yes\n";
				else cout << "No\n";
			}
		}
	}
	return;
}