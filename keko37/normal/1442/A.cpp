#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 30005;

llint t, n;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        llint x = a[0], y = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                y += a[i] - a[i - 1];
            } else {
                x += a[i] - a[i - 1];
            }
        }
        if (x >= 0) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}