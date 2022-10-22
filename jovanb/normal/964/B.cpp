#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll a, b, c, T;
    cin >> a >> b >> c >> T;
    ll ukup=0;
    for(int i=0; i<n; i++){
        ll t;
        cin >> t;
        if(c <= b) ukup += a;
        else {
            ll kolko = T-t;
            ukup += (c-b)*kolko+a;
        }
    }
    cout << ukup;
    return 0;
}