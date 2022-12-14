#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> dp(1 << n);
    vector<int> idx = dp;
    string ss = s;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = (1 << n) - (1 << (i + 1)); (j - ((1 << n) - (1 << (i + 1)))) < (1 << i); ++j){
            idx[j] = ++cnt;
            ss[idx[j]] = s[j];
        }
    }
    for(int i = 0; i < (1 << n) - 1; ++i){
        if(i < (1 << (n - 1))) dp[idx[i]] = (s[i] == '?' ? 2 : 1);
        else{
            if(s[i] == '?') dp[idx[i]] = dp[idx[i] * 2] + dp[idx[i] * 2 + 1];
            else if(s[i] == '0') dp[idx[i]] = dp[idx[i] * 2];
            else dp[idx[i]] = dp[idx[i] * 2 + 1];
        }
    }
    int q; cin >> q;
    while(q--){
        int num; char c; cin >> num >> c; --num;
        num = idx[num]; ss[num] = c;
        while(num >= 1){
            if(num >= (1 << (n - 1))) dp[num] = (ss[num] == '?' ? 2 : 1);
            else{
                if(ss[num] == '?') dp[num] = dp[num * 2] + dp[num * 2 + 1];
                else if(ss[num] == '0') dp[num] = dp[num * 2];
                else dp[num] = dp[num * 2 + 1];
            }
            num >>= 1;
        }
        cout << dp[1] << '\n';
    }
    return 0;
}