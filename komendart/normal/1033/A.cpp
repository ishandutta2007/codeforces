#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    int ax, ay;
    int bx, by;
    int cx, cy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    if ((bx > ax) ^ (cx > ax)) {
        cout << "NO\n";
    } else if ((by > ay) ^ (cy > ay)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}