#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

const string FINITE = "Finite";
const string INFINITE = "Infinite";



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<vector<int>> b(n, vector<int>(n));
        vector<vector<int>> mx(n, vector<int>(n));
        for (int len = 0; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if (len == 0) b[i][j] = a[i];
                else {
                    b[i][j] = b[i][j - 1] ^ b[i + 1][j];
                    mx[i][j] = max(mx[i][j], max(mx[i][j - 1], mx[i + 1][j]));
                }
                mx[i][j] = max(mx[i][j], b[i][j]);
            }
        }

        int q;
        scanf("%d", &q);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--; r--;
            printf("%d\n", mx[l][r]);
        }
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}