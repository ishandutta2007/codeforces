#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
    //long long dp[505][505][505]; //, , 
    //long long dpsum[505][505][505];
    const long long mod = 998244353;
    long long dpprevi[505][505];
    long long dpprevsum[505][505];
    long long dpnext[505][505];
    long long dpnextsum[505][505];
int main() {
    //cout.precision(10);
    long long n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dpprevi[i][j] = 0;
            dpprevsum[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        dpprevi[i][1] = 1;
    }
    for(int i = 1; i <= n; i++){
        dpprevsum[i][1] = 1;
        for(int k = 2; k <= n; k++){
            dpprevsum[i][k] = dpprevsum[i][1];
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dpnext[j][1] = (dpprevsum[j][j] % mod);
            dpnextsum[j][1] = (dpnext[j][1] % mod);
            for(int k = 2; k <= n; k++){
                dpnext[j][k] = dpprevi[j][k - 1];
                //if(dp[i][j][k] < 0) return 0;
                dpnextsum[j][k] = (dpnextsum[j][k - 1] + dpnext[j][k]) % mod;
            }
        }
        swap(dpprevi, dpnext);
        swap(dpprevsum, dpnextsum);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //cout << dpsum[i][j][j] << endl;
        }
    }
    dpprevsum[0][0] = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i * j >= k){
                continue;
            }
            //cout << (dpsum[n][i][i] - dpsum[n][i - 1][i - 1]) * (dpsum[n][j][j] - dpsum[n][j - 1][j - 1]) << endl;
            long long a = dpprevsum[i][i] - dpprevsum[i - 1][i - 1];
            if(a < 0){
                a += mod;
            }
            long long b = dpprevsum[j][j] - dpprevsum[j - 1][j - 1];
            if(b < 0){
                b += mod;
            }
            ans += 2 * a * b;
            ans = ans % mod;
        }
    }
    cout << ans << endl;
    return 0;
}