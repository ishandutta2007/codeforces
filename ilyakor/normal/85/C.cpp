#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const int maxn = 218 * 1000;

int par[maxn];
int y[maxn];

int M[maxn], m[maxn];

vi g[maxn];

int64 d[maxn];
int dc[maxn];

void dfs(int x) {
    M[x] = m[x] = y[x];
    if (sz(g[x]) && y[g[x][0]] > y[g[x][1]])
        swap(g[x][0], g[x][1]);
    for (int i = 0; i < sz(g[x]); ++i) {
        int t = g[x][i];
        dfs(t);
        M[x] = max(M[x], M[t]);
        m[x] = min(m[x], m[t]);
    }
}

void go(int x) {
    if (d[x] != -1) return;
    int p = par[x];
    if (p == -1) d[x] = 0, dc[x] = 0;
    else {
        go(p);
        d[x] = d[p], dc[x] = dc[p];
    }
    if (p == -1) return;
    if (y[p] > y[x])
        d[x] += m[g[p][1]], dc[x]++;
    else
        d[x] += M[g[p][0]], dc[x]++;
}

map<int, int> md;

int main() {
    int n;
    cin >> n;
    int r = 0;
    vi v;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &par[i], &y[i]);
        if (par[i] != -1) {
            --par[i];
            g[par[i]].pb(i);
        } else r = i;
        md[y[i]] = i;
        v.pb(y[i]);
    }
    sort(all(v));
    dfs(r);
    memset(d, -1, sizeof(d));
    for (int i = 0; i < n; ++i)
        if (d[i] == -1) go(i);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        int ind = lower_bound(all(v), x) - v.begin();
        if (ind >= sz(v)) --ind;
        int vind = md[v[ind]];
        if (sz(g[vind])) {
            --ind;
            vind = md[v[ind]];
        }
        int64 res = d[vind];
        int cnt = dc[vind];
        //res += y[vind];
        //++cnt;
        double rd = (res + 0.) / cnt;
        printf("%.10lf\n", rd);
    }
    return 0;
}