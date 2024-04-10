#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[1000005][6];

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    string s;
    cin >> s;
    int n = s.size();
    for(int i=1; i<=n; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];
        dp[i][3] = dp[i-1][3];
        if(s[i-1] == 'v'){
            if(i >= 2 && s[i-2] == 'v'){
                dp[i][3] += dp[i-2][2];
                dp[i][1]++;
            }
        }
        else dp[i][2] += dp[i-1][1];
    }
    cout << dp[n][3];
    return 0;
}