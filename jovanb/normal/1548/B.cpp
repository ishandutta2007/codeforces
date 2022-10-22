#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;
const int LOG = 20;

ll a[N+5];
ll f[N+5][LOG+1];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){

    }
    for(int j=1; j<=LOG; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            f[i][j] = __gcd(__gcd(f[i][j-1], f[i+(1<<(j-1))][j-1]), abs(a[i] - a[i + (1<<(j-1))]));
        }
    }
    int res = 1;
    for(int i=1; i<=n; i++){
        int x = i;
        ll tg = 0;
        for(int j=LOG; j>=0; j--){
            if(x + (1<<j) > n) continue;
            ll novi = __gcd(tg, __gcd(f[x+1][j], abs(a[i] - a[x+1])));
            if(novi != 1){
                tg = novi;
                x += (1<<j);
            }
        }
        res = max(res, x - i + 1);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
5
1 5 2 4 6
*/