#include <bits/stdc++.h>
//#pragma GCC optimize 03
#define fi first
#define se second
#define int long long
#define ld long double
using namespace std;
const int N = 2e6 + 1;
int bad = 0;
int m[2][N];

int cnt_bad(int i, int j) {
    int ans = 0;
    if (m[i][j]) {
        if (m[1 - i][j])
            ++ans;
        if (j > 0 && m[1 - i][j - 1])
            ++ans;
        if (m[1 - i][j + 1])
            ++ans;
    }
    return ans;
}

void solve() {
    int i, j, k, n, q;
    cin >> n >> q;
    int cnt = 0;
    for (i = 0; i < q; ++i) {
        cin >> j >> k;
        --j;
        --k;
        if (m[j][k]) {
            cnt -= cnt_bad(j, k);
            m[j][k] = 0;
        } else {
            m[j][k] = 1;
            cnt += cnt_bad(j, k);
        }
        if (cnt == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}