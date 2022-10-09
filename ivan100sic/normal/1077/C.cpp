#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i=0; i<n; i++)
                cin >> a[i];
        b[0] = a[0];
        for (int i=1; i<n; i++)
                b[i] = max(b[i-1], a[i]);
        c[n-1] = a[n-1];
        for (int i=n-2; i>=0; i--)
                c[i] = max(c[i+1], a[i]);
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        basic_string<int> z;
        for (int i=0; i<n; i++) {
                int mx = 0;
                if (i > 0) mx = max(mx, b[i-1]);
                if (i < n-1) mx = max(mx, c[i+1]);
                if (sum - a[i] == 2 * mx)
                        z += i+1;
        }
        cout << z.size() << '\n';
        for (int x : z)
                cout << x << ' ';
        cout << '\n';
}