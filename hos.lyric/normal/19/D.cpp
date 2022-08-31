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

#define MAXN 200010

int N;
char typ[MAXN][10];
int X[MAXN], Y[MAXN];

int xsLen;
int xs[MAXN];

set<int> sets[MAXN];
int segN;
int seg[MAXN * 4];

void segInit(int n) {
    for (segN = 1; segN < n; segN <<= 1);
    int a;
    for (a = 0; a < segN; ++a) seg[segN + a] = -1;
    for (a = segN; --a; ) seg[a] = max(seg[a << 1], seg[a << 1 | 1]);
}
void segUpdate(int a, int val) {
    seg[a += segN] = val;
    for (; a >>= 1; ) {
        seg[a] = max(seg[a << 1], seg[a << 1 | 1]);
    }
}
int segRangeMax(int a, int b) {
    int ret = -1;
    for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
        if ( a & 1) { chmax(ret, seg[a]); ++a; }
        if (~b & 1) { chmax(ret, seg[b]); --b; }
    }
    return ret;
}

int main() {
    int i;
    int e;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            scanf("%s%d%d", typ[i], &X[i], &Y[i]);
            if (typ[i][0] == 'f') {
                ++X[i];
                ++Y[i];
            }
        }
        xsLen = 0;
        for (i = 0; i < N; ++i) {
            xs[xsLen++] = X[i];
        }
        sort(xs, xs + xsLen);
        xsLen = unique(xs, xs + xsLen) - xs;
        for (e = 0; e < xsLen; ++e) {
            sets[e].clear();
            sets[e].insert(-1);
        }
        segInit(xsLen);
        for (i = 0; i < N; ++i) {
            e = lower_bound(xs, xs + xsLen, X[i]) - xs;
            switch (typ[i][0]) {
                case 'a': {
                    sets[e].insert(Y[i]);
                    segUpdate(e, *--sets[e].end());
                } break;
                case 'r': {
                    sets[e].erase(Y[i]);
                    segUpdate(e, *--sets[e].end());
                } break;
                case 'f': {
                    int lo = e - 1, ho = xsLen;
                    for (; lo + 1 < ho; ) {
                        int mo = (lo + ho) / 2;
                        (segRangeMax(e, mo) >= Y[i]) ? (ho = mo) : (lo = mo);
                    }
                    if (ho >= xsLen) {
                        puts("-1");
                    } else {
                        int y = *sets[ho].lower_bound(Y[i]);
                        printf("%d %d\n", xs[ho], y);
                    }
                } break;
                default: {
                    assert(0);
                }
            }
        }
    }
    
    return 0;
}