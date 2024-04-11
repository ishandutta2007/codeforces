#pragma comment(linker, "/STACK:16777216")
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
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
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
typedef ll _I;
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
int n, q, i, len[3], dp[256][256][256], nxt[100100][26];
char tp, c;
string s, g[3];

void add1() {
	cin >> c;
	g[0] += c;
	len[0]++;
	for (int i = 0; i <= len[1]; i++)
		for (int j = 0; j <= len[2]; j++) {
			dp[len[0]][i][j] = min(
					{ nxt[dp[len[0] - 1][i][j] + 1][g[0][len[0]] - 'a'],
							i ? nxt[dp[len[0]][i - 1][j] + 1][g[1][i] - 'a'] : n
										+ 1,
							j ? nxt[dp[len[0]][i][j - 1] + 1][g[2][j] - 'a'] : n
										+ 1 });
//			cout << len[0] << " " << i << " " << j << " " << dp[len[0]][i][j] << "\n";
		}
}
void add2() {
	cin >> c;
	len[1]++;
	g[1] += c;
	for (int i = 0; i <= len[0]; i++)
		for (int j = 0; j <= len[2]; j++) {
			dp[i][len[1]][j] = min(
					{ i ? nxt[dp[i - 1][len[1]][j] + 1][g[0][i] - 'a'] : n + 1,
							nxt[dp[i][len[1] - 1][j] + 1][g[1][len[1]] - 'a'],
									j ? nxt[dp[i][len[1]][j - 1] + 1][g[2][j]
												- 'a'] :
										n + 1 });
//			for (auto i : { i ? dp[i - 1][len[1]][j] : n + 1,
//					dp[i][len[1] - 1][j], j ? dp[i][len[1]][j - 1] : n + 1 })
//				cout << i << " ";
//			cout << " : ";
//			for (auto i : { g[0][i], g[1][len[1]], g[2][j]})
//				cout << i << " ";
//			cout << " : ";
//			cout << i << " " << len[1] << " " << j << " "
//					<< dp[i - 1][len[1]][j] + 1 << "\n";
		}
}
void add3() {
	cin >> c;
	g[2] += c;
	len[2]++;
	for (int i = 0; i <= len[0]; i++)
		for (int j = 0; j <= len[1]; j++) {
			dp[i][j][len[2]] =
					min(
							{
									i ? nxt[dp[i - 1][j][len[2]] + 1][g[0][i]
												- 'a'] :
										n + 1,
									j ? nxt[dp[i][j - 1][len[2]] + 1][g[1][j]
												- 'a'] :
										n + 1,
									nxt[dp[i][j][len[2] - 1] + 1][g[2][len[2]]
											- 'a'] });
//			cout << i << " " << j << " " << len[2] << " " << dp[i][j][len[2]] << "\n";
		}
}

int main() {
//	doin();
	cin >> n >> q >> s;
	s = " " + s;
	g[0] = g[1] = g[2] = " ";
	for (int i = 1; i <= n; i++)
		nxt[i][s[i] - 'a'] = i;
	for (int i = n; i < 100100; i++)
		for (int j = 0; j < 26; j++)
			nxt[i][j] = nxt[i][j] ? nxt[i][j] : n + 1;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < 26; j++) {
			nxt[i][j] = nxt[i][j] ? nxt[i][j] : nxt[i + 1][j];
		}
	dp[0][0][0] = 0;
	while (q--) {
		cin >> tp >> i, i--;
		if (tp == '-') {
			len[i]--, g[i].pop_back();
		} else {
			if (i == 0)
				add1();
			else if (i == 1)
				add2();
			else
				add3();
		}
		cout << (dp[len[0]][len[1]][len[2]] <= n ? "YES" : "NO") << "\n";
	}
}