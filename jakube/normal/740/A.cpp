#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    
    if (n % 4 == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n % 4 == 1) {
        cout << min(3*a, min(a+b, c)) << endl;
        return 0;
    }

    if (n % 4 == 2) {
        cout << min(2*a, min(b, 2*c)) << endl;
        return 0;
    }

    cout << min(a, min(b+c, c*3)) << endl;


    return 0;
}