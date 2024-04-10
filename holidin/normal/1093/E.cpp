#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int G = 500;
const int mod = 998244353;

int m[G][N], a[N], b[N], pa[N], pb[N], n;

int f(int i) {
    return (i & (-i));
}

void add(int s, int i, int j) {
    while (i <= n) {
        m[s][i] += j;
        i += f(i);
    }
}

int sum(int s, int i) {
    int ans = 0;
    while (i > 0) {
        ans += m[s][i];
        i -= f(i);
    }
    return ans;
}

int main() {
   int i, j, k, p, x, y, len, t, l1, r1, l2, r2;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int Ln = 2000;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        pa[a[i]] = i;
    }
    for (j = 1; j <= n; ++j) {
        cin >> b[j];
        --b[j];
        pb[b[j]] = j;
        add(pa[b[j]] / Ln, j, 1);
    }
    for (i = 0; i < k; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> l1 >> r1 >> l2 >> r2;
            --l1;
            --r1;
            int ans = 0;
            int p1 = l1 / Ln, p2 = r1 / Ln;
            for (j = p1 + 1; j < p2; ++j)
                ans += sum(j, r2) - sum(j, l2 - 1);
            if (p1 == p2) {
                for (j = l1; j <= r1; ++j)
                if (l2 <= pb[a[j]] && pb[a[j]] <= r2)
                    ++ans;
            } else {
                for (j = l1; j < (p1 + 1) * Ln; ++j)
                if (l2 <= pb[a[j]] && pb[a[j]] <= r2)
                    ++ans;
                for (j = p2 * Ln; j <= r1; ++j)
                if (l2 <= pb[a[j]] && pb[a[j]] <= r2)
                    ++ans;
            }
            cout << ans << "\n";
        } else {
            cin >> x >> y;
            add(pa[b[x]] / Ln, x, -1);
            add(pa[b[y]] / Ln, y, -1);
            swap(b[x], b[y]);
            swap(pb[b[x]], pb[b[y]]);
            add(pa[b[x]] / Ln, x, 1);
            add(pa[b[y]] / Ln, y, 1);
        }
    }
}