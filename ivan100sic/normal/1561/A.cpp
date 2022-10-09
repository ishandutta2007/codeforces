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
        for (int& x : a) cin >> x;

        int c = 0;
        for (int i=0; !is_sorted(begin(a), end(a)); i++) {
            c++;
            for (int j=i%2; j+1<n; j+=2) {
                if (a[j] > a[j+1]) {
                    swap(a[j], a[j+1]);
                }
            }
        }

        cout << c << '\n';
    }
}