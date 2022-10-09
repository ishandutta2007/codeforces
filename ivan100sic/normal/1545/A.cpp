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
        valarray<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        slice se(0, (n+1)/2, 2);
        slice so(1, n/2, 2);

        valarray<int> b = a[se];
        valarray<int> c = a[so];

        sort(begin(b), end(b));
        sort(begin(c), end(c));

        a[se] = b;
        a[so] = c;

        cout << (is_sorted(begin(a), end(a)) ? "YES\n" : "NO\n");
    }
}