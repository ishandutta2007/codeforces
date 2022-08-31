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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

namespace SA {
    #define MAXN 100010
    int n;
    char t[MAXN];
    int ki[MAXN], ik[MAXN], is[MAXN], hh;
    bool cmp(const int &a, const int &b) {
        return (a == b) ? 0 : (ik[a] != ik[b]) ? (ik[a] < ik[b]) : (ik[a + hh] < ik[b + hh]);
    }
    void makeSA() {
        n = strlen(t);
        int i;
        for (i = 0; i <= n; ++i) ik[ki[i] = i] = t[i];
        is[0] = is[n] = hh = 0;
        sort(ki, ki + n + 1, cmp);
        for (hh = 1; is[n] != n; hh <<= 1) {
            sort(ki, ki + n + 1, cmp);
            for (i = 0; i < n; ++i) is[i + 1] = is[i] + (cmp(ki[i], ki[i + 1]) ? 1 : 0);
            for (i = 0; i <= n; ++i) ik[ki[i]] = is[i];
        }
    }
    int lcp[MAXN];
    void makeHA() {
        int h = 0, i, j;
        for (i = 0; i < n; ++i) {
            for (j = ki[ik[i] - 1]; t[j + h] == t[i + h]; ++h);
            lcp[ik[i] - 1] = h;
            if (h) --h;
        }
    }
}

Int score(Int x) { return x * (x - 1) / 2; }
int uf[MAXN];
Int as[MAXN];
Int now;

int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    now -= score(as[x]) + score(as[y]);
    uf[x] += uf[y]; uf[y] = x;
    as[x] += as[y];
    now += score(as[x]);
    return 1;
}

int N;
int A[MAXN];
pint ps[MAXN];

int main() {
    int i, k;
    
    for (; ~scanf("%s", SA::t); ) {
        SA::makeSA();
        SA::makeHA();
        N = SA::n;
        for (i = 0; i < N; ++i) {
            A[i] = SA::lcp[i];
        }
//cout<<"A : ";pv(A,A+N);
        for (i = 0; i < N; ++i) {
            ps[i] = mp(A[i], i);
        }
        sort(ps, ps + N, greater<pint>());
        Int ans = (Int)N * (N + 1) / 2;
        for (i = 0; i <= N; ++i) {
            as[i] = 1;
            uf[i] = -1;
        }
        now = 0;
        for (i = 0, k = N; k > 0; --k) {
            for (; i < N && ps[i].first == k; ++i) {
                conn(ps[i].second, ps[i].second + 1);
            }
//cout<<"uf : ";pv(uf,uf+N+1);
//cout<<"now = "<<now<<endl;
            ans += now;
        }
        cout << ans << endl;
    }
    
    return 0;
}