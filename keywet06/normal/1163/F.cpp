#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using int64 = long long;

const int N = 200005, M = 400005;
const int64 inf = 0x3c3c3c3c3c3c3c3cLL;

char Book[N], Path[N];

int n, m, MId, Cnt;
int Head[N], Next[M], To[M];
int p[N], Left[N], Right[N], Id[N];

int64 w[M];
int64 d[2][N];

inline void ist(int aa, int ss, int64 ww) {
    To[Cnt] = ss;
    Next[Cnt] = Head[aa];
    Head[aa] = Cnt;
    w[Cnt] = ww;
    ++Cnt;
}

struct ST {
    int Id;
    int64 d;
    ST(int id_ = 0, int64 d_ = 0) : Id(id_), d(d_) {}
    bool operator<(const ST& rhs) const { return d > rhs.d; }
};

struct Edge {
    int u, v;
    int64 w;
} e[M];

struct Node {
    int lef, rig;
    int64 mn;
} tree[N * 4];

inline void Dijkstra(int start, int64* d, int type = -1) {
    memset(d, 0x3c, sizeof(d[0]) * (n + 2));
    memset(Book, 0, sizeof Book);
    d[start] = 0;
    p[start] = -1;
    std::priority_queue<ST> hp;
    hp.push(ST(start, 0));
    ST k;
    while (!hp.empty()) {
        k = hp.top();
        hp.pop();
        if (k.d > d[k.Id] || Book[k.Id]) continue;
        Book[k.Id] = 1;
        for (int j = Head[k.Id]; j != -1; j = Next[j]) {
            if (d[To[j]] > d[k.Id] + w[j]) {
                d[To[j]] = d[k.Id] + w[j];
                p[To[j]] = j / 2 + 1;
                hp.push(ST(To[j], d[To[j]]));
                if (type == 0 && !Path[To[j]]) {
                    Left[To[j]] = Left[k.Id];
                } else if (type == 1 && !Path[To[j]]) {
                    Right[To[j]] = Right[k.Id];
                }
            }
        }
    }
}

void Build(int p, int lef, int rig) {
    tree[p].lef = lef;
    tree[p].rig = rig;
    tree[p].mn = inf;
    if (lef == rig) return;
    int mid = (lef + rig) / 2;
    Build(p * 2, lef, mid);
    Build(p * 2 + 1, mid + 1, rig);
}

void upd(int p, int ql, int qr, const int64& val) {
    if (ql > qr) return;
    if (tree[p].lef == ql && tree[p].rig == qr) {
        tree[p].mn = std::min(tree[p].mn, val);
        return;
    }
    int mid = (tree[p].lef + tree[p].rig) / 2;
    if (qr <= mid) {
        upd(p * 2, ql, qr, val);
    } else if (ql > mid) {
        upd(p * 2 + 1, ql, qr, val);
    } else {
        upd(p * 2, ql, mid, val);
        upd(p * 2 + 1, mid + 1, qr, val);
    }
}

int64 qry(int p, const int& pos) {
    if (tree[p].lef == tree[p].rig) {
        return tree[p].mn;
    }
    int64 tans;
    int mid = (tree[p].lef + tree[p].rig) / 2;
    if (pos <= mid) {
        tans = qry(p * 2, pos);
    } else {
        tans = qry(p * 2 + 1, pos);
    }
    return std::min(tree[p].mn, tans);
}

int main() {
    memset(Head, -1, sizeof Head);
    int q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
        ist(e[i].u, e[i].v, e[i].w);
        ist(e[i].v, e[i].u, e[i].w);
    }

    Dijkstra(n, d[1]);
    int64 minDis = d[1][1];

    int cur = 1;
    MId = 0;
    Left[1] = 0;
    Right[1] = 1;
    Path[1] = 1;
    while (cur != n) {
        ++MId;
        Id[p[cur]] = MId;
        cur = e[p[cur]].u ^ e[p[cur]].v ^ cur;
        Left[cur] = MId;
        Right[cur] = MId + 1;
        Path[cur] = 1;
    }

    Dijkstra(1, d[0], 0);
    Dijkstra(n, d[1], 1);

    Build(1, 1, MId);

    for (int i = 1; i <= m; ++i) {
        if (Id[i]) continue;
        int64 tem1 = d[0][e[i].u] + e[i].w + d[1][e[i].v];
        int64 tem2 = d[0][e[i].v] + e[i].w + d[1][e[i].u];
        upd(1, Left[e[i].u] + 1, Right[e[i].v] - 1, tem1);
        upd(1, Left[e[i].v] + 1, Right[e[i].u] - 1, tem2);
    }

    int t1;
    int64 t2, ans;
    while (q--) {
        scanf("%d%lld", &t1, &t2);
        if (Id[t1]) {
            if (t2 < e[t1].w) {
                ans = minDis - (e[t1].w - t2);
            } else {
                ans = minDis + (t2 - e[t1].w);
                int64 tans = qry(1, Id[t1]);
                ans = std::min(ans, tans);
            }
        } else {
            if (t2 >= e[t1].w) {
                ans = minDis;
            } else {
                ans = std::min(minDis, d[0][e[t1].u] + t2 + d[1][e[t1].v]);
                ans = std::min(ans, d[0][e[t1].v] + t2 + d[1][e[t1].u]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}