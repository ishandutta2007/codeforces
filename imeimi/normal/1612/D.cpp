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
        ll a, b, x;
        cin >> a >> b >> x;
        bool ans = false;
        while (a && b) {
            if (a > b) swap(a, b);
            if (a == x || b == x) {
                ans = true;
                break;
            }
            if (x <= b && x % a == b % a) {
                ans = true;
                break;
            }
            b %= a;
        }
        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}