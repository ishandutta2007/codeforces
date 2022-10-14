#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[100100];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	dp[0]=1;
	cin >> s;
	int n = s.size();
	if(s.find('m')!=string::npos) return cout << 0, 0;
	if(s.find('w')!=string::npos) return cout << 0, 0;
	for(int i = 0; i < n; i++) {
		if(i+1<n&&s[i]==s[i+1]&&(s[i]=='u'||s[i]=='n'))
			(dp[i+2] += dp[i])%=mod;
		(dp[i+1]+=dp[i])%=mod;
	}
	cout << dp[n];
}