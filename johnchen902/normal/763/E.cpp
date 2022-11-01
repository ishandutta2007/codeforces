#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Dj {
    int ans;
    int a[100000];
    void init(int n) {
        ans = 0;
        fill_n(a, n, -1);
    }
    int find(int x) {
        return a[x] == -1 ? x : (a[x] = find(a[x]));
    }
    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            ans++;
            a[x] = y;
        }
    }
};
struct Dj2 {
    Dj dj;
    int curd, ans;
    int d[100000], a[100000];
    void init(int n) {
        dj.init(n);
        curd = 1;
        ans = 0;
        fill_n(d, n, 0);
    }
    void reset() {
        curd++;
        ans = 0;
    }
    int find(int x) {
        return d[x] != curd ? x : (a[x] = find(a[x]));
    }
    void join(int x, int y) {
        x = find(dj.find(x));
        y = find(dj.find(y));
        if(x != y) {
            d[x] = curd;
            a[x] = y;
            ans++;
        }
    }
    int getans() const {
        return ans + dj.ans;
    }
};
constexpr int blk = 317;
static_assert(blk * blk >= 100000);
struct Q {
    int l, r, id;
    bool operator < (Q rhs) const {
        if(l / blk != rhs.l / blk)
            return l / blk < rhs.l / blk;
        return r < rhs.r;
    }
};
vector<int> adj[100000];
Q qry[100000];
int ans[100000];
Dj2 dj2;

int main() {
    int n, m;
    scanf("%d %*d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        qry[i] = Q{l, r, i};
    }
    sort(qry, qry + q);
    for(int i = 0, cut = -1, lr = 0; i < q; i++) {
        if(cut <= qry[i].l) {
            lr = cut = (qry[i].l / blk + 1) * blk;
            dj2.init(n);
        }
        if(qry[i].r < cut) {
            for(int j = qry[i].l; j < qry[i].r; j++)
                for(int v : adj[j])
                    if(j <= v && v < qry[i].r)
                        dj2.join(j, v);
        } else {
            for(; lr < qry[i].r; lr++)
                for(int v : adj[lr])
                    if(cut <= v && v < lr)
                        dj2.dj.join(v, lr);
            for(int j = qry[i].l; j < cut; j++)
                for(int v : adj[j])
                    if(j <= v && v < qry[i].r)
                        dj2.join(j, v);
        }
        ans[qry[i].id] = qry[i].r - qry[i].l - dj2.getans();
        dj2.reset();
    }

    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
}