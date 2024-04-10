#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

void solve() {
    int n, a, b;
    cin >> a >> b;
    int x = abs(a - b);
    if (min(a, b) <= x) {
        cout << min(a, b) << endl;
        return;
    }
    if (a > b) swap(a, b);
    a -= x;
    b -= 2 * x;
    if (a % 3 < 2) {
        cout << x + (a / 3) * 2 << endl;
    }
    else cout << x + (a / 3) * 2 + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}