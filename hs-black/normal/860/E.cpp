#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
    if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
    static short st[30]; short tp = 0;
    if (x < 0) putchar('-'), x = -x;
    do st[++tp] = x % 10, x /= 10; while (x);
    while (tp) putchar(st[tp--] | '0');
    putchar(ed);
}

#define ll long long
#include <vector>
const int N = 505000;

struct node {
    ll d;
    int id;
    bool operator < (const node &i) const { return id < i.id; }
    node (ll D = 0, int I = 0) : d(D), id(I) {}
};

vector<vector<node> > vec;
vector<node> ety;
int ne[N<<1], to[N<<1], h[N], f[N], rt, tot, n;
inline void add(int x, int y) {
    ne[++tot] = h[x], to[h[x] = tot] = y;
}

int dep[N], L[N], R[N], cnt;
int son[N], mxd[N], rev[N];
ll ans[N];
void dfs1(int x, int fa) {
    mxd[x] = dep[x] = dep[fa] + 1, L[x] = ++cnt, rev[cnt] = x;
    if (dep[x] >= vec.size()) vec.push_back(ety);
    vec[dep[x]].push_back(node(0, L[x]));
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; dfs1(to[i], x);
        if (mxd[y] >= mxd[x]) son[x] = y, mxd[x] = mxd[y];
    }
    R[x] = cnt;
}

inline bool inc(int x, int l, int r) { return R[x] >= r && L[x] <= l; }
ll tab[N], t[N];
void dfs2(int x) {
    int ct = 0, nw = dep[x];
    ll res = 0; t[dep[x]]++;
    auto pl = lower_bound(vec[dep[x]].begin(), vec[dep[x]].end(), node(0, L[x])), pr = pl; ++pr;
    while ("jzpakioi", true) {
        res += 1ll * (ct += t[nw]) * (pr - pl) + tab[nw];
//        write(pr - pl);
        tab[nw] = t[nw] = 0, pl -> d += res;
        if (pr != vec[nw].end()) pr -> d -= res;
        if (++nw > mxd[x]) break;
        pl = lower_bound(vec[nw].begin(), vec[nw].end(), node(0, L[x]));
        pr = upper_bound(vec[nw].begin(), vec[nw].end(), node(0, R[x]));
        if (inc(son[x], pl -> id, (pr - 1) -> id)) { t[nw] += ct, tab[nw] += res; break; }
    }
    if (son[x]) dfs2(son[x]);
    for (int i = h[x]; i; i = ne[i]) 
        if (to[i] != son[x]) dfs2(to[i]);
}

int main() {
    read(n), vec.push_back(ety);
    for (int i = 1;i <= n; i++) 
        read(f[i]), f[i] ? add(f[i], i), 0 : rt = i;
    dfs1(rt, 0), dfs2(rt);
    for (int i = 1;i <= mxd[rt]; i++) {
    	ll res = 0;
    	for (auto t: vec[i])
    		res += t.d, ans[rev[t.id]] += res;
    }
    for (int i = 1;i <= n; i++) write(ans[i] - dep[i], ' ');
    return 0;
}