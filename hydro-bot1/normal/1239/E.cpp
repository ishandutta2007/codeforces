// Hydro submission #624aa05fc7ec5adf0dbc7295@1649057887872
#include <bits/stdc++.h>

using namespace std;

const int N = 25, N2 = 55, M = 1250005;
int n, a[N2];
bool vis[N2];
bitset<M> f[N2][N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n * 2; i++)
        cin >> a[i];

    sort(a + 1, a + n * 2 + 1);
    f[2][0][0] = true;
    int sum = 0;

    for (int i = 3; i <= n * 2; i++) {
        sum += a[i];

        for (int j = 0; j < n; j++) {
            f[i][j] = f[i - 1][j];

            if (j)
                f[i][j] |= f[i - 1][j - 1] << a[i];
        }
    }

    const bitset<M> &g = f[n * 2][n - 1];
    int h = sum / 2;

    for (int i = 0; i <= h; i++)
        if (g[h - i]) {
            int cur = h - i;
            vis[1] = true;

            for (int j = n * 2, k = n - 1; j >= 3; j--)
                if (!f[j - 1][k][cur])
                    vis[j] = true, k--, cur -= a[j];

            for (int j = 1; j <= n * 2; j++)
                if (vis[j])
                    cout << a[j] << " ";

            cout << "\n";

            for (int j = n * 2; j >= 1; j--)
                if (!vis[j])
                    cout << a[j] << " ";

            cout << "\n";
            break;
        }

    return 0;
}