#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second - a.first < b.second - b.first;
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
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> plus, minus;
    for(int i = 0; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	if(b >= 0) {
    		plus.push_back({a, b});
    	} else {
    		minus.push_back({a, -b});
    	}
    }
    sort(plus.begin(), plus.end());
    int ans = 0;
    for(int i = 0; i < plus.size(); i++) {
    	if(plus[i].first <= r) {
    		++ans;
    		r += plus[i].second;
    	}
    }
    sort(minus.begin(), minus.end(), cmp);
    //cout << minus[0].first << endl;
    vvi dp(minus.size() + 1, vi(r + 1, 0));
    for(int i = (int)minus.size() - 1; i >= 0; i--) {
    	for(int j = 0; j <= r; j++) {
    		dp[i][j] = dp[i + 1][j];
    		if(j < minus[i].first || j < minus[i].second) {
    			continue;
    		}
    		dp[i][j] = max(dp[i][j], dp[i + 1][j - minus[i].second] + 1);
    	}
    }
    cout << dp[0][r] + ans;
}