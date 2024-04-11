#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCALc
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef int _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int bias = 20;
int dp[20][40][40][40], P[20][40][40][40], N, a, b;
vi h;

int f(int i, int po_2, int po_1, int pc) {
	int p = h[i - 1] - a * po_1 - b*po_2 - b*pc, c = h[i] - a * pc - b*po_1, n = h[i+1] - b*pc;
	if (i == N-1) {
		return (p >= 0 || c >= 0) ? 1000000 : 0;
	}
	if(p<0&&c<0&&n<0) {
		P[i][po_2][po_1][pc] = 2;
		return  dp[i][po_2][po_1][pc] = f(i + 1, po_1, pc, 0);
	}
	if (dp[i][po_2][po_1][pc] != -1)
		return dp[i][po_2][po_1][pc];
	int &ans = dp[i][po_2][po_1][pc];
	ans = INT_MAX;
	int t;
	if (p >= 0 || c >= 0 || n>=0) {
		t = 1+f(i, po_2, po_1, pc + 1);
		if (t < ans) {
			ans = t;
			P[i][po_2][po_1][pc] = 1;
		}
	}
	if (p < 0) {
		t = f(i + 1, po_1, pc, 0);
		if (t < ans) {
			ans = t;
			P[i][po_2][po_1][pc] = 2;
		}
	}
	return ans;
}

void bt(int i, int p, int c, int n) {
	if (i == N - 1)
		return;
	if (P[i][p][c][n] == 1) {
		cout <<i+1 <<" ";
		bt(i, p, c, n+1);
	} else if (P[i][p][c][n] == 2) {
		bt(i + 1, c, n, 0);
	}
}

int main() {
	memset(dp, -1, sizeof dp);
	doin();
	cin >> N >> a >> b;
	getv(h, N);
	h.pb(-1);
	cout << f(1, 0, 0, 0) << "\n";
	bt(1, 0, 0, 0);
}