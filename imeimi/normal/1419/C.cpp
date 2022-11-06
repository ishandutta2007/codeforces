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
        int n, x;
        cin >> n >> x;
        int sum = 0;
        set<int> A;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            sum += a;
            A.insert(a);
        }
        if (int(A.size()) == 1 && *A.begin() == x) printf("0\n");
        else if (sum == x * n || A.count(x)) printf("1\n");
        else printf("2\n");
    }
    return 0;
}