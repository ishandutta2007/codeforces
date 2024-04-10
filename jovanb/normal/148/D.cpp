#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld dp[1005][1005][2];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int x, y;
    cin >> x >> y;
    ld res = 0;
    dp[x][y][1] = 1;
    for(int w=x; w>=0; w--){
        for(int b=y; b>=0; b--){
            if(w > 0 || b > 0) res += dp[w][b][1] * w / (w+b);
            if(b > 0) dp[w][b-1][0] += dp[w][b][1] * b / (w+b);
            if(w > 0 && b > 0) dp[w-1][b-1][1] += dp[w][b][0] * b / (w+b) * w / (w+b-1);
            if(b > 1) dp[w][b-2][1] += dp[w][b][0] * b / (w+b) * (b-1) / (w+b-1);
        }
    }
    cout << res;
    return 0;
}