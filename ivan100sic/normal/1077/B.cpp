#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, z=0;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
                cin >> a[i];
        for (int i=0; i<n; i++) {
                if (i > 0 && i < n-1 && a[i-1] && a[i+1] && !a[i]) {
                        z++;
                        a[i+1] = 0;
                }
        }
        cout << z << '\n';
}