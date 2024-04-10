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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        char S[100];
        cin >> n >> S + 1;
        int sum = 0, mn = 0;
        for (int i = 1; i <= n; ++i) {
            sum += S[i] == '(' ? 1 : -1;
            mn = min(mn, sum);
        }
        printf("%d\n", -mn);
    }
    return 0;
}