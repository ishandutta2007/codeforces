#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct MCMF {
    struct E {
        int s, e, cap, all, cost;
    };
    vector<E> e;
    vector<int> adj[500];
    int add_edge(int s, int ed, int cap, int cost) {
        int idx = e.size();
        e.push_back({ s, ed, 0, cap, cost });
        adj[s].push_back(idx);
        adj[ed].push_back(~idx);
        return idx;
    }
    static const ll inf = 1e18;
    ll d[500];
    int p[500];
    bool in[500];
    void spfa(int s, int n) {
        for (int i = 1; i <= n; ++i) {
            d[i] = inf;
            p[i] = 0;
            in[i] = 0;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        in[s] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            in[x] = 0;
            for (int i : adj[x]) {
                if (i < 0) {
                    if (e[~i].cap == 0) continue;
                    ll nd = d[x] - e[~i].cost;
                    int c = e[~i].s;
                    if (nd < d[c]) {
                        d[c] = nd;
                        p[c] = i;
                        if (!in[c]) {
                            q.push(c);
                            in[c] = 1;
                        }
                    }
                }
                else {
                    if (e[i].cap == e[i].all) continue;
                    ll nd = d[x] + e[i].cost;
                    int c = e[i].e;
                    if (nd < d[c]) {
                        d[c] = nd;
                        p[c] = i;
                        if (!in[c]) {
                            q.push(c);
                            in[c] = 1;
                        }
                    }
                }
            }
        }
    }
    
    ll min_cost(int s, int ed, int n) {
        ll ans = 0;
        while (1) {
            spfa(s, n);
            if (d[ed] >= 0) break;
            ans += d[ed];
            for (int i = ed; i != s; ) {
                int ei = p[i];
                if (ei < 0) {
                    e[~ei].cap--;
                    i = e[~ei].e;
                }
                else {
                    e[ei].cap++;
                    i = e[ei].s;
                }
            }
        }
        return ans;
    }
} mcmf;

const int inf = 1e5;
int n1, n2, m, r, b;
char N1[205], N2[205];
int idxr[205], idxb[205];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n1 >> n2 >> m >> r >> b >> N1 + 1 >> N2 + 1;
    int n = n1 + n2 + 2;
    int s = 1, e = 2;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        idxr[i] = mcmf.add_edge(x + 2, y + 2 + n1, 1, r);
        idxb[i] = mcmf.add_edge(y + 2 + n1, x + 2, 1, b);
    }
    ll need = 0;
    for (int i = 1; i <= n1; ++i) {
        if (N1[i] == 'U') {
            mcmf.add_edge(s, i + 2, 500, 0);
            mcmf.add_edge(i + 2, e, 500, 0);
            continue;
        }
        need -= inf;
        if (N1[i] == 'R') {
            mcmf.add_edge(s, i + 2, 1, -inf);
            mcmf.add_edge(s, i + 2, 500, 0);
        }
        else {
            mcmf.add_edge(i + 2, e, 1, -inf);
            mcmf.add_edge(i + 2, e, 500, 0);
        }
    }
    for (int i = 1; i <= n2; ++i) {
        if (N2[i] == 'U') {
            mcmf.add_edge(s, i + n1 + 2, 500, 0);
            mcmf.add_edge(i + n1 + 2, e, 500, 0);
            continue;
        }
        need -= inf;
        if (N2[i] == 'B') {
            mcmf.add_edge(s, i + n1 + 2, 1, -inf);
            mcmf.add_edge(s, i + n1 + 2, 500, 0);
        }
        else {
            mcmf.add_edge(i + n1 + 2, e, 1, -inf);
            mcmf.add_edge(i + n1 + 2, e, 500, 0);
        }
    }
    ll ans = mcmf.min_cost(s, e, n) - need;
    if (ans >= inf) cout << -1;
    else {
        cout << ans << '\n';
        for (int i = 1; i <= m; ++i) {
            int r = idxr[i], b = idxb[i];
            if (mcmf.e[r].cap) cout << 'R';
            else if (mcmf.e[b].cap) cout << 'B';
            else cout << 'U';
        }
    }
}