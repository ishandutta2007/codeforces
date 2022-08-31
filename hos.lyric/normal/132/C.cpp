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

const int INF = 1001001001;

int M, N;
char S[110];
int dpMin[110][110][2];
int dpMax[110][110][2];

int main() {
    int i, j, s;
    int jj, ss;
    int dx;
    
    for (; ~scanf("%s%d", S, &N); ) {
        M = strlen(S);
        memset(dpMin, 0x3f, sizeof(dpMin));
        memset(dpMax, 0xc0, sizeof(dpMax));
        dpMin[0][0][0] = 0;
        dpMax[0][0][0] = 0;
        for (i = 0; i < M; ++i) for (j = 0; j <= N; ++j) for (s = 0; s < 2; ++s) {
            {
                //  F
                jj = (S[i] != 'F') ? (j + 1) : j;
                ss = s;
                dx = s ? -1 : +1;
                chmin(dpMin[i + 1][jj][ss], dpMin[i][j][s] + dx);
                //chmax(dpMax[i + 1][jj][ss], dpMin[i][j][s] + dx);
                //chmin(dpMin[i + 1][jj][ss], dpMax[i][j][s] + dx);
                chmax(dpMax[i + 1][jj][ss], dpMax[i][j][s] + dx);
            }
            {
                //  T
                jj = (S[i] != 'T') ? (j + 1) : j;
                ss = s ^ 1;
                dx = 0;
                chmin(dpMin[i + 1][jj][ss], dpMin[i][j][s] + dx);
                //chmax(dpMax[i + 1][jj][ss], dpMin[i][j][s] + dx);
                //chmin(dpMin[i + 1][jj][ss], dpMax[i][j][s] + dx);
                chmax(dpMax[i + 1][jj][ss], dpMax[i][j][s] + dx);
            }
        }
        int ansMin = +INF, ansMax = -INF;
        for (j = N % 2; j <= N; j += 2) for (s = 0; s < 2; ++s) {
            chmin(ansMin, dpMin[M][j][s]);
            chmax(ansMax, dpMax[M][j][s]);
        }
//cout<<ansMin<<" "<<ansMax<<endl;
        int ans = max(abs(ansMin), abs(ansMax));
        printf("%d\n", ans);
    }
    
    return 0;
}