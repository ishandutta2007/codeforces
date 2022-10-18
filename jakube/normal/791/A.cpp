#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long a, b;
    cin >> a >> b;
    
    for (int i = 0; i < 100; i++) {
        a *= 3;
        b *= 2;
        if (a > b) {
            cout << i + 1 << endl;
            return 0;
        }

    }

    return 0;
}