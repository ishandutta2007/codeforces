#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    ll a, b;
    cin >> n >> a >> b;
    ll g = a*b;
    while(n--){
        ll x;
        cin >> x;
        ll l=0, r=x, res=0;
        while(l <= r){
            ll mid = (l+r)/2;
            ll t1 = b*mid;
            ll t2 = a*(x-mid);
            if(t1 <= t2+a){
                res = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        ll t1 = b*res;
        ll t2 = a*(x-res);
        if(t2 > t1) cout << "Vova\n";
        else if(t2+a == t1 || t2 == t1) cout << "Both\n";
        else cout << "Vanya\n";
    }
    return 0;
}