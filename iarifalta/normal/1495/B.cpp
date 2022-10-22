/**
 *	author:   fractal
 *	timus: 288481RF
 *	created: 03/10/21 18:42
**/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define nl printf("\n");
#define clbuff fflush(stdin);

mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e6 + 2;
const int M = 1e5;
const int mod = 0;
const int inf = 2e9 + 3;
const ll INF = 1e18;
const ld pi2 = 2.0 * 3.141592;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void files() {
	#ifndef PC
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif
}

int n, p[N], up[2][N], dw[2][N], mxp[N], mxs[N], ans;

int getup(int c, int i) {
	if (up[c][i] != -1) return up[c][i];
	if (c == 0) {
		if (i > 1 && p[i - 1] > p[i])
			return up[0][i] = 1 + getup(0, i - 1);
		else
			return up[0][i] = 0;
	}
	else {
		if (i < n && p[i + 1] > p[i])
			return up[1][i] = 1 + getup(1, i + 1);
		else
			return up[1][i] = 0;
	}
}

int getdw(int c, int i) {
	if (dw[c][i] != -1) return dw[c][i];
	if (c == 0) {
		if (i > 1 && p[i - 1] < p[i])
			return dw[0][i] = 1 + getdw(0, i - 1);
		else
			return dw[0][i] = 0;
	}
	else {
		if (i < n && p[i + 1] < p[i])
			return dw[1][i] = 1 + getdw(1, i + 1);
		else
			return dw[1][i] = 0;
	}
}

int main() {
	speed;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		up[0][i] = up[1][i] = dw[0][i] = dw[1][i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		getup(0, i);
		getup(1, i);
		getdw(0, i);
		getdw(1, i);
	}
	for (int i = 1; i <= n; ++i) {
		mxp[i] = max({mxp[i - 1], up[0][i], dw[0][i]});
	}
	for (int i = n; i >= 1; --i) {
		mxs[i] = max({mxs[i + 1], up[1][i], dw[1][i]});
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i - 1] < p[i] && p[i] > p[i + 1]) {
			int a = dw[0][i], b = dw[1][i], mx = max(mxp[i - a], mxs[i + b]);			
			if (a == b && a % 2 == 0) {
				ans += (mx < a);
			}
		}
	}
	cout << ans << '\n';
}