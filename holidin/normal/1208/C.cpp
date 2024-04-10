#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define uniq(x) x.resize(unique(x.begin(), x.end()) - x.begin())
using namespace std;
const int N = 2e3 + 52;

int a[N][N];

void solve() {
    int i, j, k,n, b;
    cin >> n;
    int top = -1;
    for (i = 0; i < n / 4; ++i)
    for (j = 0; j < n / 4; ++j) {
        for (int l = 0; l < 16; ++l)
            a[4 * i + l % 4][4 * j + l / 4] = ++top;
    }
    for (i = 0; i < n; ++i) {
        int x = 0;
        for (j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

signed main() {
    int i, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}