// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int xor_upto(int x) {
    switch (x % 4) {
        case 0: return x;
        case 1: return 1;
        case 2: return x^1;
        case 3: return 0;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int x = xor_upto(a-1);
        if (b == x) {
            cout << a << '\n';
        } else if ((b ^ x) != a) {
            cout << a+1 << '\n';
        } else {
            cout << a+2 << '\n';
        }
    }
}