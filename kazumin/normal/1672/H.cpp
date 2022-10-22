#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, q, l, r, psa[2][MN];
char a[MN];

int32_t main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < n; j++) {
            psa[i][j + 1] = psa[i][j] + (a[j] == '0' + i && a[j + 1] == '0' + i);
        }
    }
    while (q--) {
        cin >> l >> r;
        printf("%lld\n", max(psa[0][r] - psa[0][l], psa[1][r] - psa[1][l]) + 1);
    }

    return 0;
}