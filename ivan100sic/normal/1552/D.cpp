// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, f;
int a[10];

void rek(int i, int t, int z) {
    if (i == n) {
        if (z == 0 && t > 0) f = 1;
        return;
    }

    rek(i+1, t, z);
    rek(i+1, t + 1, z + a[i]);
    rek(i+1, t + 1, z - a[i]);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        f = 0;
        rek(0, 0, 0);
        cout << (f ? "YES\n" : "NO\n");
    }
}