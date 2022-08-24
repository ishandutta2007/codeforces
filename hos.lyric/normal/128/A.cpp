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

const int N = 8;

char A[20][20];
bool vis[20][20][20];

bool dfs(int t, int x, int y) {
    if (vis[t][x][y]) return 0;
    vis[t][x][y] = 1;
//cout<<"dfs "<<t<<" "<<x<<" "<<y<<endl;
    if (x == 0 && y == N - 1) {
        return 1;
    }
    
    int tt, xx, yy;
    int dt, xxx, yyy;
    int dx, dy;
    for (dx = -1; dx <= +1; ++dx) for (dy = -1; dy <= +1; ++dy) {
        tt = min(t + 1, N);
        xx = x + dx;
        yy = y + dy;
        bool ok = 1;
        if (0 <= xx && xx < N && 0 <= yy && yy < N) {
            for (dt = 0; dt < 2; ++dt) {
                xxx = xx - (t + dt);
                yyy = yy;
                if (0 <= xxx && xxx < N && 0 <= yyy && yyy < N) {
                    if (A[xxx][yyy] == 'S') {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                if (dfs(tt, xx, yy)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int x;
    
    for (; ; ) {
        for (x = 0; x < N; ++x) {
            if (!~scanf("%s", A[x])) break;
        }
        if (x < N) break;
        memset(vis, 0, sizeof(vis));
        bool res = dfs(0, N - 1, 0);
        puts(res ? "WIN" : "LOSE");
    }
    
    return 0;
}