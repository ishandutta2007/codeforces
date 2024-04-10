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

int ex[] = { 1, 1, 0, -1, -1, -1, 0, 1, };
int ey[] = { 0, 1, 1, 1, 0, -1, -1, -1, };

#define MAX 100010
#define ws ___ws

int N, M;
int X[MAX], Y[MAX];
pair<pint,int> ps[MAX];
int ws[MAX];
int ans[10];

int main() {
    int h, hh, i;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        for (i = 0; i < M; ++i) {
            X[i] = in();
            Y[i] = in();
        }
        memset(ws, 0, M << 2);
        for (h = 0; h < 8; ++h) {
            hh = (h + 2) & 7;
            for (i = 0; i < M; ++i) {
                ps[i] = mp(mp(ex[h] * X[i] + ey[h] * Y[i], ex[hh] * X[i] + ey[hh] * Y[i]), i);
            }
            sort(ps, ps + M);
            for (i = 0; i < M - 1; ++i) {
                if (ps[i].first.first == ps[i + 1].first.first) {
                    ++ws[ps[i].second];
                }
            }
        }
        memset(ans, 0, sizeof(ans));
        for (i = 0; i < M; ++i) {
            ++ans[ws[i]];
        }
        for (h = 0; h <= 8; ++h) {
            if (h) printf(" ");
            printf("%d", ans[h]);
        }
        puts("");
    }
    
    return 0;
}