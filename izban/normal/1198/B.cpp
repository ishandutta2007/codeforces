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



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<int> last(n);

        int q;
        scanf("%d", &q);
        vector<int> upd(q, -1);


        for (int i = 0; i < q; i++) {
            int t, p, x;
            scanf("%d", &t);
            if (t == 1) {
                scanf("%d%d", &p, &x);
                p--;
                a[p] = x;
                last[p] = i;
            }
            if (t == 2) {
                scanf("%d", &x);
                upd[i] = x;
            }
        }

        for (int i = q - 2; i >= 0; i--) upd[i] = max(upd[i], upd[i + 1]);

        for (int i = 0; i < n; i++) {
            printf("%d%c", max(a[i], upd[last[i]]), " \n"[i + 1 == n]);
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}