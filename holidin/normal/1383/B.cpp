#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 1;
const int LogN = 30;

int t[LogN];
int a[N];

void solve() {
    int i, j, k ,n, m;
    cin >> n;
    int xr = 0;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        xr ^= a[i];
    }
    if (xr == 0) {
        cout << "DRAW\n";
        return;
    }
    for (int i = LogN - 1; i >= 0; --i)
    if ((xr & t[i]) > 0) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        if ((a[j] & t[i]) > 0)
            ++cnt;
        if ((cnt / 2 + 1) % 2 || (n - cnt) % 2)
            cout << "WIN\n";
        else
            cout << "LOSE\n";
        break;
    }

}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    t[0] = 1;
    for (int i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
        solve();
}