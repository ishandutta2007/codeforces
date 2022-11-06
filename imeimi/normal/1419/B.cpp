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
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

const llong inf = 1e18 + 5;
vector<llong> S(1, 0);
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    for (int i = 1; S.back() < inf; ++i) {
        llong x = (1ll << i) - 1;
        S.push_back(S.back() + x * (x + 1) / 2);
    }
    int T;
    cin >> T;
    while (T--) {
        llong x;
        cin >> x;
        printf("%d\n", upper_bound(S.begin(), S.end(), x) - S.begin() - 1);
    }
    return 0;
}