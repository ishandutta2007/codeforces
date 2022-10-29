#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 1e4;
const int inf = 0x3f3f3f3f;

struct Tree {
    int ch[N * 42][2], tot;
    int val[N * 42];

    bool isleft;

    Tree(bool isleft) {
        this->isleft = isleft;
    }

    void init() {
        tot = 0;
    }

    int update(int a, int b) {
        return max(a, b);
    }

    int build(int l, int r) {  // 
        int p = ++tot;
        if (l == r) {
            //
            val[p] = -inf;
            return p;
        }
        int mid = (l + r) >> 1;
        ch[p][0] = build(l, mid);
        ch[p][1] = build(mid + 1, r);
        val[p] = update(val[ch[p][0]], val[ch[p][1]]);
        return p;  // 
    }

    int modify(int pre, int l, int r, int pos, int v) {  // 
        int now = ++tot;
        ch[now][0] = ch[pre][0], ch[now][1] = ch[pre][1];
        if (l == r) {
            val[now] = v;
            return now;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            ch[now][0] = modify(ch[now][0], l, mid, pos, v);
        else
            ch[now][1] = modify(ch[now][1], mid + 1, r, pos, v);
        val[now] = update(val[ch[now][0]], val[ch[now][1]]);
        return now;
    }

    int query(int now, int l, int r, int ql, int qr, int bot) {  // 
        if (isleft) {
            if (val[now] < bot) return -inf;
            if (r < ql || qr < l) return -inf;
            if (l == r) return l;
            int mid = (l + r) >> 1;
            int rv = query(ch[now][1], mid + 1, r, ql, qr, bot);
            if (rv != -inf) return rv;
            else return query(ch[now][0], l, mid, ql, qr, bot);
        } else {
            if (val[now] < bot) return inf;
            if (r < ql || qr < l) return inf;

            if (l == r) return l;
            int mid = (l + r) >> 1;
            int lv = query(ch[now][0], l, mid, ql, qr, bot);
            if (lv != inf) return lv;
            else return query(ch[now][1], mid + 1, r, ql, qr, bot);
        }
    }
//rt[]!!!
} tl(1), tr(0);

int p[N], pl[N], pr[N];
int dis[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
//        n = 20, a = 1, b = n;
        tl.init(), tr.init();
        for (int i = 1; i <= n; i++) dis[i] = -inf;
        int lrt = tl.build(1, n);
        int rrt = tr.build(1, n);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
//            p[i] = rand() % 5 + 1;
            pl[i] = p[i] + i;
            pr[i] = p[i] - i;
            lrt = tl.modify(lrt, 1, n, i, pl[i]);
            rrt = tr.modify(rrt, 1, n, i, pr[i]);
        }
        queue<int> que;
        que.push(a);
        dis[a] = 0;
        lrt = tl.modify(lrt, 1, n, a, -inf);
        rrt = tr.modify(rrt, 1, n, a, -inf);
        while (!que.empty()) {
            int q = que.front();
            que.pop();

            while (q != 1) {
                int pos = tl.query(lrt, 1, n, max(1, q - p[q]), q - 1, q);
                if (pos == -inf) break;
                dis[pos] = dis[q] + 1;
                que.push(pos);
                rrt = tr.modify(rrt, 1, n, pos, -inf);
                lrt = tl.modify(lrt, 1, n, pos, -inf);
            }

            while (q != n) {
                int pos = tr.query(rrt, 1, n, q + 1, min(n, q + p[q]), -q);
                if (pos == inf) break;
                dis[pos] = dis[q] + 1;
                que.push(pos);
                rrt = tr.modify(rrt, 1, n, pos, -inf);
                lrt = tl.modify(lrt, 1, n, pos, -inf);
            }
        }
        cout << dis[b] << endl;
    }
}

//3
//10 2 9
//4 1 1 1 5 1 1 1 1 5