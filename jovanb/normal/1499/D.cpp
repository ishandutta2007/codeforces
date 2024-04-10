#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAX = 20000000;

short divs[MAX+5];
bool np[MAX+5];

ll uradi(ll nzd, ll c, ll d, ll x){
    ll k = x + d*nzd;
    if(k%c) return 0;
    ll nzs = k/c;
    if(nzs%nzd) return 0;
    nzs /= nzd;
    return (1LL << (divs[nzs]));
}

void solve(){
    ll c, d, x;
    cin >> c >> d >> x;
    ll res = 0;
    for(int i=1; i*i<=x; i++){
        if(x%i) continue;
        res += uradi(i, c, d, x);
        if(i != x/i) res += uradi(x/i, c, d, x);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=2; i<=MAX; i++){
        if(!np[i]){
            divs[i] = 1;
            for(int j=2*i; j<=MAX; j+=i){
                np[j] = 1;
                divs[j]++;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}