#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0, mn = 1e9, mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != i) {
                cnt++;
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        if (cnt == 0) {
            cout << 0 << '\n';
        } else if (mx - mn + 1 == cnt) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}