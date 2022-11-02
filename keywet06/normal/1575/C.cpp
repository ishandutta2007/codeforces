#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 5;
const int M = 1000000007;

int ans, n, m, k, r;
int a[N], b[N], p[N], s[N];
int cnt[19][N];

void add(int &x, int y) {
    x += y;
    if (x >= M) x -= M;
}
void sub(int &x, int y) {
    x -= y;
    if (x < 0) x += M;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = (b[i - 1] + a[i - 1]) % k;
    for (int i = 0; i < n; ++i) cnt[0][b[i]]++;
    r = p[0] = b[n];
    for (int i = 1; i <= 17; ++i) {
        for (int j = 0; j < k; ++j) {
            add(cnt[i][j], cnt[i - 1][j]);
            add(cnt[i][(j + r) % k], cnt[i - 1][j]);
        }
        r = r * 2 % k;
        p[i] = r;
    }
    r = 0;
    for (int i = 17; i >= 0; --i)
        if ((m >> i) & 1) {
            for (int j = 0; j < k; ++j) add(s[(j + r) % k], cnt[i][j]);
            r = (r + p[i]) % k;
        }
    ans = 0;
    for (int i = 0; i < n; ++i) {
        sub(s[b[i]], 1);
        add(ans, s[b[i]]);
        add(s[(b[i] + r) % k], 1);
    }
    ans = 1ll * ans * m % M;
    if (!r) add(ans, 1);
    cout << ans << endl;
    return 0;
}