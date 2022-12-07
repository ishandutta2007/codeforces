#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n;
    cin >> n;
    vector<int> a(n + n);
    vector<vector<int>> where(n);
    for (int i = 0; i < n + n; ++i) {
        int x; scanf("%d", &x);
        --x;
        a[i] = x;
        where[x].push_back(i);
    }
    ll ans = where[0][0] + where[0][1];
    for (int pos = 1; pos < n; ++pos) {
        ll px = where[pos - 1][0], py = where[pos - 1][1];
        ll nx = where[pos][0], ny = where[pos][1];
        ans += min(labs(px - nx) + labs(py - ny), labs(px - ny) + labs(py - nx));
    }
    cout << ans << endl;

    return 0;
}