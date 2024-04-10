#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ax, ay;
    cin >> ax >> ay;
    int bx, by;
    cin >> bx >> by;
    int cx, cy;
    cin >> cx >> cy;

    if (bx > cx) {
        swap(bx, cx);
        swap(by, cy);
    }

    if (bx < ax && ax < cx) {
        cout << "NO" << '\n';
        return 0;
    }

    if (by > cy) {
        swap(bx, cx);
        swap(by, cy);
    }

    if (by < ay && ay < cy) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    
}