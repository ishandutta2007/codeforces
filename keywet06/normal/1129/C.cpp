#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int R = 1;
const int N = 3002;
const int M = N * N;
const int P = 1e9 + 7;

bool bad[N];

int cv = 2;
int a[N];
int e[M][2];

int64 f[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout.setf(ios::fixed), cout.precision(20);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        int v = R;
        for (int j = i - 1; j >= 0; --j) {
            int g = min(4, i - j);
            if (g == 4) {
                int ms = a[j] * 8 + a[j + 1] * 4 + a[j + 2] * 2 + a[j + 3];
                g -= ms == 3 || ms == 5 || ms == 14 || ms == 15;
            }
            f[j] = 0;
            for (int k = 1; k <= g; ++k) f[j] += f[j + k];
            f[j] %= P;
            int& u = e[v][a[j]];
            if (u == 0) ans = (ans + f[j]) % P, u = cv++;
            v = u;
        }
        cout << ans << "\n";
    }
}