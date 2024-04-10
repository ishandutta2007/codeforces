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

int uf[1000010];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1, };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1, };

int M, N;
char A[1010][1010];
bool a[1010][1010];

bool vis[1010][1010];
int que[2000010], *qb, *qe;

int zeit, flg[1010][1010];
int len, xs[1000010], ys[1000010];

int search(int sx, int sy) {
    int h, x, y, xx, yy;
    int i;
    qb = qe = que;
    vis[sx][sy] = 1;
    *qe++ = sx;
    *qe++ = sy;
    for (; qb != qe; ) {
        x = *qb++;
        y = *qb++;
        for (h = 0; h < 8; ++h) {
            xx = x + dx[h];
            yy = y + dy[h];
            if (!(0 <= xx && xx < M && 0 <= yy && yy < N)) {
                //  outside
                return -1;
            }
            if (!a[xx][yy]) {
                if (!vis[xx][yy]) {
                    vis[xx][yy] = 1;
                    *qe++ = xx;
                    *qe++ = yy;
                }
            }
        }
    }
//cout<<"que : ";pv(que,qb);
    ++zeit;
    len = 0;
    for (int *q = que; q != qb; ) {
        x = *q++;
        y = *q++;
        for (h = 0; h < 8; ++h) {
            xx = x + dx[h];
            yy = y + dy[h];
            if (a[xx][yy]) {
                if (flg[xx][yy] != zeit) {
                    flg[xx][yy] = zeit;
                    xs[len] = xx;
                    ys[len] = yy;
                    ++len;
                }
            }
        }
    }
    for (i = 0; i < len; ++i) {
        x = xs[i];
        y = ys[i];
        int cnt = 0;
        for (h = 0; h < 4; ++h) {
            xx = x + dx[h];
            yy = y + dy[h];
            if (0 <= xx && xx < M && 0 <= yy && yy < N) {
                if (flg[xx][yy] == zeit) {
                    ++cnt;
                }
            }
        }
        if (cnt != 2) {
            //  not correct
//cerr<<"not correct"<<endl;
            return -2;
        }
    }
    /*
    for (i = 0; i < len; ++i) {
        x = xs[i];
        y = ys[i];
        if (flg[x][y] == zeit && flg[x][y + 1] == zeit && flg[x + 1][y] == zeit && flg[x + 1][y + 1] == zeit) {
            //  !!four!!
//cerr<<"!!four!!"<<endl;
            return -4;
        }
    }
    */
    int r = -1;
    for (i = 0; i < len; ++i) {
        x = xs[i];
        y = ys[i];
        if (!~r) r = root(x * N + y);
        if (r != root(x * N + y)) {
            //  not connected
            return -3;
        }
    }
//cout<<"len = "<<len<<endl;
    return len;
}

int main() {
    int x, y;
    
    for (; ~scanf("%d%d", &M, &N); ) {
        for (x = 0; x < M; ++x) {
            scanf("%s", A[x]);
        }
        memset(a, 0, sizeof(a));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            a[x][y] = (A[x][y] == '1');
        }
        
        memset(uf, ~0, (M * N) << 2);
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (a[x][y]) {
            if (x && a[x - 1][y]) conn((x - 1) * N + y, x * N + y);
            if (y && a[x][y - 1]) conn(x * N + (y - 1), x * N + y);
        }
        
        int ans = 0;
        for (x = 0; x < M - 1; ++x) for (y = 0; y < N - 1; ++y) {
            if (a[x][y] && a[x][y + 1] && a[x + 1][y] && a[x + 1][y + 1]) {
                chmax(ans, 4);
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(flg, 0, sizeof(flg));
        zeit = 0;
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (!a[x][y]) {
            if (!vis[x][y]) {
                int tmp = search(x, y);
                chmax(ans, tmp);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}