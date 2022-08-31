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

struct Bus {
    int x, y, t;
    int id;
    bool operator<(const Bus &a) const {
        return (y != a.y) ? (y > a.y) : (id < a.id);
    }
};

#define MAX 200010
const int INF = 1001001001;

int N, M;
int bsLen;
Bus bs[MAX];
int ans[MAX];

int xsLen, ysLen;
int xs[MAX], ys[MAX];
map<int,int> tr;

int bitN;
set<int> bit[MAX];

void bitInit(int n) {
    bitN = n;
    for (int x = 1; x <= bitN; ++x) {
        bit[x].clear();
        bit[x].insert(INF);
    }
}
void bitAdd(int x, int val) {
    for (; x <= bitN; x += x & -x) bit[x].insert(val);
}
int bitCal(int x, int b) {
    int ret = INF;
    for (; x > 0; x &= x - 1) chmin(ret, *bit[x].lower_bound(b));
    return ret;
}

int main() {
    int i;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        bsLen = N + M;
        for (i = 0; i < bsLen; ++i) {
            bs[i].x = in();
            bs[i].y = in();
            bs[i].t = in();
            bs[i].id = i;
        }
        xsLen = ysLen = 0;
        for (i = 0; i < bsLen; ++i) {
            xs[xsLen++] = bs[i].x;
            ys[ysLen++] = bs[i].y;
        }
        sort(xs, xs + xsLen);
        sort(ys, ys + ysLen);
        xsLen = unique(xs, xs + xsLen) - xs;
        ysLen = unique(ys, ys + ysLen) - ys;
        for (i = 0; i < bsLen; ++i) {
            bs[i].x = lower_bound(xs, xs + xsLen, bs[i].x) - xs + 1;
            bs[i].y = lower_bound(ys, ys + ysLen, bs[i].y) - ys + 1;
        }
        tr.clear();
        tr[INF] = -1;
        for (i = 0; i < N; ++i) {
            tr[bs[i].t] = i + 1;
        }
        sort(bs, bs + bsLen);
        bitInit(xsLen);
        for (i = 0; i < bsLen; ++i) {
            if (bs[i].id < N) {
                bitAdd(bs[i].x, bs[i].t);
            } else {
                int res = bitCal(bs[i].x, bs[i].t);
                ans[bs[i].id] = tr[res];
            }
        }
        for (i = N; i < N + M; ++i) {
            if (i > N) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    
    return 0;
}