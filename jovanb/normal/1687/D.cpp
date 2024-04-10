#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

int a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(ll t=1; ; t++){
        ll l = t*t - a[1];
        ll r = t*t + t - a[1];
        if(r < 0) continue;
        l = max(l, 0LL);
        int h = 1;
        for(ll i=t; ; i++){
            if(i*i > a[n] + l) break;
            /// i*i do i*i + i
            auto k = upper_bound(a+h, a+1+n, i*i + i - l) - a;
            k--;
            if(a[k] + l >= i*i){
                r = min(r, i*i + i - a[k]);
                h = k + 1;
            }
            k = lower_bound(a+h, a+1+n, i*i + i + 1 - l) - a;
            if(k <= n && a[k] + l <= (i+1)*(i+1)){
                l = max(l, (i+1)*(i+1) - a[k]);
                h = k + 1;
            }
        }
        if(l <= r){
            cout << l << "\n";
            return 0;
        }
    }
    return 0;
}