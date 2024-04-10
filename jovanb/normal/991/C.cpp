#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll n;

bool checc(ll k){
    ll d = n;
    ll e1=0;
    ll e2=0;
    while(d > 0){
        if(d <= k){e1 += d; break;}
        e1 += k;
        d -= k;
        ll i2 = d/10;
        d -= i2;
        e2 += i2;
    }
    if(e1 >= e2) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    ll l=1, r=n;
    ll minres=n;
    while(l <= r){
        ll mid = (l+r)/2;
        if(checc(mid)){r = mid-1; minres = min(minres, mid);}
        else l = mid+1;
    }
    cout << minres;
    return 0;
}