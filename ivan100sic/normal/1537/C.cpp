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

        sort(begin(a), end(a));
        
        if (n > 2) {
            int lo = 2e9, id = -1;
            for (int i=0; i<n-1; i++) {
                if (a[i+1] - a[i] < lo) {
                    lo = a[i+1] - a[i];
                    id = i;
                }
            }
            rotate(begin(a), begin(a) + id + 1, end(a));
        }

        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}