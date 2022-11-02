#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define FOR(i, x, y) for (LL i=x; i<y; ++i)
#define sz(x) (int)x.size()

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;

vvi dat;

vi maxv;

int main() {
    scanf("%d", &n);
    dat.resize(n);
    maxv.resize(n);
    int maxs = 0;
    FOR (i, 0, n) {
        int siz, x;
        scanf("%d", &siz);
        dat[i].resize(siz);
        FOR (j, 0, siz) {
            scanf("%d", &dat[i][j]);
            maxv[i] = max(maxv[i], dat[i][j]);
        }
        maxs = max(maxs, maxv[i]);
    }

    LL ans = 0;
    FOR (i, 0, n) {
        LL del = 1LL*(maxs-maxv[i])*sz(dat[i]);
        ans += del;
    }
    cout << ans << endl;

    return 0;
}