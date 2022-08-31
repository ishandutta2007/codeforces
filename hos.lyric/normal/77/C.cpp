//  Codeforces Beta Round #69

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

#define MAX 200010

int N, R;
Int A[MAX];
int m, ptr[MAX], next[MAX], zu[MAX];
int par[MAX];

int uslen, us[MAX];
Int dp[MAX], dp2[MAX];
Int cslen, cs[MAX];

void dfs(int u, int oy) {
    int i, v;
    par[u] = oy;
    for (i = ptr[u]; ~i; i = next[i]) if ((v = zu[i]) != oy) {
        dfs(v, u);
    }
    us[uslen++] = u;
}
void solve(int u) {
    int i, v;
    Int a = A[u], b = 0;
    cslen = 0;
    for (i = ptr[u]; ~i; i = next[i]) if ((v = zu[i]) != par[u]) {
        cs[cslen++] = dp[v];
        b += dp2[v];
    }
    sort(cs, cs + cslen, greater<Int>());
    dp[u] = 1;
    --a;
    for (i = 0; i < cslen && a; ++i) {
        dp[u] += 1 + cs[i];
        --a;
    }
    Int tmp = min(a, b);
    dp[u] += tmp * 2;
    dp2[u] = a - tmp;
}

int main() {
    int i, u, v;
    
    for (; ~scanf("%d", &N); ) {
        for (u = 0; u < N; ++u) {
            A[u] = in();
        }
        m = 0;
        memset(ptr, ~0, N << 2);
        for (i = 1; i < N; ++i) {
            u = in() - 1;
            v = in() - 1;
            next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
            next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
        }
        R = in() - 1;
        uslen = 0;
        dfs(R, -1);
//pv(us,us+uslen);
        ++A[R];
        for (i = 0; i < N; ++i) {
            solve(us[i]);
        }
//cout<<"dp:  ";pv(dp,dp+N);cout<<"dp2: ";pv(dp2,dp2+N);
        Int ans = dp[R] - 1;
        cout << ans << endl;
    }
    
    return 0;
}