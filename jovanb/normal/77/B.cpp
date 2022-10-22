#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    ll a, b;
    cin >> a >> b;
    if(a == 0 && b == 0){cout << "1\n"; return;}
    if(b == 0){cout << "1\n"; return;}
    if(a == 0){cout << "0.5000000\n"; return;}
    if(a <= 4*b){
        ld t1 = a;
        t1 /= 4;
        ld p1 = a*b+(t1*a)/2;
        cout << p1/(2*a*b) << "\n";
        return;
    }
    ld t1 = 4*b;
    ld p1 = 2*a*b-(b*t1)/2;
    cout << p1/(2*a*b) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}