#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[1005][11];
ll prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

const ll MAX = 1'000'000'000'000'000'000;

ll mul(ll a, ll b){
    if(MAX/b < a) return MAX;
    return a*b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=10; j++){
            dp[i][j] = MAX;
        }
    }
    dp[1][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++){
            for(int k=0; k<j; k++){
                ll xx=1;
                for(int x=0; x<=64; x++){
                    if(i % (x+1)){xx = mul(xx, prime[j]); continue;}
                    dp[i][j] = min(dp[i][j], mul(dp[i/(x+1)][k], xx));
                    xx = mul(xx, prime[j]);
                }
            }
        }
    }
    cout << dp[n][10];
    return 0;
}