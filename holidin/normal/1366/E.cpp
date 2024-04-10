#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 12;
const int inf = 2e9;
const int mod = 998244353;
const int tmod = 2 * mod;
const int maxN = 2e7 + 1;

int a[N], b[N], sfmin[N];
int sum[N];

map<int, int> lst;

void run() {
    int n, x, m, i, j;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    sfmin[n + 1] = inf;
    for (i = n; i >= 1; --i) {
        sfmin[i] = min(sfmin[i + 1], a[i]);
    }
    int l = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        if (lst.count(b[i]) == 0) {
            cout << 0;
            return;
        }
        //cout << b[i] << ' ' << need2[b[i]] << endl;
    }
    b[0] = 0;
    sum[0] = 1;
    l = 1;
    if (sfmin[1] < b[1]) {
        cout << 0;
        return;
    }
    for (i = 1; i <= m; ++i) {
        while (l <= n && (i == m || l < lst[b[i + 1]])) {
            if ((i == m && l == n) || (i < m && sfmin[l + 1] == b[i + 1]))
                sum[i] = (sum[i] + sum[i - 1]) % mod;
            ++l;
        }
    }
    cout << sum[m];
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    run();
}