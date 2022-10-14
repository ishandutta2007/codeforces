#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
int n;
vi dp, p;
int main() {
	cin >> n;
	p.resize(n + 1);
	for(int i = 0; i < n; i++) cin >> p[i];
	dp.resize(n + 1);
	dp[0] = 0;
	for(int i = 0; i < n; i++) dp[i + 1] = ((2*dp[i]) + 2 - dp[p[i]-1] + mod)%mod;
	cout << dp[n];
}