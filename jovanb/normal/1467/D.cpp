#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b){
    return add(a, MOD-b);
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int ways[5005][5005];
int val[5005];
int poj[5005];

int res;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k, q;
    cin >> n >> k >> q;
    for(int i=1; i<=n; i++){
        cin >> val[i];
    }
    for(int i=1; i<=n; i++) ways[0][i] = 1;
    for(int j=1; j<=k; j++){
        for(int i=1; i<=n; i++){
            ways[j][i] = add(ways[j-1][i-1], ways[j-1][i+1]);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            poj[i] = add(poj[i], mul(ways[j][i], ways[k-j][i]));
        }
    }
    for(int i=1; i<=n; i++) res = add(res, mul(poj[i], val[i]));
    while(q--){
        int l, r;
        cin >> l >> r;
        res = sub(res, mul(poj[l], val[l]));
        val[l] = r;
        res = add(res, mul(poj[l], val[l]));
        cout << res << "\n";
    }
    return 0;
}