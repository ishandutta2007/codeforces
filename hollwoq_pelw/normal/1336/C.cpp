#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 1515 + 1515;
string s, t; int dp[N][N];
// tau hai
signed main(){
    cin >> s >> t;
    for (int l = 0; l < s.length(); l++){
        for (int i = 0; i + l < s.length(); i++){
            int j = i + l;
            char c = s[l];
            if (!l){
                if (i < t.length()) 
                    dp[i][j] = (c == t[i]) * 2;
                else
                    dp[i][j] = 2;
            }
			if (i >= t.length() || c == t[i]) (dp[i][j] += dp[i + 1][j]) %= mod;
			if (j >= t.length() || c == t[j]) (dp[i][j] += dp[i][j - 1]) %= mod;
        }
    }
    int ans = 0;
	for (int i = t.length() - 1; i < s.length(); i++) (ans += dp[0][i]) %= mod;
	cout << ans << endl;
}