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

int q(int x) {
    cout << "? " << x << endl;
    cin >> x;
    if (!x) exit(0);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> P(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (P[i]) continue;
            int init = q(i);
            int p = init;
            while (1) {
                int x = q(i);
                P[p] = x;
                if (x == init) break;
                p = x;
            }
        }
        cout << '!';
        for (int i = 1; i <= n; ++i) cout << ' ' << P[i];
        cout << endl;
    }
    return 0;
}