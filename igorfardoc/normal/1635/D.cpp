#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, p;
    cin >> n >> p;
    vi dp(p + 1);
    dp[0] = 1;
    for(int i = 1; i <= p; i++) {
        dp[i] = dp[i - 1];
        if(i > 1) {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }
    for(int i = 1; i <= p; i++) {
        dp[i] = (dp[i - 1] + dp[i]) % mod;
    }
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    unordered_set<int> was;
    int ans = 0;
    //cout << dp[3] << endl;
    for(int i = 0; i < n; i++) {
        int here = a[i];
        bool ok = true;
        while(here > 0) {
            if(here & 1) {
                here >>= 1;
            } else {
                if((here & 3) != 0) break;
                here >>= 2;
            }
            if(was.find(here) != was.end()) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        was.insert(a[i]);
        int am = 0;
        for(int j = 0; j < 31; j++) {
            if((a[i] >> j) == 0) {
                am = j;
                break;
            }
        }
        if(p >= am) ans = (ans + dp[p - am]) % mod;
    }
    cout << ans;

}