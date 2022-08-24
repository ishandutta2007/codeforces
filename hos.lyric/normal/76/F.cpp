//  UOI 2011.04.12.

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

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
Int V, T[100010], X[100010], Y[100010], Z[100010];
int pslen;
pint ps[100010];
int aslen;
Int as[100010];

int solve() {
    int i;
    sort(ps, ps + pslen);
    aslen = 0;
    for (i = 0; i < pslen; ++i) {
        int pos = upper_bound(as, as + aslen, ps[i].second) - as;
        as[pos] = ps[i].second;
        if (pos == aslen) ++aslen;
    }
    return aslen;
}

int main() {
    int i;
    int ans[2];
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            X[i] = in();
            T[i] = in();
        }
        V = in();
        for (i = 0; i < N; ++i) {
            Y[i] = V * T[i] - X[i];
            Z[i] = V * T[i] + X[i];
        }
        for (int prob = 0; prob < 2; ++prob) {
            pslen = 0;
            for (i = 0; i < N; ++i) {
                if (!prob && abs(X[i]) > V * T[i]) continue;
                ps[pslen++] = mp(Y[i], Z[i]);
            }
            ans[prob] = solve();
        }
        printf("%d %d\n", ans[0], ans[1]);
    }
    
    return 0;
}