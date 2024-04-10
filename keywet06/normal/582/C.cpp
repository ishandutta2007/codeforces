#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 5e5 + 5;

int n;
int a[N], cd[N], is_max[N], cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], a[i + n] = a[i];
    int64 res = 0;
    for (int g = 1; g <= n; ++g) {
        if (n % g) continue;
        for (int j = g; j <= n; j += g) cd[j] = g;
    }
    for (int g = 1; g <= n; ++g) {
        if (n % g) continue;
        for (int i = 0; i < g; ++i) {
            int m = 0;
            for (int j = i; j < n; j += g) m = max(m, a[j]);
            for (int j = i; j < n * 2; j += g) is_max[j] = (a[j] == m);
        }
        for (int j = 1; j < n * 2; ++j) {
            if (is_max[j]) is_max[j] += is_max[j - 1];
        }
        cnt[0] = 0;
        for (int i = 1; i < n; ++i) cnt[i] = cnt[i - 1] + (cd[i] == g);
        for (int j = n; j < n * 2; ++j) res += cnt[min(is_max[j], n - 1)];
    }
    cout << res << '\n';
    return 0;
}