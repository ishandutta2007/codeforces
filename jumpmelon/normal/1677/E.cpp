#include <bits/stdc++.h>

using namespace std;

typedef long long big;

int n;

struct null_tag { };
extern struct node *null;

struct node_data {
    big tag, sum;
    node_data() : tag(0), sum(0) { }

    void add(big v, big len) {
        tag += v;
        sum += len * v;
    }

    void maintain(const node_data &l, const node_data &r, big len) {
        sum = l.sum + r.sum + len * tag;
    }
};

struct node {
    node_data k, b;
    node *ls, *rs;

    node(null_tag) : ls(this), rs(this) { }

    static node *&copy(node *&p) {
        if (p == null)
            p = new node(*p);
        return p;
    }

    void maintain(int l, int r) {
        k.maintain(ls->k, rs->k, r - l + 1);
        b.maintain(ls->b, rs->b, r - l + 1);
    }

    void add(int x, int y, big vk, big vb, int l = 1, int r = n) {
        if (x <= l && r <= y) {
            k.add(vk, r - l + 1);
            b.add(vb, r - l + 1);
        } else {
            int mid = (l + r) >> 1;
            if (x <= mid)
                copy(ls)->add(x, y, vk, vb, l, mid);
            if (y > mid)
                copy(rs)->add(x, y, vk, vb, mid + 1, r);
            maintain(l, r);
        }
    }

    big query(int x, int y, big T, int l = 1, int r = n) {
        if (x <= l && r <= y) {
            return k.sum * T + b.sum;
        } else {
            int mid = (l + r) >> 1;
            big t = (k.tag * T + b.tag) * (y - x + 1);
            if (y <= mid)
                return ls->query(x, y, T, l, mid) + t;
            else if (x > mid)
                return rs->query(x, y, T, mid + 1, r) + t;
            else
                return ls->query(x, mid, T, l, mid) + rs->query(mid + 1, y, T, mid + 1, r) + t;
        }
    }
};

node *null = new node(null_tag());

const int MAXN = 200000;
int P[MAXN + 1], Pos[MAXN + 1];
node *Root[MAXN + 1];

int St[MAXN + 1], ML[MAXN + 1], MR[MAXN + 1];

struct event {
    int pos, lx, ly;
    big k, b;
};

vector<event> E;

bool operator <(const event &a, const event &b) {
    return a.pos < b.pos;
}

const int MAXQ = 1000000;
struct qry_t { int id, x, y; } Q[MAXQ + 1];
big Ans[MAXQ + 1];

int main() {
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        Pos[P[i]] = i;
    }

    int *top = St;
    *top = 0;
    for (int i = 1; i <= n; i++) {
        while (top > St && P[*top] < P[i])
            top--;
        ML[i] = *top;
        *++top = i;
    }

    top = St;
    *top = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top > St && P[*top] < P[i])
            top--;
        MR[i] = *top;
        *++top = i;
    }

    vector<pair<int, int>> *V = new vector<pair<int,int>>[n + 1];

    for (int a = 1; a * (a + 1) <= n; a++)
        for (int b = a + 1; a * b <= n; b++) {
            int i = Pos[a], j = Pos[b], k = Pos[a * b];
            if (i > j)
                swap(i, j);
            int lx = ML[k] + 1, ly = min(i, k);
            int rx = max(k, j), ry = MR[k] - 1;
            if (lx <= ly && rx <= ry) {
                V[k].push_back({ly, rx});
            }
        }
    
    for (int k = 1; k <= n; k++)
        if (!V[k].empty()) {
            sort(V[k].begin(), V[k].end(), [](auto &&a, auto &&b) {
                return a.first > b.first;
            });
            int lx = ML[k] + 1, ry = MR[k] - 1;
            int rx = ry + 1, prv = k;
            for (auto &&e : V[k]) {
                int ly = e.first;
                if (ly + 1 <= prv && rx <= ry) {
                    E.push_back({rx, ly + 1, prv, 1, -rx + 1});
                    E.push_back({ry, ly + 1, prv, -1, ry});
                }
                rx = min(rx, e.second);
                prv = ly;
            }
            if (lx <= prv && rx <= ry) {
                E.push_back({rx, lx, prv, 1, -rx + 1});
                E.push_back({ry, lx, prv, -1, ry});
            }
        }
    
    delete[] V;
    
    sort(E.begin(), E.end());

    auto p = E.begin();
    Root[0] = null;

    for (int i = 0; i < q; i++) {
        Q[i].id = i;
        scanf("%d%d", &Q[i].x, &Q[i].y);
    }
    sort(Q, Q + q, [](auto &&a, auto &&b) { return a.y < b.y; });

    int qp = 0;
    for (int i = 1; i <= n; i++) {
        Root[i] = Root[i - 1];
        node::copy(Root[i]);
        while (p != E.end() && p->pos == i) {
            Root[i]->add(p->lx, p->ly, p->k, p->b);
            p++;
        }
        while (qp < q && Q[qp].y == i) {
            Ans[Q[qp].id] = Root[i]->query(Q[qp].x, Q[qp].y, i);
            qp++;
        }
    }

    for (int i = 0; i < q; i++)
        printf("%lld\n", Ans[i]);
    return 0;
}