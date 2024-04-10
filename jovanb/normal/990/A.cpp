#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll n, m;
    cin >> n >> m;
    ll a, b;
    cin >> a >> b;
    if(n%m == 0){cout << 0; return 0;}
    ll veci = n+m-(n%m);
    ll manji = n-(n%m);
    cout << min((veci-n)*a, (n-manji)*b);
    return 0;
}