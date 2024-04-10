#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll k, n, s, p;
    cin >> k >> n >> s >> p;
    ll x = n/s;
    if(n%s != 0) x++;
    x *= k;
    ll r = x/p;
    if(x%p != 0) r++;
    cout << r;
    return 0;
}