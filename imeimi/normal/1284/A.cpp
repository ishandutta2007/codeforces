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
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, m;
string S[30], T[30];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> S[i];
    for (int i = 1; i <= m; ++i) cin >> T[i];
    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        cout << S[(y - 1) % n + 1] << T[(y - 1) % m + 1] << '\n';
    }
    return 0;
}