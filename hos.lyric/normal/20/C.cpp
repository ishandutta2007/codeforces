//  Codeforces Alpha Round #20
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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

#define MAXN 100010
#define MAXM 200010

int N, M;
int m, ptr[MAXN], next[MAXM], zu[MAXM], ca[MAXM];
Int d[MAXN];
int prev[MAXN];
int que[MAXN], *qb, *qe;

int main() {
    int i, u, v;
    Int c;
    
    N = in();
    M = in();
    memset(ptr, ~0, N << 2);
    for (; M--; ) {
        u = in() - 1;
        v = in() - 1;
        c = in();
        next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ca[m] = c; ++m;
        next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ca[m] = c; ++m;
    }
    priority_queue< pair<Int,int>,vector< pair<Int,int> >,greater< pair<Int,int> > > q;
    memset(d, 0x3f, N << 3);
    memset(prev, ~0, N << 2);
    d[N - 1] = 0;
    prev[N - 1] = -2;
    q.push(mp(0, N - 1));
    for (; !q.empty(); ) {
        c = q.top().first;
        u = q.top().second;
        q.pop();
        if (u == 0) break;
        if (d[u] == c) {
            for (i = ptr[u]; ~i; i = next[i]) {
                v = zu[i];
                if (d[v] > c + ca[i]) {
                    d[v] = c + ca[i];
                    prev[v] = u;
                    q.push(mp(d[v], v));
                }
            }
        }
    }
    if (!~prev[0]) {
        puts("-1");
        return 0;
    }
    printf("1");
    for (u = 0; (u = prev[u]) >= 0; ) {
        printf(" %d", u + 1);
    }
    puts("");
    
    return 0;
}