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
        ll k;
        cin >> n >> k;
        if (n < 62 && k > (1ll << (n - 1))) {
            cout << "-1\n";
            continue;
        }

        vector<int> a(n);
        for (int i=0; i<n; i++) {
            a[i] = n-i;
        }

        bitset<200000> b(k-1);
        
        for (int i=0; i<n-1; i++) {
            if (b[i] == 1) {
                int j = i;
                while (j+1 < n-1 && b[j+1] == 1) {
                    j++;
                }
                reverse(a.begin()+i, a.begin()+j+2);
                i = j;
            }
        }

        reverse(begin(a), end(a));
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}