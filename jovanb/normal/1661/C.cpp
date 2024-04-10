#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300000;

ll a[N+5];

bool check(int n, ll k, ll h){
    ll d = k/2;
    k -= d;
    for(int i=1; i<=n; i++){
        ll x = h - a[i];
        if(x >= d*2){
            x -= d*2;
            d = 0;
        }
        else{
            d -= x/2;
            x -= 2*(x/2);
        }
        if(x > k) return 0;
        k -= x;
    }
    return 1;
}

void solve(){
    int n;
    cin >> n;
    ll mx = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll l = 0, r = 1e15, res = 1e15;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(n, mid, mx)){
            res = min(res, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    l = 0, r = 1e15;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(n, mid, mx + 1)){
            res = min(res, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}