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
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e3 + 2;
int n, dp[N][N];
vi a;

int f(int i, int j) {
	if(i>j)
		return 6000;
	if(i == j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = min(a[i]==a[j] ? ((a[i]!=a[i+1]||a[j]!=a[j-1]) + f(i+1, j-1)) : 6000, min(f(i+1, j) + (a[i] != a[i+1]), f(i, j-1)+(a[j]!=a[j-1])));
}

int main() {
	doin();
	memset(dp, -1, sizeof dp);
	cin >> n;
	a.resize(n);
	for(auto& i : a) cin >> i;
	cout << f(0, n-1);
}