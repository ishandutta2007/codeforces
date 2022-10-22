#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

int L = -1e5, R = 1e5 + 1;

struct line{
    long long k, b;
    line() : k(0), b(1e18) {}
    line(long long k, long long b) : k(k), b(b) {}
};

struct node{
    line x;
    node* l;
    node* r;
    node() : x(), l(nullptr), r(nullptr) {}
    node(line t) : x(t), l(nullptr), r(nullptr) {}
};

typedef node* pnode;

long long get(line t, long long x) {
    return t.k * x + t.b;
}

void update(pnode t) {
    if (!t->l) t->l = new node();
    if (!t->r) t->r = new node();
}

void update(pnode t, int l, int r, line x) {
    if (x.b == 1e18) return;
    update(t);
    int m = (l + r - (l + r) % 2) / 2;
    if (get(t->x, m) > get(x, m)) {
        swap(t->x, x);
    }
    if (l + 1 != r) {
        if (x.k < t->x.k) {
            update(t->r, m, r, x);
        }
        else {
            update(t->l, l, m, x);
        }
    }
}

long long get(pnode t, int l, int r, long long x) {
    update(t);
    if (l + 1 == r) {
        return get(t->x, x);
    }
    int m = (l + r - (l + r) % 2) / 2;
    if (x < m) {
        return min(get(t->x, x), get(t->l, l, m, x));
    }
    else {
        return min(get(t->x, x), get(t->r, m, r, x));
    }
}

long long ans[100000];
int a[100000], b[100000], sz[100000], ind[100000];
pnode dp[100000];
vector<int> g[100000];

void get_sz(int v, int pr) {
    sz[v] = 1;
    for (auto x : g[v]) {
        if (x != pr) {
            get_sz(x, v);
            sz[v] += sz[x];
        }
    }
}

void merge(pnode x, pnode t) {
    if (!x) return;
    merge(x->l, t);
    merge(x->r, t);
    if (x->x.b != 1e18) {
        update(t, L, R, x->x);
    }
}

void dfs(int v, int pr) {
    if (sz[v] == 1) {
        ans[v] = 0;
        dp[v] = new node(line(b[v], 0));
        ind[v] = v;
        return;
    }
    int j = -1;
    for (auto x : g[v]) {
        if (x != pr) {
            dfs(x, v);
            if (j == -1 || sz[x] > sz[j]) j = x;
        }
    }
    ind[v] = ind[j];
    for (auto x : g[v]) {
        if (x != pr && x != j) {
            merge(dp[ind[x]], dp[ind[v]]);
        }
    }
    ans[v] = get(dp[ind[v]], L, R, a[v]);
    update(dp[ind[v]], L, R, line(b[v], ans[v]));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    get_sz(0, -1);
    dfs(0, -1);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}