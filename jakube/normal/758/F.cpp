#include <bits/stdc++.h>
using namespace std;

int power(int a, int e) {
    int result = 1;
    while (e) {
        if (e & 1) {
            result = (result * a);
        }
        a = (a * a);
        e >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, l, r;
    cin >> n >> l >> r;
    
    if (n == 1) {
        cout << r - l + 1 << endl;
        return 0;
    }

    if (n == 2) {
        cout << (long long)(r - l + 1) * (long long)(r - l) << endl;
        return 0;
    }

    long long cnt = 0;
    int b = (int)(pow(r, 1.0 / (n - 1)) + .1);


    for (int y = 1; y <= b; y++) {
        for (int x = y + 1; x <= b; x++) {
            if (__gcd(x, y) == 1) {
                cnt += max(0, r / power(x, n-1) - (l - 1) / power(y, n-1));
            }
        }
    }

    cout << 2 * cnt << endl;

    return 0;
}