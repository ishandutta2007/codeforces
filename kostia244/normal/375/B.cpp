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
int n, m, ans, t, s[5005], ts[5005];
char mat[5005][5005];

int f() {
	int ans = 0;
	memcpy(ts, s, sizeof s);
	sort(ts, ts+n);
	for(int i = n-1; i >= 0; i--)
		ans = max(ans, (n-i)*ts[i]);
	return ans;
}

int main() {
	doin();
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];
	for(int j = m-1; j >= 0; j--) {
		for(int i = 0; i < n; i++)
			if(mat[i][j] == '0')
				s[i] = 0;
			else
				s[i]++;
		ans = max(ans,f());
	}
	cout << ans;
	return 0;
}