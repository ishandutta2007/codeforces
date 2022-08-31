#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, K;
int is[1010];
int asLen, bsLen;
pint as[1010], bs[1010];
int ansLens[1010];
pint ans[1010][1010];

int main() {
    int i, j;
    int x;
    
    for (; ~scanf("%d%d", &N, &K); ) {
        asLen = bsLen = 0;
        for (i = 0; i < N; ++i) {
            x = in();
            is[i] = in();
            if (is[i] == 1) {
                as[asLen++] = mp(x, i);
            } else {
                bs[bsLen++] = mp(x, i);
            }
        }
        sort(as, as + asLen, greater<pint>());
        sort(bs, bs + bsLen, greater<pint>());
        int kill = min(asLen, K - 1);
        memset(ansLens, 0, K << 2);
        for (i = 0; i < kill; ++i) {
            ans[i][ansLens[i]++] = as[i];
        }
        int pos = kill;
        for (i = kill; i < asLen; ++i) {
            ans[pos][ansLens[pos]++] = as[i];
            if (++pos == K) pos = kill;
        }
        for (i = 0; i < bsLen; ++i) {
            ans[pos][ansLens[pos]++] = bs[i];
            if (++pos == K) pos = kill;
        }
        Int sum = 0;
        for (i = 0; i < K; ++i) {
            sort(ans[i], ans[i] + ansLens[i]);
            bool ok = 0;
            for (j = 0; j < ansLens[i]; ++j) {
                ok = ok || (is[ans[i][j].second] == 1);
            }
            for (j = 0; j < ansLens[i]; ++j) {
                sum += ans[i][j].first * 2;
            }
            if (ok) {
                sum -= ans[i][0].first;
            }
        }
        cout << (sum / 2) << "." << (sum % 2 * 5) << endl;
        for (i = 0; i < K; ++i) {
            printf("%d", ansLens[i]);
            for (j = 0; j < ansLens[i]; ++j) {
                printf(" %d", ans[i][j].second + 1);
            }
            puts("");
        }
    }
    
    return 0;
}