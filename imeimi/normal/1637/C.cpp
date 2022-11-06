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

int n, A[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        if (n == 3) {
            printf("%d\n", A[2] % 2 ? -1 : A[2] / 2);
            continue;
        }
        vector<int> V;
        for (int i = 2; i < n; ++i) {
            if (A[i]) V.push_back(A[i]);
        }
        if (V.size() == 1 && V[0] == 3) {
            printf("-1\n");
            continue;
        }
        bool pos = 0;
        ll ans = 0;
        for (int i : V) {
            if (i >= 2) pos = 1;
            ans += (i + 1) / 2;
        }
        printf("%lld\n", pos ? ans : -1);
    }
    return 0;
}