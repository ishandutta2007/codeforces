#include <bits/stdc++.h>
#define fi first
#define se second
#define sqr(a) ((a) * (a))
#define ll long long
#define ld lond double
using namespace std;
const int N = 1e5 + 1;
const int inf = 1e9 + 1;

int a[N], l[N];
bool u[N];

int main() {
    int i, j, k, n, x, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long double sum = n, tk = 0;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        l[i] = 1;
    }
    while (true) {
        tk = 0;
        for (i = 1; i <= n; ++i)
        if (l[i] > a[i])
            ++tk;
        int q = (0.50000001 + 100 * tk / sum);
        int cntk = k;
        for (i = 1; i <= n; ++i)
        if (l[i] <= a[i] && cntk > 0) {
            if (l[i] == q)
                u[i] = 1;
            ++l[i];
            --cntk;
        }
        if (cntk == k)
            break;
    }
    int ans = 0;
    for (i = 1; i <= n; ++i)
        ans += u[i];
    cout << ans;
}