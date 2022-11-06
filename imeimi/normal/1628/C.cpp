#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int n;
int A[1005][1005];
bool G[1005][1005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> A[i][j];
                G[i][j] = 0;
            }
        }
        for (int s = 3; s <= n + 1; ++s) {
            for (int i = 2; i < s && i <= n; ++i) {
                int j = s - i;
                if (j > n) continue;
                G[i][j] = G[i - 1][j + 1] ^ G[i - 2][j] ^ G[i - 1][j - 1] ^ 1;
            }
        }
        for (int s = n + 3; s <= n + n; s += 2) {
            for (int i = 1; i < s && i <= n; ++i) {
                int j = s - i;
                if (j > n) continue;
                G[i][j] = G[n - j + 1][n - i + 1];
            }
        }
        for (int s = n + 2; s <= n + n; s += 2) {
            for (int i = 1; i < s && i <= n; ++i) {
                int j = s - i;
                if (j > n) continue;
                G[i][j] = G[n - j + 1][n - i + 1] ^ (i + 1 & 1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (G[i][j]) ans ^= A[i][j];
                if (i + j & 1) printf("  ");
                else debug("%d ", int(G[i][j]));
            }
            debug("\n");
        }
        printf("%d\n", ans);
    }
    return 0;
}