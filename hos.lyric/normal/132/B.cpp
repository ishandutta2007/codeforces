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

int dx[] = { 1, 0, -1, 0, };
int dy[] = { 0, 1, 0, -1, };

#define MAXV 3010

int M, N, K;
char A[60][60];
int V;
int id[60][60];
int xMin[MAXV], yMin[MAXV], xMax[MAXV], yMax[MAXV];

int is[MAXV][4][4];
int us[MAXV];

int main() {
    int x, y;
    int xx, yy;
    int u;
    int hD, hC, hDiff;
    int k;
    
    for (; ~scanf("%d%d", &M, &K); ) {
        for (x = 0; x < M; ++x) {
            scanf("%s", A[x]);
        }
        N = strlen(A[0]);
        V = 0;
        memset(id, ~0, sizeof(id));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            if (x && A[x - 1][y] == A[x][y]) {
                id[x][y] = id[x - 1][y];
            } else if (y && A[x][y - 1] == A[x][y]) {
                id[x][y] = id[x][y - 1];
            } else {
                id[x][y] = V++;
            }
        }
//for(x=0;x<M;++x)pv(id[x],id[x]+N);
        memset(xMin, 0x3f, sizeof(xMin));
        memset(yMin, 0x3f, sizeof(yMin));
        memset(xMax, 0xc0, sizeof(xMax));
        memset(yMax, 0xc0, sizeof(yMax));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            u = id[x][y];
            chmin(xMin[u], x);
            chmin(yMin[u], y);
            chmax(xMax[u], x);
            chmax(yMax[u], y);
        }
        u = 0;
        hD = 1;
        hDiff = +1;
        hC = (hD + hDiff) & 3;
        memset(is, ~0, sizeof(is));
        for (k = 0; ; ++k) {
            if (k == K) {
                printf("%c\n", A[xMin[u]][yMin[u]]);
                goto done;
            }
            if (~is[u][hD][hC]) {
                int k0 = is[u][hD][hC];
                int kk = k0 + (K - k) % (k - k0);
                printf("%c\n", A[xMin[us[kk]]][yMin[us[kk]]]);
                goto done;
            }
            xx = yy = -1;
            switch ((hD * 2 + hDiff) & 7) {
                case 1: xx = xMax[u]; yy = yMax[u]; break;
                case 3: xx = xMin[u]; yy = yMax[u]; break;
                case 5: xx = xMin[u]; yy = yMin[u]; break;
                case 7: xx = xMax[u]; yy = yMin[u]; break;
                default: assert(0);
            }
            xx += dx[hD];
            yy += dy[hD];
            if (0 <= xx && xx < M && 0 <= yy && yy < N && A[xx][yy] != '0') {
                u = id[xx][yy];
            } else {
                if (hDiff == +1) {
                    hDiff = -1;
                } else {
                    hDiff = +1;
                    --hD &= 3;
                }
                hC = (hD + hDiff) & 3;
            }
        }
    done:;
    }
    
    return 0;
}