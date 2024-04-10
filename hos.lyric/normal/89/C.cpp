//  Codeforces Beta Round #74

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

string CS = "DRUL";
int dx[] = { 1, 0, -1, 0, };
int dy[] = { 0, 1, 0, -1, };

char buf[10010];

int M, N;
string S[5010];
int to[20010];
bool is[20010];

int _(int x, int y, int h) {
    if (0 <= x && x < M && 0 <= y && y < N) return (x * N + y) * 4 + h;
    return M * N * 4;
}
int too(int u) {
    return is[to[u]] ? to[u] : (to[u] = too(to[u]));
}
int solve(int SX, int SY) {
//cout<<"solve "<<SX<<" "<<SY<<endl;
    int x, y, h;
    for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
        for (h = 0; h < 4; ++h) {
            to[_(x, y, h)] = _(x + dx[h], y + dy[h], h);
            is[_(x, y, h)] = (S[x][y] != '.');
        }
    }
    is[M * N * 4] = 1;
    int ret = 0;
    int u = _(SX, SY, 0);
    for (; ; ) {
        if (u == M * N * 4) break;
        ++ret;
        x = u / 4 / N;
        y = u / 4 % N;
//cout<<x<<" "<<y<<endl;
        for (h = 0; h < 4; ++h) {
            is[_(x, y, h)] = 0;
        }
        u = _(x, y, CS.find(S[x][y]));
        u = too(u);
    }
    return ret;
}

int main() {
    int x, y;
    
    for (; ~scanf("%d%d", &M, &N); ) {
        for (x = 0; x < M; ++x) {
            scanf("%s", buf);
            S[x] = buf;
        }
        int dai = 0, cnt = 0;
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (S[x][y] != '.') {
            int tmp = solve(x, y);
            if (dai < tmp) {
                dai = tmp;
                cnt = 0;
            }
            if (dai == tmp) {
                ++cnt;
            }
        }
        printf("%d %d\n", dai, cnt);
    }
    
    return 0;
}