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

int n, A[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        int ans = 2;
        for (int i = 1; i < n; ++i) {
            int cnt = 2, pos = i + 1;
            while (pos < n && A[i] == A[pos] && A[i] == A[pos + 1]) ++cnt, ++pos, ++i;
            while (1) {
                int nxt = lower_bound(A + pos + 1, A + n + 1, A[pos] + (A[pos] - A[i])) - A;
                if (nxt > n) break;
                ++cnt;
                pos = nxt;
            }
            ans = max(ans, cnt);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}