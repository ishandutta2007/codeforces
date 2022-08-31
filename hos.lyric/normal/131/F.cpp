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

int M, N, K;
char A[510][510];
int B[510][510];
int C[510][510];

int calc(int xa, int ya, int xb, int yb) {
    return C[xa][ya] - C[xa][yb] - C[xb][ya] + C[xb][yb];
}

int main() {
    int x, y;
    int xa, xb;
    int ya, yb;
    
    for (; ~scanf("%d%d%d", &M, &N, &K); ) {
        M -= 2;
        N -= 2;
        for (x = 0; x < M + 2; ++x) {
            scanf("%s", A[x]);
        }
        memset(B, 0, sizeof(B));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            if (A[x][y + 1] == '1' && A[x + 1][y] == '1' && A[x + 1][y + 1] == '1' && A[x + 1][y + 2] == '1' && A[x + 2][y + 1] == '1') {
                B[x][y] = 1;
            }
        }
//for(x=0;x<M;++x)pv(B[x],B[x]+N);
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            C[x + 1][y + 1] = C[x + 1][y] + C[x][y + 1] - C[x][y] + B[x][y];
        }
        Int ans = 0;
        for (xa = 0; xa < M; ++xa) for (xb = xa + 1; xb <= M; ++xb) {
            for (ya = yb = 0; ya < N; ++ya) {
                for (; yb <= N && calc(xa, ya, xb, yb) < K; ++yb);
                ans += N + 1 - yb;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}