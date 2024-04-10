#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    printf("YES\n");
    forn(i, n) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        x1 = abs(x1);
        y1 = abs(y1);
        int res = 1;
        if (x1%2) ++res;
        if (y1%2) res += 2;
        printf("%d\n", res);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}