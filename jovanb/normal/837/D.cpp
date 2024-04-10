#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int br2[205];
int br5[205];
int dp[205][7005];
int dpp[205][7005];

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int n, k;
    ll x;
    cin >> n >> k;
    ll moze=0;
    for(int i=1; i<=n; i++){
        cin >> x;
        while(x % 2 == 0){
            br2[i]++;
            x /= 2;
        }
        while(x % 5 == 0){
            br5[i]++;
            x /= 5;
            moze++;
        }
    }
    for(int j=0; j<=k; j++){
        for(int x=0; x<=3600; x++){
            dpp[j][x] = -1000000000;
            dp[j][x] = -1000000000;
        }
    }
    dpp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=min(k, i); j++){
            for(int x=0; x<=6000; x++){
                dp[j+1][x+br5[i]] = max(dp[j+1][x+br5[i]], dpp[j][x]+br2[i]);
                dp[j][x] = max(dp[j][x], dpp[j][x]);
            }
        }
        for(int j=0; j<=min(k, i)+1; j++){
            for(int x=0; x<=6000; x++){
                dpp[j][x] = dp[j][x];
            }
        }
    }
    int maxans = 0;
    for(int i=0; i<=moze; i++){
        maxans = max(maxans, min(i, dp[k][i]));
    }
    cout << maxans;
    return 0;
}