//  Yandex.Algorithm 2011 Finals

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

const int A = 7;
const int K = 28;

int M, N;
char S[110][110];
int is[110][110];
int L;
int ls[110][110];
int xs[110], ys[110];

int psLen[110], ps[110][110];
int vis[110][110];
int as[110];
int ans;
char cs[110][110];

void dfs(int l) {
//cout<<"dfs. ";cout<<"as : ";pv(as,as+l);
    if (l == L) {
//cout<<"dfs. ";cout<<"as : ";pv(as,as+l);
        if (++ans == 1) {
            int x, y;
            for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
                cs[x][y] = ~ls[x][y] ? ('0' + as[ls[x][y]]) : '.';
            }
        }
        return;
    }
    int k;
    int dx, dy;
    int aMax = l ? *max_element(as, as + l) : -1;
    for (int &a = as[l] = 0; a < A && a <= aMax + 1; ++a) {
        for (dx = 0; dx < 2; ++dx) for (dy = 0; dy < 2; ++dy) {
            k = is[xs[l] + dx][ys[l] + dy];
            ps[k][psLen[k]++] = a;
        }
        bool ok = 1;
        set<int> checked;
        for (dx = 0; dx < 2; ++dx) for (dy = 0; dy < 2; ++dy) {
            k = is[xs[l] + dx][ys[l] + dy];
            if (checked.insert(k).second) {
                if (psLen[k] == 2) {
                    int b0 = ps[k][0], b1 = ps[k][1];
                    if (b0 > b1) swap(b0, b1);
                    if (vis[b0][b1]) ok = 0;
                    ++vis[b0][b1];
                }
            }
        }
//if(!ok)cout<<"not ok a = "<<a<<endl;
        if (ok) {
            dfs(l + 1);
        }
        checked.clear();
        for (dx = 0; dx < 2; ++dx) for (dy = 0; dy < 2; ++dy) {
            k = is[xs[l] + dx][ys[l] + dy];
            if (checked.insert(k).second) {
                if (psLen[k] == 2) {
                    int b0 = ps[k][0], b1 = ps[k][1];
                    if (b0 > b1) swap(b0, b1);
                    if (vis[b0][b1]) ok = 0;
                    --vis[b0][b1];
                }
            }
        }
        for (dx = 0; dx < 2; ++dx) for (dy = 0; dy < 2; ++dy) {
            k = is[xs[l] + dx][ys[l] + dy];
            --psLen[k];
        }
    }
}

int main() {
    int x, y;
    
    for (; ~scanf("%d%d", &M, &N); ) {
        for (x = 0; x < M; ++x) {
            scanf("%s", S[x]);
        }
        memset(is, ~0, sizeof(is));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (S[x][y] != '.') {
            is[x][y] = islower(S[x][y]) ? (S[x][y] - 'a') : (26 + S[x][y] - 'A');
        }
        memset(ls, ~0, sizeof(ls));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (~is[x][y]) if (!~ls[x][y]) {
            xs[L] = x;
            ys[L] = y;
            ls[x][y] = ls[x][y + 1] = ls[x + 1][y] = ls[x + 1][y + 1] = L++;
        }
//for(x=0;x<M;++x)pv(ls[x],ls[x]+N);
assert(K==L*2);
        memset(psLen, 0, sizeof(psLen));
        memset(vis, 0, sizeof(vis));
        ans = 0;
        dfs(0);
        printf("%d\n", ans * 5040);
        for (x = 0; x < M; ++x) {
            cs[x][N] = 0;
            puts(cs[x]);
        }
    }
    
    return 0;
}