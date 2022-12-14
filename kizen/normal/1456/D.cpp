#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e18 + 7;
const LL NS = (LL)5004;
LL N;
pair<LL, LL> a[NS];
LL dp[NS][NS], mn[NS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(LL i = 1; i <= N; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + N + 1);
    for(LL j = 0; j <= N; ++j){
        mn[j] = MOD;
        if(a[j].second == 0){
            dp[0][j] = 1;
        }
    }
    mn[0] = 0;
    for(LL i = 0; i < N; ++i){
        if(max(mn[i] + abs(a[i].second - a[i + 1].second), a[i].first) <= a[i + 1].first){
            mn[i + 1] = min(mn[i + 1], max(mn[i] + abs(a[i].second - a[i + 1].second), a[i].first));
        }
        for(LL j = 0; j <= N; ++j){
            if(max(mn[i] + abs(a[i].second - a[j].second), a[i].first) + abs(a[j].second - a[i + 1].second) <= a[i + 1].first){
                dp[i + 1][j] = 1;
            }
            if(dp[i][j]){
                if(j != i + 1){
                    if(a[i].first + abs(a[i].second - a[i + 1].second) <= a[i + 1].first){
                        dp[i + 1][j] = 1;
                    }
                }
            }
        }
        if(dp[i][i + 1]){
            if(max(a[i].first + abs(a[i].second - a[i + 2].second), a[i + 1].first) <= a[i + 2].first){
                mn[i + 2] = min(mn[i + 2], max(a[i].first + abs(a[i].second - a[i + 2].second), a[i + 1].first));
            }
            for(LL j = 0; j <= N; ++j){
                if(max(a[i].first + abs(a[i].second - a[j].second), a[i + 1].first) + abs(a[j].second - a[i + 2].second) <= a[i + 2].first){
                    dp[i + 2][j] = 1;
                }
            }
        }
    }
    if(mn[N] <= a[N].first || dp[N - 1][N]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}