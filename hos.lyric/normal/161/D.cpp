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

#define MAXN  50010
#define MAXM 100010

int N, K;
int m, ptr[MAXN], next[MAXM], zu[MAXM], ca[MAXM];
Int ans;
int fort[MAXN], size[MAXN];
int len0, len1, dist0[MAXN], dist1[MAXN];

void sizes(int u, int oy) {
    int i, v;
    size[u] = 1;
    for (i = ptr[u]; ~i; i = next[i]) if (!fort[v = zu[i]] && v != oy) {
        sizes(v, u);
        size[u] += size[v];
    }
}

void dists(int u, int oy, int d) {
    int i, v;
    if (d > K) return;
    ++ans;
    dist0[len0++] = dist1[len1++] = d;
    for (i = ptr[u]; ~i; i = next[i]) if (!fort[v = zu[i]] && v != oy) {
        dists(v, u, d + ca[i]);
    }
}

Int pairs(int len, int dist[]) {
    Int ret = 0;
    int a, b;
    sort(dist, dist + len);
    for (a = 0, b = len - 1; a < b; ++a) {
        for (; a < b && dist[a] + dist[b] > K; --b);
        ret += b - a;
    }
//cout<<ret<<"  ";pv(dist,dist+len);
    return ret;
}

void solve(int u) {
    int i, v, dai, vm;
    sizes(u, ~0);
    for (; ; ) {
        dai = 0;
        vm = ~0;
        for (i = ptr[u]; ~i; i = next[i]) if (!fort[v = zu[i]])  {
            if (dai < size[v]) {
                dai = size[v];
                vm = v;
            }
        }
        if (dai <= (size[u] >> 1)) break;
        size[u] -= size[vm];
        size[vm] += size[u];
        u = vm;
    }
    fort[u] = 1;
    for (i = ptr[u]; ~i; i = next[i]) if (!fort[v = zu[i]]) {
        solve(v);
    }
    len1 = 0;
    for (i = ptr[u]; ~i; i = next[i]) if (!fort[v = zu[i]]) {
        len0 = 0;
        dists(v, u, ca[i]);
        ans -= pairs(len0, dist0);
    }
    ans += pairs(len1, dist1);
    fort[u] = 0;
}

int main() {
    int i;
    int u, v, c;
    
    for (; ~scanf("%d%d", &N, &K); ) {
        // N = in();
        // K = in();
        // if (!(N | K)) break;
        memset(ptr, ~0, N << 2);
        m = 0;
        for (i = 1; i < N; ++i) {
            u = in() - 1;
            v = in() - 1;
            // c = in();
            c = 1;
            next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ca[m] = c; ++m;
            next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ca[m] = c; ++m;
        }
        
        Int ANS = 0;
        for (int p = 0; p < 2; ++p) {
            ans = 0;
            solve(0);
            ANS += ans * (p ? -1 : +1);
            --K;
        }
        cout << ANS << endl;
    }
    
    return 0;
}