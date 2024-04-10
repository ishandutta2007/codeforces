#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll l, r;
    cin >> l >> r;
    cout << "YES\n";
    for(ll i=l; i<=r; i+=2){
        cout << i << " " << i+1 << "\n";
    }
    return 0;
}