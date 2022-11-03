#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ll n;
    ld a;
    cin >> n >> a;
    ld one = 180. / (ld)n;
    ld x = floorl(a / one);
    ld y = x + 1;
    ll cur;
    if(fabsl(x * one - a) < fabsl(y * one - a)){
        cur = (ll)x;
    }else{
        cur = (ll)y;
    }
    if(cur >= n - 2){
        cur = n - 2;
    }
    if(cur <= 0){
        cur = 1;
    }
    cout << "2 1 " << cur + 2 << endl;

    return 0;
}