#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 12;
const int inf = 2e9;
const int mod = 1e9 + 7;

int l[N], r[N];
void run() {
    int n, x, m;
    cin >> n >> x >> m;
    int li = x, ri = x;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        if (l[i] <= ri && r[i] >= li) {
            li = min(li, l[i]);
            ri = max(ri, r[i]);
        }
    }
    cout << ri - li + 1 << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
        run();
}