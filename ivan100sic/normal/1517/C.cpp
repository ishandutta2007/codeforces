// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[505][505];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i][i];

    for (int d=0; d<n; d++) {
        int lo = 1 + d;
        for (int i=2+d; i<=n; i++) {
            if (a[i][i-d] < a[lo][lo-d]) {
                lo = i;
            }
        }

        for (int i=1+d; i<lo; i++) {
            a[i+1][i-d] = a[i][i-d];
        }

        for (int i=lo+1; i<=n; i++) {
            a[i][i-d-1] = a[i][i-d];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cout << a[i][j] << " \n"[j == i];
        }
    }
}