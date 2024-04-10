// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        sort(begin(a), end(a));

        int t = 0, z = 0;
        for (int i=n-1; i>=0; i--) {
            if (t >= a[i]) {
                break;
            } else {
                z += 1;
                t += k - a[i];
            }
        }

        cout << z << '\n';
    }
}