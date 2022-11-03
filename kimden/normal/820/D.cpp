#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;

inline ll myabs(ll x){
    return (x > 0 ? x : -x);
}
vector<ll> derv;

int main() {
    ll n;
    cin >> n;
    derv.resize(n, 0);
    vector<ll> p(n);
    ll cur = 0;
    for(ll i = 0; i < n; ++i){
        cin >> p[i];
        --p[i];
        cur += myabs(p[i] - i);
    }
    vector<pii> events;
    for(ll i = 0; i < n; ++i){
        if(p[i] == 0){
            derv[(p[i] - i + n) % n] += n;
            derv[(n + n - 1 - i) % n] +=  -n;
//            derv[(n - i) % n, -1 - myabs(p[i]) + myabs(p[i] - n - 1)});
        }else {
            if(p[i] == n - 1){
                derv[(p[i] - i + n) % n] += n;
//                derv[(n + n - 1 - i) % n, -n});
                derv[(n - i) % n] += -n;
            }else {
                derv[(p[i] - i + n) % n] += 2;
                derv[(n + n - 1 - i) % n] += myabs(p[i]) - myabs(p[i] - n + 1) - 1;
                derv[(n - i) % n] += -1 - myabs(p[i]) + myabs(p[i] - n + 1);
            }
        }
    }

    ll deriv = 0;
    for(int i = 0; i < n; ++i){
        if(p[i] == 0){
            if(i == n - 1){
                deriv += 1 - n;
            }else{
                deriv += 1;
            }
        }else{
            if(p[i] == n - 1){
                if(i == n - 1){
                    deriv += n - 1;
                }else{
                    deriv -= 1;
                }
            }else{
                if(i == n - 1){
                    deriv += myabs(p[i]) - myabs(p[i] - n + 1);
                }else {
                    deriv += (p[i] > i ? -1 : 1);
                }
            }
        }
    }
    ll res = cur;
    ll mn = cur;
    ll ans = 0;
    for(int i = 0; i <= n; ++i){
        if(i) {
            res += deriv;
        }
        if(i) {
            deriv += derv[i];
        }else{
        }
        if(i < n) {
            if (mn > res) {
                mn = res;
                ans = i;
            }
        }
    }
    cout << mn << " " << ans << endl;

    return 0;
}