#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int dp[100002];

int main() {
    ios_base::sync_with_stdio(false);
    int n, q, l, r;
    string s;
    cin >> s;
    n = s.length();
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1];
        if(s[i - 1] == s[i]){
            dp[i]++;
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        cout << dp[r - 1] - dp[l - 1] << endl;
    }
    return 0;
}