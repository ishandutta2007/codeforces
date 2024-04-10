#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[300005][3];
ll a[300005];
ll b[300005];

const ll INF = 1000000000000000000LL;

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=2; j++){
            dp[i][j] = INF;
        }
    }
    a[0] = -300;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
        for(int j=0; j<=2; j++){
            for(int k=0; k<=2; k++){
                if(a[i] + j != a[i-1] + k){
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + j*b[i]);
                }
            }
        }
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}