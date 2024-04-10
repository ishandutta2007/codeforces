#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
const int LogN = 20;

unsigned long long l[N], r[N], t[N], k;

int main() {
    int i, j, n, a1, b1, q, p;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q;
    t[0] = 1;
    for (i = 1; i < 64; ++i)
        t[i] = t[i - 1] * 2;
    for (p = 0; p < q; ++p) {
        cin >> n >> k;
        int n1 = n;
        n = min(n, 31);
        int u = 0;
        for (i = 0; i <= n; ++i) {
            u = i;
            l[i] = t[i + 1] - i - 2;
            r[i] = (t[2 * i] - 1) / 3 + (t[2 * i] - (t[i + 1] - 1)) * (t[2 * (n - i)] - 1) / 3;
            if (((long double) t[2 * i] - 1) / 3.0 + (long double) (t[2 * i] - (t[i + 1] - 1)) * ((long double) (t[2 * (n - i)]) - 1) / 3 > 2 * k) {
                r[i] = 2 * k;
                break;
            }
        }
        bool flag = false;
        for (i = 0; i <= u; ++i)
        if (l[i] <= k && k <= r[i]) {
            cout << "YES" << ' ' << n1 - i << "\n";
            flag = true;
            break;
        }
        if (!flag)
            cout << "NO\n";
    }
}