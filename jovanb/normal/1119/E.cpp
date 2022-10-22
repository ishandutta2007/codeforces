#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll res = 0, tren = 0;
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        ll a = min(x/2, tren);
        x -= 2*a;
        tren -= a;
        res += a;
        res += x/3;
        x %= 3;
        tren += x;
    }
    cout << res;
    return 0;
}