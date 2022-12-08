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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
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

const int N = 3e3 + 7;

ll dp[N][N];
ll ddp[N][N];

ll ans = 0;

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}

void add(ll& a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

ll cur[N];

ll check(string s, string t) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < t.size(); j++) {
			if (i == 0) {
				if (s[i] != t[j]) continue;
				ddp[i][j] = 2;
			}
			else {
				//if (j == 3 && i == 2) cout << ddp[ i - 1][i + j] << endl;
				if((j + i) < t.size() && s[i] == t[j + i])
					add(ddp[i][j], ddp[i - 1][j]);
				if (j + 1 < t.size() && s[i] == t[j])
					add(ddp[i][j], ddp[i - 1][j + 1]);
			}
			//if(ddp[i][j])cout << i << " " << j << " " << ddp[i][j] << endl;
		}
	}
	return ddp[s.size() - 1][0];
}

ll smart(string s, string t) {
	ans = 0;
	int n = s.size();
	int m = t.size();
	for (int i = 0; i < N; i++)
	{
		cur[i] = 0;
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
			ddp[i][j] = 0;
		}
	}
	reverse(all(t));
	add(ans, (n - m + 1) * check(s.substr(0, m), t) % mod);
	for (int i = 0; i < N; i++)
	{
		cur[i] = 0;
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
	}
	reverse(all(t));
	string kek = t;
	reverse(all(kek));
	for (int i = 0; i < n; i++) {
		if (i && s[i] == t.back()) {
			dp[i][0] = bp(2, i);
		}
		for (int j = 1; j < min(i, m); j++) {
			if (s[i] != t[m - 1 - j]) continue;
			//cout << i << " " << j << endl;
			dp[i][j] = cur[j - 1];
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
		//cout << i << " " << ddp[i][0] << endl;
		if (i < m)
			cur[i] = ddp[i][0];
		//cout << i << " " << dp[i][1] << endl;
		add(ans, (n - i) * 1ll * dp[i][m - 1] % mod);
		for (int j = 0; j < min(i, m); j++)
			add(cur[j], dp[i][j]);
	}
	return ans;
}

ll stupid(string s, string t) {
	int n = s.size();
	int m = t.size();
	ll a = 0;
	for (int i = m; i <= n; i++) {
		for (int mask = 0; mask < (1 << i); mask++) {
			string kek = "";
			for (int j = 0; j < i; j++) {
				if ((1 << j) & mask)
					kek += s[j];
				else
					kek = s[j] + kek;
			}
			if (kek.substr(0, m) == t)
				a++;
		}
	}
	return a;
}

void stress() {
	int cnt = 0;
	while (true) {
		cnt++;
		int n = rand() % 10 + 1;
		int m = rand() % n + 1;
		string s = "", t = "";
		for (int i = 0; i < n; i++)
			s += (char)('a' + rand() % 10);
		for(int i = 0; i < m; i++)
			t += (char)('a' + rand() % 10);
		ll m1 = smart(s, t);
		ll m2 = stupid(s, t);
		if (m1 == m2) cout << "TEST# " << cnt << " OK\n";
		else {
			cout << "TEST# " << cnt << " FAILED\n";
			cout << s << " " << t << endl;
			cout << m1 << " " << m2 << endl;
			return;
		}
	}
}

void solve() {
	//stress(); return;
	string s, t; cin >> s >> t;
	cout << smart(s, t) << endl;
	return;
}