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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        vector<pair<int, int>> all;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            all.push_back({a[i], i});
        }
        sort(all.begin(), all.end());
        int now1 = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0 || all[i].first != all[i - 1].first) {
                a[all[i].second] = now1++;
            } else {
                a[all[i].second] = now1 - 1;
            }
        }
        vi fir(now1);
        for(int i = n - 1; i >= 0; i--) {
            fir[a[i]] = i;
        }
        vi sec(now1);
        for(int i = 0; i < n; i++) {
            sec[a[i]] = i;
        }
        vi now(now1, -1);
        vvi dp(n, vi(2, 1)); // 0 -  
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(now[a[i]] != -1) {
                dp[i][0] = dp[now[a[i]]][0] + 1;
                dp[i][1] = dp[now[a[i]]][1] + 1;
            }
            if(a[i] != 0 && now[a[i] - 1] != -1 && fir[a[i]] == i) {
                if(sec[a[i] - 1] == now[a[i] - 1]) {
                    dp[i][0] = max(dp[i][0], dp[now[a[i] - 1]][0] + 1);
                } else {
                    dp[i][0] = max(dp[i][0], dp[now[a[i] - 1]][1] + 1);
                }
            }
            now[a[i]] = i;
            //cout << dp[i][0] << ' ' << dp[i][1] << endl;
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        vi amount(now1, 0);
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] < now1 - 1 && sec[a[i]] == i) {
                res = max(res, amount[a[i] + 1] + dp[i][0]);
            }
            if(a[i] < now1 - 1) {
                res = max(res, amount[a[i] + 1] + dp[i][1]);
            }
            ++amount[a[i]];
        }
        cout << n - res << '\n';
    }
}