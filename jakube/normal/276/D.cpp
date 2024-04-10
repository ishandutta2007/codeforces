#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long l, r;
    cin >> l >> r;
    
    auto test = [&](long long a, long long b) {
        return l <= a && a <= b && b <= r;
    };

    long long a = 0, b = 0;
    for (int i = 62; i >= 0; i--) {
        if (test((1LL<<i) - 1, 1LL<<i)) {
            cout << (1LL << (i+1)) - 1 << endl;
            return 0;
        }
        l %= (1LL << i);
        r %= (1LL << i);
    }

    cout << 0 << endl;

    return 0;
}