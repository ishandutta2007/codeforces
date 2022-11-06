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
int A[200005];
int mn[200005];
int mx[200005];
int S[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        if (!mn[A[i]]) {
            mn[A[i]] = i;
        }
        mx[A[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = i;
        int j = mx[A[i]];
        if (j == i) continue;
        while (1) {
            int nxt = 0;
            while (i < j) nxt = max(nxt, mx[A[i++]]);
            if (nxt <= j) break;
            --ans;
            j = nxt;
        }
        ans += j - p - 1;
        debug("%d -> %d\n", p, j);
    }
    printf("%d\n", ans);
    return 0;
}