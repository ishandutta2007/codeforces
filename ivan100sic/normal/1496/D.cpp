// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[100005], l[100005], r[100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for (int i=2; i<=n; i++) {
        l[i] = a[i] > a[i-1] ? l[i-1] + 1 : 0;
    }

    for (int i=n-1; i>=1; i--) {
        r[i] = a[i] > a[i+1] ? r[i+1] + 1 : 0;
    }

    int lh = max_element(l+1, l+n+1) - l;
    int rh = max_element(r+1, r+n+1) - r;

    int w = max(l[lh], r[rh]);

    int cw = 0, ci = -1;
    for (int i=1; i<=n; i++) {
        if (max(l[i], r[i]) == w) cw++, ci = i;
    }

    if (cw > 1) {
        cout << "0\n";
    } else if (w % 2 == 0 && l[ci] == w && r[ci] == w) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
}