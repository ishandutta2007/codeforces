#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int x, y;
    cin >> x >> y;
    
    int a = y;
    int b = y;
    int c = y;
    // Invariant: a < b < c

    int cnt = 0;
    while (a != x) {
        int A = a;
        int B = b;
        int C = c;
        c = C + B - 1;
        if (c > x) c = x;
        b = C;
        a = B;
        cnt++;
        // cout << cnt << ": (" << a << ", " << b << ", " << c << ")" << endl;
    }

    cout << cnt << endl;

    return 0;
}