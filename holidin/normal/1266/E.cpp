#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 6e5 + 1;

map <pair<int, int>, int> m;
int d[N];
int cnt[N];

void solve() {
    int i, j, k, n, t, a, b, c, sum = 0;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> d[i];
        sum += d[i];
    }
    cin >> k;
    for (i = 0; i < k; ++i) {
        cin >> a >> b >> c;
        if (m[{a, b}] != 0) {
            --cnt[m[{a, b}]];
            if (cnt[m[{a, b}]] < d[m[{a, b}]])
                ++sum;
            m[{a, b}] = 0;
        }
        m[{a, b}] = c;
        if (c != 0) {
            ++cnt[m[{a, b}]];
            if (cnt[m[{a, b}]] <= d[m[{a, b}]])
                --sum;
        }
        cout << sum << "\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();
}