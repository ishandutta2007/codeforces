#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 20;

int sol[(1<<N)];
int a[(1<<N)+5];
int dp[30][(1<<N)];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=0; i<=25; i++){
        if((n - 1) - i < 0) break;
        for(int j=(n-1)-i; j>=0; j--){
            dp[i][j] = dp[i][j+1] + ((((n-1)-i) & j) == j);
            dp[i][j] %= 2;
        }
    }
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int l=1; l<=n; l++){
        ll prod = a[l];
        for(int r=l; r<=n; r++){
            if(r != l){
                if(a[r] >= 20) break;
                prod *= (1 << a[r]);
            }
            if(prod >= (1 << 20)) break;
            int m = (n - 1);
            m -= (r - l);
            if(l > 1) m--;
            if(r < n) m--;
            int t = k;
            if(l > 1) t--;
            if(r < n) t--;
            t = max(0, t);
            if(m < t) continue;
            sol[prod] += dp[(n - 1) - m][t];
            sol[prod] %= 2;
        }
    }
    bool bilo = 0;
    for(int i=(1<<N)-1; i>=0; i--){
        sol[i] %= 2;
        if(sol[i]) bilo = 1;
        if(bilo) cout << sol[i];
    }
    if(!bilo) cout << "0";
    cout << "\n";
    return 0;
}