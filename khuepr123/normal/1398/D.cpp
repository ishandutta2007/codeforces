#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define temp dp[rr][gg][bb]
 
const int maxn = 100005;
int r[203], g[203], b[203], dp[204][204][204];
 
int main(){
    ios_base::sync_with_stdio(0);
    ll R, G, B; cin >> R >> G >> B;
    for(ll i = 1; i <= R; i++){
        cin >> r[i];
    }
    for(ll i = 1; i <= G; i++){
        cin >> g[i];
    }
    for(ll i = 1; i <= B; i++){
        cin >> b[i];
    }
    sort(r + 1, r + R + 1);
    sort(g + 1, g + G + 1);
    sort(b + 1, b + B + 1);
    for(ll rr = 0; rr <= R; rr++){
        for(ll gg = 0; gg <= G; gg++){
            for(ll bb = 0; bb <= B; bb++){
                temp = 0;
                if(rr){
                    temp = max(temp, dp[rr - 1][gg][bb]);
                }
                if(gg){
                    temp = max(temp, dp[rr][gg - 1][bb]);
                }
                if(bb){
                    temp = max(temp, dp[rr][gg][bb - 1]);
                }
                if(rr&&gg){
                    temp = max(temp, dp[rr - 1][gg - 1][bb] + (r[rr] * g[gg]));
                }
                if(rr&&bb){
                    temp = max(temp, dp[rr - 1][gg][bb - 1] + (r[rr] * b[bb]));
                }
                if(bb&&gg){
                    temp = max(temp, dp[rr][gg - 1][bb - 1] + (b[bb] * g[gg]));
                }
                
            }
        }
    }
    cout << dp[R][G][B];
}