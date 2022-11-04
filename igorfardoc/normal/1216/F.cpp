#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> otr;
    for(int i = 0; i < n; i++) {
    	if(s[i] == '1') {
    		otr.push_back({i - k + 1, i + k + 1});
    	}
    }
    vector<ll> dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
    	dp[i] = i + dp[i - 1];
    	int id1 = lower_bound(otr.begin(), otr.end(), (pair<int, int>){i - 2 * k, -100000}) - otr.begin();
    	if(id1 >= otr.size() || otr[id1].first > i || otr[id1].second < i) {
    		continue;
    	}
    	ll other = (otr[id1].first + otr[id1].second) / 2;
    	other += dp[max(otr[id1].first - 1, 0)];
    	dp[i] = min(dp[i], other);
    }
    cout << dp[n];
}