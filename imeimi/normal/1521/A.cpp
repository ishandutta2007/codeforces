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
        ll a, b;
        cin >> a >> b;
        if (b == 1) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%lld %lld %lld\n", a, 2 * a * b, a * (2 * b + 1));
    }
    return 0;
}