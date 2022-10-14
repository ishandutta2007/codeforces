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
int n, m, d, f, t;
int dp[100010][2], src[100010];
vi p;
bitset<100010> s;
vvi g;

void dfs(int v = 1, int p = 1) {
	dp[v][0] = dp[v][1] = 0;
	for (int i : g[v]) {
		if (i == p)
			continue;
		dfs(i, v);
		if (dp[i][0] != 0 || s.test(i)) {
			if (dp[i][0] + 1 > dp[v][0]) {
				dp[v][1] = dp[v][0];
				dp[v][0] = dp[i][0] + 1;
				src[v] = i;
			} else if (dp[i][0] + 1 > dp[v][1]) {
				dp[v][1] = dp[i][0] + 1;
			}
		}
	}
}
void efs(int v = 1, int p = 1) {
	int t;
	for (int i : g[v]) {
		if (i == p)
			continue;
		t = 0;
		if(src[v] != i)
			t = dp[v][0]+1;
		else if(dp[v][1] != 0 || s.test(v))
			t = dp[v][1]+1;
		if (t > dp[i][0]) {
			dp[i][1] = dp[i][0];
			dp[i][0] = t;
			src[i] = -1;
		} else if (t > dp[i][1]) {
			dp[i][1] = t;
		}
		efs(i, v);
	}
}
int main() {
	doin();
	cin >> n >> m >> d;
	g.resize(n + 1);
	getv(p, m, [](int i) {
		s.set(i);
	});
	for (int i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs();
	efs();
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += dp[i][0]<=d;
	cout << ans;
}