#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    ll k, d, t;
    long double x;
    cin >> k >> d >> t;
    if(k%d == 0){cout << t; return 0;}
    t *= 2;
    ll seg = k+(d-k%d);
    ll g1, g2;
    g1 = k*2;
    g2 = seg-k;
    ll g = g1+g2;
    ll br = t/g;
    ll ost = t%g;
    ll vr = br*seg;
    if(ost <= g1){
        x = (long double)(ost)/2;
        cout << x+vr;
        return 0;
    }
    ost -= g1;
    cout << k+ost+vr;
    return 0;
}