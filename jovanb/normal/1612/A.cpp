#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int d = x + y;
        if(d%2){
            cout << "-1 -1\n";
            continue;
        }
        d /= 2;
        if(d <= x) cout << d << " " << 0 << "\n";
        else cout << x << " " << d-x << "\n";
    }
    return 0;
}