#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll v1x = x2-x1;
    ll v1y = y2-y1;
    ll v2x = x3-x2;
    ll v2y = y3-y2;
    ll g = v1x*v2y - v1y*v2x;
    if(g < 0){
        cout << "RIGHT";
    }
    if(g == 0){
        cout << "TOWARDS";
    }
    if(g > 0){
        cout << "LEFT";
    }
    return 0;
}