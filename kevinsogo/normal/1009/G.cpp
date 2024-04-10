#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
const int C = 6;
const int INF = 1<<30;

struct maxflow {

    struct edge {
        int j, cap, flow;
        edge *pair;
        edge(int j, int cap): j(j), cap(cap), flow(0), pair(NULL) {}
        inline void _add_flow(int add) {
            flow += add;
        }
        inline void add_flow(int add) {
            _add_flow(add);
            pair->_add_flow(-add);
        }
        inline bool in_res() {
            return cap != flow;
        }
        inline int res() {
            return cap - flow;
        }
    };

    int n;
    vector<edge*> adj[1111];
    edge* parent[1111];
    int flow = 0;

    maxflow(int n): n(n) {
        for (int i = 0; i < n; i++) adj[i].clear();
    }
    
    map<pair<int,int>, edge*> es;

    int get_cap(int i, int j) {
        return es[{i, j}]->cap;
    }

    void add_edge(int i, int j, int cap) {
        edge *ij = new edge(j, cap);
        edge *ji = new edge(i, 0);
        ij->pair = ji;
        ji->pair = ij;
        adj[i].push_back(ij);
        adj[j].push_back(ji);
        es[{i, j}] = ij;
        es[{j, i}] = ji;
    }

    bool aug(int s, int t) {
        for (int i = 0; i < n; i++) parent[i] = NULL;
        parent[s] = new edge(s, 0);
        vector<int> queue;
        queue.push_back(s);
        for (int f = 0; f < queue.size(); f++) {
            int i = queue[f];
            for (edge* e : adj[i]) {
                if (e->in_res()) {
                    int j = e->j;
                    if (parent[j] == NULL) {
                        parent[j] = e;
                        if (j == t) return true;
                        queue.push_back(j);
                    }
                }
            }
        }
        return false;
    }


    bool caug(int s, int t) {
        for (int i = 0; i < n; i++) parent[i] = NULL;
        parent[s] = new edge(s, 0);
        vector<int> queue;
        queue.push_back(s);
        for (int f = 0; f < queue.size(); f++) {
            int i = queue[f];
            for (edge* e : adj[i]) {
                if (e->flow > 0) {
                    int j = e->j;
                    if (parent[j] == NULL) {
                        parent[j] = e;
                        if (j == t) return true;
                        queue.push_back(j);
                    }
                }
            }
        }
        return false;
    }

    void cancel_flow(int s, int t) {
        if (s == t) return;
        caug(s, t);
        for (int i = t; i != s; i = parent[i]->pair->j) {
            parent[i]->add_flow(-1);
        }
    }

    void modify_edge(int s, int t, int i, int j, int d) {
        edge *e = es[{i, j}];
        e->cap += d;
        if (e->flow > e->cap) {
            flow--;
            cancel_flow(s, i);
            cancel_flow(j, t);
            e->flow--;
        }
    }

    int max_flow(int s, int t) {
        while (aug(s, t)) {
            int add = INF;
            for (int i = t; i != s; i = parent[i]->pair->j) {
                add = min(add, parent[i]->res());
            }
            flow += add;
            for (int i = t; i != s; i = parent[i]->pair->j) {
                parent[i]->add_flow(add);
            }
        }
        return flow;
    }
};


int ctl[C], ctr[1 << C], m[N];
char s[N], t[N];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        ctl[s[i] - 'a']++;
        m[i] = (1 << C) - 1;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int i;
        scanf("%d%s", &i, t);
        m[--i] = 0;
        for (char *c = t; *c; c++) {
            m[i] |= 1 << *c - 'a';
        }
    }
    for (int i = 0; i < n; i++) {
        ctr[m[i]]++;
    }
    maxflow mf(C + (1 << C) + 2);
    int st = C + (1 << C), en = st + 1;

    for (int i = 0; i < C; i++) {
        mf.add_edge(st, i, ctl[i]);
    }
    for (int j = 0; j < 1 << C; j++) {
        mf.add_edge(C + j, en, ctr[j]);
    }
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < 1 << C; j++) {
            if (j & (1 << i)) {
                mf.add_edge(i, C + j, n);
            }
        }
    }
    if (mf.max_flow(st, en) != n) {
        puts("Impossible");
    } else {
        for (int p = 0; p < n; p++) {
            t[p] = 0;
            mf.modify_edge(st, en, C + m[p], en, -1);
            for (int i = 0; i < C; i++) {
                if (m[p] & (1 << i)) {
                    if (mf.get_cap(st, i) > 0 && mf.get_cap(i, C + m[p]) > 0) {
                        mf.modify_edge(st, en, st, i, -1);
                        mf.modify_edge(st, en, i, C + m[p], -1);
                        if (mf.max_flow(st, en) == n - p - 1) {
                            t[p] = 'a' + i;
                            break;
                        }
                        mf.modify_edge(st, en, st, i, +1);
                        mf.modify_edge(st, en, i, C + m[p], +1);
                    }
                }
            }
            // mf.modify_edge(st, en, C + m[p], en, +1);
            assert(t[p]);
        }
        t[n] = 0;
        printf("%s\n", t);
    }
}