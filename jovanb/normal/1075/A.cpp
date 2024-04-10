#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    ll dis1 = max(x-1, y-1);
    ll dis2 = max(n-x, n-y);
    if(dis1 <= dis2) cout << "White";
    else cout << "Black";
    return 0;
}