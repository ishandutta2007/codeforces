#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[300005];
ll dpp[300005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int r, g;
    cin >> r >> g;
    if(r == 0 || g == 0){cout << "1"; return 0;}
    ll tren = 2;
    dpp[1] = 1;
    dpp[0] = 1;
    dp[1] = 1;
    dp[0] = 1;
    while(tren*(tren+1) <= 2*(r+g)){
        for(int i=0; i<=r; i++){
            dp[i] = 0;
            int ng = (tren+1)*tren/2-i;
            if(ng < 0) continue;
            if(ng > g) continue;
            if(i >= tren) dp[i] += dpp[i-tren];
            if(ng >= tren) dp[i] += dpp[i];
            dp[i] %= 1000000007;
        }
        for(int i=0; i<=r; i++) dpp[i] = dp[i];
        tren++;
    }
    ll sum=0;
    for(int i=0; i<=r; i++) sum += dp[i];
    sum %= 1000000007;
    cout << sum;
    return 0;
}