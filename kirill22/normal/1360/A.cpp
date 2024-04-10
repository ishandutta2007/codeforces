#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(a) a.begin(), a.end()

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << max(2 * a, b) * max(2 * a, b) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}