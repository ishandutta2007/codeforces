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
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef int _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int r, g, dp[2][400005], h;

int main() {
//	doin();
	cin >> r >> g;
	bool can = true;
	int h, mh;
	dp[0][0] = 1;
	mh = -1;
	for (h = 0; (mh+1)==h; h++) {
		for(int i = 0; i <= 200000; i++) dp[(h+1)&1][i] = 0;
		for (int ur = 0; ur <= min((h * (h + 1)) / 2, r); ur++) {
			if(dp[h&1][ur] == 0)
				continue;
			int ug = ((h * (h + 1)) / 2)-ur;
			if((g-ug)>h||((r-ur)>h))
				mh = h;
			(dp[(h+1)&1][ur] += dp[h&1][ur]*((g-ug)>h)) %= mod;
			(dp[(h+1)&1][ur+h+1] += dp[h&1][ur]*((r-ur)>h)) %= mod;
		}
	}
	int ans = 0;
	h = mh+1;
	for (int i = 0; i <= ((h * (h + 1)) / 2); i++)
		if(dp[h&1][i] > 0)
		(ans += dp[h&1][i]) %= mod;
	cout << ans;
	return 0;
}