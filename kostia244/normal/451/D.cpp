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
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
const int p = 37;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ans_odd, ans_even, dp[2][2];
string s;

ll nck(ll n, ll k) {
	if(k == 0) return 1;
	if(2*k > n) return nck(n, n-k);
	return (n*nck(n-1, k-1))/k;
}

int main() {
	doin();
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		dp[i&1][s[i] == 'b']++;
	ans_odd = ((dp[0][0]*(dp[0][0]-1))>>1)+dp[0][0];
	ans_odd += ((dp[0][1]*(dp[0][1]-1))>>1)+dp[0][1];
	ans_odd += ((dp[1][0]*(dp[1][0]-1))>>1)+dp[1][0];
	ans_odd += ((dp[1][1]*(dp[1][1]-1))>>1)+dp[1][1];


	ans_even = dp[0][0]*dp[1][0];
	ans_even += dp[0][1]*dp[1][1];
	cout << ans_even << " " << ans_odd << "\n";
	return 0;
}