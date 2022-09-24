// ILDAR LUCHIY
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

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        vector<int> mx(n + 1);
        for (int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], a[i - 1]);

        int j = 0;
        for (int i = 1; i < n; i++) if (a[i] > a[j]) j = i;

        deque<int> d;
        for (int i = 0; i < n; i++) d.push_back(a[i]);

        while (d[0] != a[j]) {
            int x = d[0];
            d.pop_front();
            int y = d[0];
            d.pop_front();
            d.push_front(max(x, y));
            d.push_back(min(x, y));
        }

        for (int i = 0; i < m; i++) {
            ll x;
            scanf("%lld", &x);
            x--;

            if (x < j) {
                printf("%d %d\n", mx[x + 1], a[x + 1]);
            } else {
                x -= j;
                printf("%d %d\n", d[0], d[1 + x % (n - 1)]);
            }
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}