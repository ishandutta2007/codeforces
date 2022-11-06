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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> A, S;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            A.push_back(a);
        }
        S = A;
        sort(S.begin(), S.end());
        int ans = n + 5;
        int x, y;
        for (int i = 0, cnt = 1; i < n; ++i, --cnt) {
            while (i + cnt <= n && cnt - (n - cnt) < k) ++cnt;
            if (i + cnt > n) continue;
            int v = S[i + cnt - 1] - S[i];
            if (ans > v) ans = v, x = S[i], y = S[i + cnt - 1];
        }
        debug("ans = %d\n", ans);
        printf("%d %d\n1", x, y);
        for (int i = 0, sum = 0, cnt = 0; i < n; ++i) {
            if (x <= A[i] && A[i] <= y) ++sum;
            else --sum;
            if (cnt < k - 1 && sum == cnt + 1) {
                ++cnt;
                printf(" %d\n%d", i + 1, i + 2);
            }
        }
        printf(" %d\n", n);
    }
    return 0;
}