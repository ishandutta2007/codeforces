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
const int bias = 203;
ll n, l, k;
ld dp[204][204][419], ans = 0;
vd p;
vi a;

int main() {
	doin();
	cin >> n >> l >> k;
	getv(p, n, [](ld& i) {i/=100;});
	getv(a, n);
	dp[0][0][bias + k] = 1;
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= i; w++) {
			for (int s = bias - 200; s <= (bias + 200); s++) {
				dp[i+1][w][s] += dp[i][w][s]*(1-p[i]);
				if(a[i] == -1)
					dp[i+1][w+1][s-1] += dp[i][w][s]*p[i];
				else
					dp[i+1][w+1][min(s+a[i], bias+200)] += dp[i][w][s]*p[i];
			}
		}
	}
	for(int i = l; i <= n; i++)
		for(int j = bias; j <= (bias+200); j++)
			ans+=dp[n][i][j];
	cout << fixed << setprecision(15) << ans;
}