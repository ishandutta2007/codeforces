#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300000;
const int MOD = 998244353;

int mul(int a, int b){ return (1LL*a*b)%MOD; }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

ll a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    reverse(a+1, a+1+n);
    for(int i=1; i<=n; i++) a[i] += a[i-1];
    int inv = pw(n, MOD - 2);
    for(int k=1; k<=n; k++){
        ll res = 0;
        for(int h=k+1; h<=n; h+=k){
            res += a[n] - a[h - 1];
        }
        res %= MOD;
        res = mul(res, inv);
        cout << res << " ";
    }
    cout << "\n";
    return 0;
}