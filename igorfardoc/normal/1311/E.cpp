#include<bits/stdc++.h>
#define prev prev1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<bool>> dp(5001, vector<bool>(5001, false));
vector<vector<int>> prev(5001, vector<int>(5001, -1));
vector<vector<int>> depth(5001, vector<int>(5001, -1));
vi ans;

void rec(int n, int d, int start) {
	if(n <= 1) {
		return;
	}
	if(prev[n][d] == 0) {
		ans[start + 1] = start;
		rec(n - 1, d - (n - 1), start + 1);
		return;
	}
	int amver = prev[n][d];
	ans[start + 1] = start;
	for(int i = start + 2; i < start + 1 + amver; i++) {
		ans[i] = (i - start) / 2 + start;
	}
	ans[start + 1 + amver] = start;
	rec(n - 1 - amver, depth[n][d], start + 1 + amver);
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
    for(int i = 1; i <= 5000; i++) {
    	for(int j = 0; j <= 5000; j++) {
    		if(i == 1) {
    			if(j == 0) {
    				dp[i][j] = true;
    			}
    			continue;
    		}
    		if(j < i - 1) {
    			continue;
    		}
    		if(dp[i - 1][j - (i - 1)]) {
    			dp[i][j] = true;
    			prev[i][j] = 0;
    			continue;
    		}
    		int here = j - (i - 1);
    		int now = 0;
    		int nowver = 1;
    		int iter = 0;
    		while(true) {
    			if(nowver + 2 > i || now > here) {
    				break;
    			}
    			if(dp[i - 1 - nowver][here - now]) {
    				dp[i][j] = true;
    				prev[i][j] = nowver;
    				depth[i][j] = here - now;
    				break;
    			}
    			now += (nowver + 1) * (iter + 1);
    			++iter;
    			nowver = (nowver + 1) * 2 - 1;
    		}
    	}
    }
    int t;
    cin >> t;
    while(t--) {
    	int n, d;
    	cin >> n >> d;
    	if(dp[n][d]) {
    		cout << "YES\n";
    		ans.assign(n, -1);
    		rec(n, d, 0);
    		for(int i = 1; i < n; i++) {
    			cout << ans[i] + 1 << ' ';
    		}
    		cout << '\n';
    	} else {
    		cout << "NO\n";
    	}
    }
}