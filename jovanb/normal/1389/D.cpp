#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll intersect(int l1, int r1, int l2, int r2){
    return max(0, min(r1, r2) - max(l1, l2));
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll l1, r1;
    cin >> l1 >> r1;
    ll l2, r2;
    cin >> l2 >> r2;
    if(l1 > l2){
        swap(l1, l2);
        swap(r1, r2);
    }
    k -= n*intersect(l1, r1, l2, r2);
    if(k <= 0){
        cout << "0\n";
        return;
    }
    ll treba = max(0LL, l2 - r1);
    r1 = max(r1, l2);
    ll jos = abs(l1 - l2) + abs(r1 - r2);
    ll res = 20000000000LL;
    for(int i=1; i<=n; i++){
        ll moves = treba*i;
        if(jos*i >= k){
            moves += k;
            res = min(res, moves);
            continue;
        }
        ll g = k - jos*i;
        moves += jos*i;
        moves += 2*g;
        res = min(res, moves);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}