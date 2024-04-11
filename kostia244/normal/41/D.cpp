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
int n, m, k, dp[110][110][13], st;
pi p[110][110][13];
char mat[110][110];
string s;
void bt(int i, int j, int r = 0) {
	if (i == n) {
		st = j;
		return;
	}
	if (p[i][j][r].first == 1)
		s += "L";
	else
		s += "R";
	bt(i+1, j+p[i][j][r].first, p[i][j][r].second);
}

int main() {
	doin();
	memset(dp, -100000000, sizeof dp);
	cin >> n >> m >> k, k++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	for (int i = 0; i-2 <= n; i++)
		for (int j = 0; j-2 <= m; j++) {
			for(int r = 0; r < k; r++)
				dp[i][j][r] = -100000000;
		}
	for (int j = 1; j <= m; j++) {
		dp[n][j][(mat[n][j] - '0') % k] = mat[n][j] - '0';
	}
	int a, b;
	for (int i = n - 1; i; i--)
		for (int j = 1; j <= m; j++) {
			int val = mat[i][j] - '0';
			for (int r = 0; r < k; r++) {
				if (dp[i + 1][j - 1][r] > dp[i + 1][j + 1][r])
					p[i][j][(r+val)%k] = {-1, r};
					else
					p[i][j][(r+val)%k] = {1, r};
					dp[i][j][(r+val)%k] = val+max(dp[i + 1][j - 1][r], dp[i + 1][j + 1][r]);
				}
			}
	int ans = -100000000, P = -1;
	for (int j = 1; j <= m; j++) {
		if (dp[1][j][0] > ans) {
			P = j;
			ans = dp[1][j][0];
		}
	}
	if(ans < 0)
		return cout << -1, 0;
	cout << ans << "\n";
	bt(1, P, 0);
	cout << st << "\n";
	reverse(all(s));
	cout << s;
}