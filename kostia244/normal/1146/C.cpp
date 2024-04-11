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
//	freopen("in", "r", stdin);
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
int n, tn, z, t, ans;
vi a[2];
void req() {
	cout.flush();
	cout << a[0].size() << " " << a[1].size() << " ";
	for(auto i : a[0])
			cout << i << " ";
	for(auto i : a[1])
			cout << i << " ";
	cout << "\n";
	cout.flush();
	cin >> z;
	ans = max(ans, z);
}

void solve() {
	ans = 0;
	cin >> n;
	tn = n;
	tn = 1;
	while(tn <= n) {
		a[0].clear();
		a[1].clear();
		for(int i = 1; i <= n; i++) {
			a[(i&tn)>0].pb(i);
		}
		req();
		tn<<=1;
	}
	cout << "-1 " << ans << "\n";
	cout.flush();
}
int main() {
	doin();
	cin >> t;
	while(t--)
		solve();
}