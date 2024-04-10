#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int MOD;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int dp[505][25005];
int pref[505][25005];

int factpos[505];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n >> MOD;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int k=0; k<i; k++){
            for(int j=k; j<=n*n; j++){
                dp[i][j] = add(dp[i][j], dp[i-1][j-k]);
            }
        }
    }
    int res = 0;
    factpos[0] = 1;
    for(int i=n; i>=1; i--){
        factpos[n-i+1] = mul(factpos[n-i], i);
    }
    for(int i=0; i<=n; i++){
        pref[i][0] = dp[i][0];
        for(int j=1; j<n*n; j++){
            pref[i][j] = add(dp[i][j], pref[i][j-1]);
        }
    }
    for(int dele=0; dele<n-1; dele++){
        int sum = 0;
        int ost = n - dele;
        for(int p=1; p<=ost; p++){
            for(int d=p+1; d<=ost; d++){
                for(int invp=0; invp<=n*n; invp++){
                    /// na dp[ost-1][invp] nacina p ima (p-1) + invp relevantnih inverzija
                    /// manje jednako toliko d ima na pref[ost-1][(p-1)+invp-(d-1)] nacina
                    /*if(dele == 1 && dp[ost-1][invp] && pref[ost-1][(p-1)+invp-(d-1)]){
                        cout << p << " " << d << " " << invp << endl;
                    }*/
                    if((p-1)+invp-(d-1)-1 >= 0) sum = add(sum, mul(dp[ost-1][invp], pref[ost-1][(p-1)+invp-(d-1)-1]));
                }
            }
        }
        sum = mul(sum, factpos[dele]);
        res = add(res, sum);
    }
    cout << res << "\n";
    return 0;
}