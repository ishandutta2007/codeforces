#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2e5 + 1;
const int inf = 1e9 + 1;
mt19937 rnd(58);

int lk[N], lb[N], a[N], b[N], dp[N];
int top = 0;
long double bord[N];

void add_line(int k, int b) {
    ++top;
    lk[top] = k;
    lb[top] = b;
    while (top > 1 && lk[top - 1] * bord[top - 1] + lb[top - 1] > lk[top] * bord[top - 1] + lb[top]) {
        --top;
        lk[top] = lk[top + 1];
        lb[top] = lb[top + 1];
    }
    if (top == 1)
        bord[top] = -inf;
    else
        bord[top] = (lb[top] - lb[top - 1]) / (lk[top - 1] - lk[top]);
}

int get_res(int x) {
    int l = 1, r = top + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (bord[mid] > x)
            r = mid;
        else
            l = mid;
    }
    return lk[l] * x + lb[l];
}


void solve() {
    int i, j, k, n;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (j = 0; j < n; ++j)
        cin >> b[j];
    dp[0] = 0;
    add_line(b[0], 0);
    for (i = 1; i < n; ++i) {
        dp[i] = get_res(a[i]);
        add_line(b[i], dp[i]);
    }
    cout << dp[n - 1];
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}