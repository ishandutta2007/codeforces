//  Yandex.Algorithm 2011 Round 1

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int F = 5;

int Q, N;
char QT[100010][6];
Int QX[100010];
int QY[100010];

Int xs[100010];

int segn;
int cnt[400010];
Int sum[400010][6];

void merge(int a, int b, int c) {
    cnt[a] = cnt[b] + cnt[c];
    int f, g;
    for (f = 0; f < F; ++f) {
        sum[a][f] = sum[b][f];
    }
    g = cnt[b] % F;
    for (f = 0; f < F; ++f) {
        sum[a][(f + g) % F] += sum[c][f];
    }
}
void add(int a) {
    a += segn;
    cnt[a] = 1;
    sum[a][0] = xs[a - segn];
    for (; a >>= 1; ) {
        merge(a, a << 1 | 0, a << 1 | 1);
    }
}
void del(int a) {
    a += segn;
    cnt[a] = 0;
    sum[a][0] = 0;
    for (; a >>= 1; ) {
        merge(a, a << 1 | 0, a << 1 | 1);
    }
}

int main() {
    int q;
    
    for (; ~scanf("%d", &Q); ) {
        N = 0;
        for (q = 0; q < Q; ++q) {
            scanf("%s", QT[q]);
            if (!strcmp(QT[q], "add")) {
                QX[q] = in();
                xs[N++] = QX[q];
            } else if (!strcmp(QT[q], "del")) {
                QX[q] = in();
                xs[N++] = QX[q];
            } else {
                QX[q] = QY[q] = -1;
            }
        }
        sort(xs, xs + N);
        N = unique(xs, xs + N) - xs;
        for (q = 0; q < Q; ++q) if (~QX[q]) {
            QY[q] = lower_bound(xs, xs + N, QX[q]) - xs;
        }
        for (segn = 1; segn < N + 5; segn <<= 1);
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        for (q = 0; q < Q; ++q) {
            if (!strcmp(QT[q], "add")) {
                add(QY[q]);
            } else if (!strcmp(QT[q], "del")) {
                del(QY[q]);
            } else {
//for(int a=1;a<segn*2;++a)pv(sum[a],sum[a]+F);cout<<endl;
                cout << sum[1][2] << endl;
            }
        }
    }
    
    return 0;
}