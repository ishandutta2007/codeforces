#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x, y, c;

ll resi(ll a, ll b){
    a = min(a, b);
    if(a <= 0) return 0;
    return a*(a+1)/2;
}

bool check(ll k){
    ll sum = k*k + (k-1)*(k-1);
    ll pr;
    /// levo
    pr = k-x;
    if(pr >= 0) sum -= pr*pr;
    /// desno
    pr = n-x+1;
    pr = k-pr;
    if(pr >= 0) sum -= pr*pr;
    /// gore
    pr = k-y;
    if(pr >= 0) sum -= pr*pr;
    /// dole
    pr = n-y+1;
    pr = k-pr;
    if(pr >= 0) sum -= pr*pr;

    ll gore = k-y;
    ll dole = k-(n-y+1);
    ll levo = k-x;
    ll desno = k-(n-x+1);
    sum += resi(gore-x, levo-y);
    sum += resi(gore-(n-x+1), desno-y);
    sum += resi(dole-x, levo-(n-y+1));
    sum += resi(dole-(n-x+1), desno-(n-y+1));
    return sum >= c;
}

int main(){

    cin >> n >> x >> y >> c;
    ll l = 1, r = 2*n, res = 2*n;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid)){
            r = mid-1;
            res = mid;
        }
        else l = mid+1;
    }
    cout << res-1;
    return 0;
}