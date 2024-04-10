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

#ifdef ONLINE_JUDGE
    #define I64d "%I64d"
#else
    #define I64d "%lld"
#endif

#define MAXN  200010
#define MAXQ  200010
#define MAXA 1000010
const int LARGE = 200;

struct Query {
    int a, b;
    int id;
    Int ans;
    bool operator<(const Query &q) const { return (b < q.b); }
};

int N, Q;
int A[MAXN];
Query qs[MAXQ];
Int ans[MAXN];

int app[MAXA], cnt[MAXA];
int last[MAXN];
int sum[MAXN];

int bitN;
Int bit[MAXN];
void bitAdd(int x, Int val) {
    ++x;
    for (; x <= bitN; x += x & -x) bit[x] += val;
}
Int bitSum(int x) {
    Int ret = 0;
    for (; x > 0; x &= x - 1) ret += bit[x];
    return ret;
}

int main() {
    int i, j, e;
    
    for (; ~scanf("%d%d", &N, &Q); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        for (e = 0; e < Q; ++e) {
            qs[e].a = in() - 1;
            qs[e].b = in() - 1;
            qs[e].id = e;
            qs[e].ans = 0;
        }
        sort(qs, qs + Q);
        memset(app, ~0, sizeof(app));
        memset(cnt, ~0, sizeof(cnt));
        for (i = 0; i < N; ++i) {
            last[i] = app[A[i]];
            app[A[i]] = i;
            ++cnt[A[i]];
        }
        for (i = 0; i < N; ++i) {
            if (app[A[i]] == i && cnt[A[i]] >= LARGE) {
                for (j = 0; j < N; ++j) {
                    sum[j + 1] = sum[j] + ((A[j] == A[i]) ? 1 : 0);
                }
                for (e = 0; e < Q; ++e) {
                    Int ks = sum[qs[e].b + 1] - sum[qs[e].a];
                    qs[e].ans += ks * ks * A[i];
                }
            }
        }
        bitN = N + 5;
        memset(bit, 0, sizeof(bit));
        for (e = 0, i = 0; i < N; ++i) {
            if (cnt[A[i]] < LARGE) {
                bitAdd(i, A[i]);
                for (j = last[i]; ~j; j = last[j]) {
                    bitAdd(j, 2 * A[j]);
                }
            }
            for (; e < Q && qs[e].b == i; ++e) {
                qs[e].ans += bitSum(qs[e].b + 1) - bitSum(qs[e].a);
            }
        }
        for (e = 0; e < Q; ++e) {
            ans[qs[e].id] = qs[e].ans;
        }
        for (e = 0; e < Q; ++e) {
            printf(I64d "\n", ans[e]);
        }
    }
    
    return 0;
}