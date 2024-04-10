#include <bits/stdc++.h>
using namespace std;
const int N = 10000;

set <int> s1, s2;

int main() {
    int n, m, cl, ck, u, i, j, x1, x2, y1, y2, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> cl >> ck >> u;
    for (i = 0; i < cl; ++i) {
        cin >> j;
        s1.insert(j);
    }
    for (i = 0; i < ck; ++i) {
        cin >> j;
        s2.insert(j);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        int cnt = abs(x1 - x2), ans = 1e9;
        if (x1 == x2) {
            cout << abs(y1 - y2) << "\n";
            continue;
        }
        set <int> :: iterator it = s1.lower_bound(y1);
        if (it != s1.end())
            ans = min(ans, cnt + abs((*it) - y1) + abs((*it) - y2));
        if (it != s1.begin()) {
            --it;
            ans = min(ans, cnt + abs((*it) - y1) + abs((*it) - y2));
        }
        it = s2.lower_bound(y1);
        if (it != s2.end())
            ans = min(ans, (cnt - 1) / u + 1 + abs((*it) - y1) + abs((*it) - y2));
        if (it != s2.begin()) {
            --it;
            ans = min(ans, (cnt - 1) / u + 1 + abs((*it) - y1) + abs((*it) - y2));
        }
        cout << ans << "\n";
    }

}