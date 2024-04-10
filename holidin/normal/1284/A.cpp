#include <bits/stdc++.h>
using namespace std;
const int N = 30;

string s[N], t[N];

void solve() {
    int i, j, k, n, m, q;
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        cin >> s[i];
    for (j = 0; j < m; ++j)
        cin >> t[j];
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> j;
        --j;
        cout << s[j % n] + t[j % m] << "\n";

    }

}

int main() {
    #ifdef local
        freopen("input.txt", "r", stdin);

    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}