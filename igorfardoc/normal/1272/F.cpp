#include<bits/stdc++.h>
#define inf 1000000000
#define maxbal 800
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int dp[201][201][maxbal + 1];
char here[201][201][maxbal + 1];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= m; j++) {
    		for(int l = 0; l <= maxbal; l++) {
    			int k = l;
    			bool allopen = true;
    			if(i != 0 && s[i - 1] == ')') {
    				allopen = false;
    			}
    			if(j != 0 && t[j - 1] == ')') {
    				allopen = false;
    			}
    			if(allopen) {
    				k = maxbal - l;
    			}
    			if(i == 0 && j == 0) {
    				dp[i][j][k] = k;
    				here[i][j][k] = '(';
    				continue;
    			}
    			dp[i][j][k] = inf;
    			// add (
    			if(k != 0) {
	    			int minus1 = 0;
	    			int minus2 = 0;
	    			if(i != 0 && s[i - 1] == '(') {
	    				minus1 = 1;
	    			}
	    			if(j != 0 && t[j - 1] == '(') {
	    				minus2 = 1;
	    			}
	    			dp[i][j][k] = min(1 + dp[i - minus1][j - minus2][k - 1], dp[i][j][k]);
	    			here[i][j][k] = '(';
	    		}
	    		// add )
	    		if(k != maxbal) {
	    			int minus1 = 0;
	    			int minus2 = 0;
	    			if(i != 0 && s[i - 1] == ')') {
	    				minus1 = 1;
	    			}
	    			if(j != 0 && t[j - 1] == ')') {
	    				minus2 = 1;
	    			}
	    			int ans1 = 1 + dp[i - minus1][j - minus2][k + 1];
	    			if(ans1 < dp[i][j][k]) {
	    				dp[i][j][k] = ans1;
	    				here[i][j][k] = ')';
	    			}
	    		}
	    	}
	    }
	}
	string ans = "";
	int i = n;
	int j = m;
	int k = 0;
	while(i != 0 || j != 0 || k != 0) {
		ans += here[i][j][k];
		int i1, j1, k1;
		i1 = i;
		j1 = j;
		if(here[i][j][k] == '(') {
			k1 = k - 1;
		} else {
			k1 = k + 1;
		}
		if(i != 0 && s[i - 1] == here[i][j][k]) {
			--i1;
		}
		if(j != 0 && t[j - 1] == here[i][j][k]) {
			--j1;
		}
		i = i1;
		j = j1;
		k = k1;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}