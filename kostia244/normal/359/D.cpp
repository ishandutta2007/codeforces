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
typedef int _I;
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
int n, sparse[300001][22], lg[300001], mx = 0;
set<pi> ans;
int gcd(int a, int b) {
	int k = lg[b - a + 1];
	return __gcd(sparse[a][k], sparse[b - (1 << k) + 1][k]);
}

int main() {
	doin();
	cin >> n;
	int _lg = -1;
	for (int i = 1; i <= n; i++)
		lg[i] = (i == 1 << (_lg + 1) ? ++_lg : _lg);
	for (int i = 0; i < n; i++)
		cin >> sparse[i][0];
	for(int j = 1;j < 22;j++)
		for(int i = 0; i < n;i ++)if(i + (1 << j) - 1 < n)
			sparse[i][j] = (__gcd(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]));
	for (int i = 0; i < n; i++) {
		int lo = 0, hi = (n - i - 1), mid;
		while (lo < hi) {
			mid = (lo + hi + 1) >> 1;
			if (gcd(i, i + mid) != sparse[i][0])
				hi = mid - 1;
			else
				lo = mid;
		}
		int a1 = hi;
		lo = 0, hi = i, mid;
		while (lo < hi) {
			mid = (lo + hi + 1) >> 1;
			if (gcd(i-mid, i) != sparse[i][0])
				hi = mid - 1;
			else
				lo = mid;
		}
		mx = max(mx, a1 + hi);
		ans.insert( { a1 + hi, i - hi });

	}
	vi ans2;
	for(auto& i : ans) if(i.first == mx)
		ans2.pb(i.second);
	sort(all(ans2));
	cout << ans2.size() << " " << mx << "\n";
	for(auto& i : ans2) cout << i+1 << " ";
	return 0;
}