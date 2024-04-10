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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int q;
    cin >> q;
    while (q--) {
        int n;
        vector<int> A;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        sort(A.begin(), A.end());
        int ans = 1;
        for (int i = 1; i < (int)A.size(); ++i) {
            if (abs(A[i - 1] - A[i]) == 1) ans = 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}