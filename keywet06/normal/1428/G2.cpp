#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 1000005;

int k, q, po = 3, tot;

int64 p[6];
int64 f[N], w[N], c[N];

int main() {
    cin >> k;
    for (int i = 1; i <= 999999; i++) {
        f[i] = -0x7ffffffffffff;
    }
    for (int i = 0; i <= 5; i++) {
        cin >> p[i];
    }
    for (int i = 0; i <= 5; i++) {
        int64 t = 3 * (k - 1);
        int64 now = 1;
        while (t > now) {
            t -= now;
            w[++tot] = p[i] * now;
            c[tot] = po * now;
            now *= 2;
        }
        w[++tot] = p[i] * t;
        c[tot] = po * t;
        po *= 10;
    }
    for (int i = 1; i <= tot; i++) {
        for (int j = 999999; j >= c[i]; j--) {
            f[j] = max(f[j], f[j - c[i]] + w[i]);
        }
    }
    po = 1;
    for (int i = 0; i <= 5; i++) {
        for (int j = 999999; j >= 0; j--) {
            for (int x = 1; x <= 9; x++) {
                if (j < x * po) break;
                f[j] = max(f[j], f[j - x * po] + (!(x % 3)) * (x / 3) * p[i]);
            }
        }
        po *= 10;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}