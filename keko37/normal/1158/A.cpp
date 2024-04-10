#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const int INF = 1000000007;

llint n, m, x = -1, y = -1, mn = INF, sol, sum;
llint a[MAXN], b[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
        y = max(a[i], y);
        if (y > x) swap(x, y);
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
        mn = min(mn, b[i]);
        if (b[i] < x) {
            cout << -1;
            return 0;
        }
        sol += sum - x + b[i];
    }
    if (mn != x) sol = sol + x - y;
    cout << sol;
    return 0;
}