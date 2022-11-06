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

int A[10005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        bool pos = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i + 1]) pos = 1;
        }
        printf(pos ? "YES\n" : "NO\n");
    }
    return 0;
}