#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

ll fast(vector<int> a, int m) {
    int L = -1, R = m - 1;
    while (R - L > 1) {
        int M = (L + R) >> 1;

        int mn = 0;
        for (int x : a) {
            int nl = x;
            int nr = (x + M) % m;

            if (nl <= nr) {
                if (mn > nr) mn = m;
                else mn = max(mn, nl);
            } else {
                if (nr >= mn) mn = mn;
                else mn = max(mn, nl);
            }
        }
        if (mn == m) L = M;
        else R = M;
    }
    return R;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        printf("%lld\n", fast(a, m));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}