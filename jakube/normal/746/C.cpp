#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int s, x1, x2, t1, t2;
    cin >> s >> x1 >> x2 >> t1 >> t2;
    int p, d;
    cin >> p >> d;

    int best = abs(x1 - x2) * t2;

    // wait
    int other = 0;

    if (x1 > x2) {
        x1 = s - x1;
        x2 = s - x2;
        p = s - p;
        d = -d;
    }
    
    if (d == 1) {
        if (p <= x1) {
            other = (x2 - p) * t1;
        } else {
            other = (s - p + s + x2) * t1; 
        }
    } else {
        other = (p + x2) * t1;
    }

    cout << min(best, other) << endl;
    return 0;
}