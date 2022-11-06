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

ll gcd(ll x, ll y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int n;
int A[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        pii mn = pii(1e9 + 5, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            mn = min(mn, pii(A[i], i));
        }
        printf("%d\n", n - 1);
        int x = mn.second;
        for (int i = x - 1; i >= 1; --i) {
            if (gcd(A[i], A[i + 1]) > 1) A[i] = A[i + 1] + 1;
            printf("%d %d %d %d\n", i, x, A[i], A[x]);
        }
        for (int i = x + 1; i <= n; ++i) {
            if (gcd(A[i], A[i - 1]) > 1) A[i] = A[i - 1] + 1;
            printf("%d %d %d %d\n", x, i, A[x], A[i]);
        }
    }
    return 0;
}