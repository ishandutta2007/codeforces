#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
const int maxn = 500500;
const int sz = 1<<18;

int n, q;
int p[maxn], rk[maxn];
int get(int x) { return x == p[x] ? x : (p[x] = get(p[x])); }
void unite(int x, int y) {
    x = get(x); y = get(y);
    if (x != y) {
        if (rk[x] == rk[y]) ++rk[x];
        if (rk[x] > rk[y]) p[y] = x;
        else p[x] = y;
    }
}
void init() {
    forn(i, maxn) p[i] = i;
}

int rmq[maxn];
int b[maxn];

void join_st(int v) {
    if (v >= sz || b[v]) return;
    b[v] = 1;
    unite(v, v*2);
    unite(v, v*2+1);
    join_st(v*2);
    join_st(v*2+1);
}

void useg(int l, int r) {
    vector<int> buf;
    l += sz; r += sz;
    while (l < r) {
        if (l % 2 == 1) buf.push_back(l);
        if (r % 2 == 0) buf.push_back(r);
        l = (l+1) / 2;
        r = (r-1) / 2;
    }
    if (l == r) {
        buf.push_back(l);
    }
    forn(i, buf.size()) {
        join_st(buf[i]);
        if (i) unite(buf[i], buf[i-1]);
    }
}

void gen() {
    freopen("input.txt", "w", stdout);
    printf("200000 500000\n");
    int n = 200000;
    forn(i, 500000) {
        int x = rand()%n;
        int y = rand()%n;
        if (x > y) swap(x, y);
        printf("%d %d %d\n", rand()%3+1, x+1, y+1);
    }
}

void solve() {
    int t, x, y;
    forn(I, q) {
        scanf("%d%d%d", &t, &x, &y); --x; --y;
        if (t == 1) {
            unite(x+sz, y+sz);
        } else if (t == 2) {
            useg(x, y);
        } else {
            printf("%s\n", get(x+sz) == get(y+sz) ? "YES" : "NO");
        }
    }
}

int main() {
    //gen();
    //return 0;
#ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &q);
    init();
    solve();

    return 0;
}