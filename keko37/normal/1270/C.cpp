#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint t, n;
llint a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        llint s = 0, x = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            x ^= a[i];
        }
        cout << 2 << '\n';
        cout << x << " " << s + x << '\n';
    }
    return 0;
}