// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int w[100005], n = 100;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool b;
        if (n % 2) {
            b = true;
        } else {
            int q = n & (n - 1);
            if (q == 0) {
                b = __builtin_clz(n) % 2 == 0;
            } else {
                b = false;
            }
        }

        cout << (b ? "Bob\n" : "Alice\n");
    }
}