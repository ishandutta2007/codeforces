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

int n, A[200005], B[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> A[i] >> B[i];
        int s = 1, e = n;
        while (s < e) {
            int m = (s + e + 1) / 2;
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                if (A[i] >= m - cnt - 1 && B[i] >= cnt) ++cnt;
                if (cnt == m) break;
            }
            if (cnt == m) s = m;
            else e = m - 1;
        }
        printf("%d\n", s);
    }
    return 0;
}