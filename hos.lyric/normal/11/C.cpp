//  Codeforces Beta Round #11
//  Problem C

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
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

#define MAXMN 63010

int uf[MAXMN];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

#define _(x,y) ((x) * N + (y))
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1, };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1, };

const int INF = 1001001001;
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }

int M, N, MN;
char A[260][260];
int cnt[MAXMN];
int as0[MAXMN], bs0[MAXMN], cs0[MAXMN], ds0[MAXMN];
int as1[MAXMN], bs1[MAXMN], cs1[MAXMN], ds1[MAXMN];

char AA(int xpy, int xmy) {
    int x = (xpy + xmy) / 2;
    int y = (xpy - xmy) / 2;
    return (0 <= x && x < M && 0 <= y && y < N) ? A[x][y] : ' ';
}

int main() {
    int h, x, y, xx, yy;
    int r;
    int a0, a1, b0, b1, c0, c1, d0, d1, p, q;
    int ans;
    
    for (int TC = in(); TC--; ) {
        M = in();
        N = in();
        for (x = 0; x < M; ++x) {
            scanf("%s", A[x]);
        }
        MN = M * N;
        memset(uf, ~0, MN << 2);
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (A[x][y] == '1') {
            for (h = 0; h < 8; ++h) {
                xx = x + dx[h];
                yy = y + dy[h];
                if (0 <= xx && xx < M && 0 <= yy && yy < N) if (A[xx][yy] == '1') {
                    conn(_(x, y), _(xx, yy));
                }
            }
        }
        memset(cnt, 0, MN << 2);
        for (r = 0; r < MN; ++r) {
            as0[r] = bs0[r] = cs0[r] = ds0[r] = +INF;
            as1[r] = bs1[r] = cs1[r] = ds1[r] = -INF;
        }
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (A[x][y] == '1') {
            r = root(_(x, y));
            ++cnt[r];
            chmin(as0[r], x); chmax(as1[r], x);
            chmin(bs0[r], y); chmax(bs1[r], y);
            chmin(cs0[r], x + y); chmax(cs1[r], x + y);
            chmin(ds0[r], x - y); chmax(ds1[r], x - y);
        }
        ans = 0;
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (A[x][y] == '1') if (uf[_(x, y)] < 0) {
            r = _(x, y);
//cout<<"r = "<<r<<"  "<<x<<" "<<y<<endl;
//cout<<"cnt = "<<cnt[r]<<endl;
            a0 = as0[r]; a1 = as1[r];
            b0 = bs0[r]; b1 = bs1[r];
            if (a1 - a0 < 1 || b1 - b0 < 1 || a1 - a0 != b1 - b0) goto failedab;
            if (cnt[r] != (a1 - a0) * 4) goto failedab;
            for (p = a0; p <= a1; ++p) if (A[p][b0] != '1' || A[p][b1] != '1') goto failedab;
            for (q = b0; q <= b1; ++q) if (A[a0][q] != '1' || A[a1][q] != '1') goto failedab;
            ++ans;
//cout<<a0<<" "<<a1<<"  "<<b0<<" "<<b1<<endl;
            goto failedcd;
        failedab:;
            c0 = cs0[r]; c1 = cs1[r];
            d0 = ds0[r]; d1 = ds1[r];
            if ((c1 - c0) % 2 != 0 || (d1 - d0) % 2 != 0) goto failedcd;
            if (c1 - c0 < 2 || d1 - d0 < 2 || c1 - c0 != d1 - d0) goto failedcd;
            if (cnt[r] != (c1 - c0) * 2) goto failedcd;
            for (p = c0; p <= c1; p += 2) if (AA(p, d0) != '1' || AA(p, d1) != '1') goto failedcd;
            for (q = d0; q <= d1; q += 2) if (AA(c0, q) != '1' || AA(c1, q) != '1') goto failedcd;
            ++ans;
//cout<<c0<<" "<<c1<<"  "<<d0<<" "<<d1<<endl;
        failedcd:;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}