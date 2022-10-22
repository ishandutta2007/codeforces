#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

int n;

ll dp[1005][1005];
int niz[1005];

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return (1LL * a * b)%MOD;
}

int resi(int l, int r){
    if(r <= l) return dp[l][r] = 1;
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    int mn = n;
    for(int i=l; i<=r; i++){
        mn = min(mn, niz[i]);
    }
    int ind = 0;
    for(int i=l; i<=r; i++){
        if(mn == niz[i]) ind = i;
    }
    ll sum = 0;
    for(int l1=ind; l1>=l; l1--){
        sum = add(sum, mul(resi(l, l1-1), resi(l1, ind-1)));
    }
    for(int r1=ind; r1<=r; r1++){
        dp[l][r] = add(dp[l][r], mul(mul(sum, resi(ind+1, r1)), resi(r1+1, r)));
        /*if(ind == 1) cout << mul(mul(mul(resi(l, l1-1), resi(l1, ind-1)), resi(ind+1, r1)), resi(r1+1, r)) << " " << l1 << " " << r1 << endl;
        if(ind == 1) cout << dp[l][r] << "\n";*/
    }
    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    cout << resi(1, n);
    return 0;
}