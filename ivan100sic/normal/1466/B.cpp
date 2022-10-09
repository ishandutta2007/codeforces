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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }

        for (int i=0; i<n; i++) {
            if (i && a[i-1] >= a[i]) {
                a[i]++;
            }
        }

        cout << set(begin(a), end(a)).size() << '\n';
    }
}