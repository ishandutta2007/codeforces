#include<bits/stdc++.h>

using namespace std;

#define int long long

bool f(int n) {
    int x = 1;
    while (x * 3 <= n) {
        x *= 3;
    }
    while (x) {
        if (n >= x) {
            n -= x;
        }
        x /= 3;
    }
    if (n == 0) {
        return true;
    }
    return false;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        while (true) {
            if (f(n)) {
                cout << n << endl;
                break;
            }
            n++;
        }
    }
}