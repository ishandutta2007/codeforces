#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int k;
map<ll, int> tp;
set<ll> s;
map<string, int> d;
map<pair<ll, int>, int> dp;
vector<int> dp1;

int dfs(ll x, int val, int level) {
	if(dp.find({x, val}) != dp.end()) {
		return dp[{x, val}];
	}
	if(s.find(x) == s.end()) {
		dp[{x, val}] = dp1[level];
		return dp1[level];
	}
	if(tp.find(x) != tp.end() && tp[x] != val) {
		dp[{x, val}] = 0;
		return 0;
	}
	if(level == 1) {
		dp[{x, val}] = 1;
		return 1;
	}
	int res = 0;
	for(int i = 0; i < 6; i++) {
		if(i == val || i + val == 5) {
			continue;
		}
		for(int j = 0; j < 6; j++) {
			if(j == val || j + val == 5) {
				continue;
			}
			res = ((ll)dfs(x * 2, i, level - 1) * dfs(x * 2 + 1, j, level - 1) + res) % mod;
		}
	}
	dp[{x, val}] = res;
	return res;
}




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    d["white"] = 0;
    d["green"] = 1;
    d["red"] = 2;
    d["orange"] = 3;
    d["blue"] = 4;
    d["yellow"] = 5;
    int n;
    cin >> k;
    dp1.resize(k + 1);
    dp1[1] = 1;
    dp1[0] = 1;
    for(int i = 2; i <= k; i++) {
    	int res = ((ll)dp1[i - 1] * dp1[i - 1]) % mod;
    	res = ((ll)res * 16) % mod;
    	dp1[i] = res;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
    	ll x;
    	string s1;
    	cin >> x >> s1;
    	int val = d[s1];
    	tp[x] = val;
    	while(x) {
    		//cout << x << endl;
    		s.insert(x);
    		x >>= 1;
    	}
    }
    int res = 0;
    for(int i = 0; i < 6; i++) {
    	res = (res + dfs(1, i, k)) % mod;
    }
    cout << res;
}