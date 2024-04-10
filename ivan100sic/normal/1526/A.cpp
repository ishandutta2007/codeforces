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
        vector<int> a(2*n);
        auto b = a;
        for(int& x : a) cin >> x;
        sort(begin(a), end(a));
        for (int i=0; i<n; i++) {
            b[2*i] = a[i];
        }
        for (int i=0; i<n; i++) {
            b[2*i+1] = a[i+n];
        }
        for (int x : b) cout << x << ' ';
        cout << '\n';
    }
}