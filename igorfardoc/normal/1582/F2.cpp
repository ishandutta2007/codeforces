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
    int n;
    cin >> n;
    vi a(n);
    vector<bool> ans(8193, false);
    ans[0] = true;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<vector<bool>> used(5001, vector<bool>(8193, false));
    vvi dp(5001);
    for(int i = 1; i <= 5000; i++) {
    	dp[i].push_back(0);
    	used[i][0] = true;
    }
    for(int i = 0; i < n; i++) {
    	if(a[i] == 0) {
    		continue;
    	}
    	for(int j = 0; j < dp[a[i]].size(); j++) {
    		int here = a[i] ^ dp[a[i]][j];
    		ans[here] = true;
    		for(int k = a[i] + 1; k <= 5000; k++) {
    			if(used[k][here]) {
    				break;
    			}
    			used[k][here] = true;
    			dp[k].push_back(here);
    		}
    	}
    	dp[a[i]].clear();
    }
    int am = 0;
    for(int i = 0; i <= 8192; i++) {
    	if(ans[i]) {
    		++am;
    	}
    }
    cout << am << '\n';
    for(int i = 0; i <= 8192; i++) {
    	if(ans[i]) {
    		cout << i << ' ';
    	}
    }
}