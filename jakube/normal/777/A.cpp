#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, x;
    cin >> n >> x;
    n %= 6;

    for (int i = n; i > 0; i--) {
        if (i % 2 == 0) {
            if (x == 1) x = 2;
            else if (x == 2) x = 1;
        } else {
            if (x == 0) x = 1;
            else if (x == 1) x = 0;
        }
    }

    cout << x << endl;

    return 0;
}