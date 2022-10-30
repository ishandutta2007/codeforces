#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define Y(x) (2*(x))
#define N(x) (2*(x)+1)

struct SAT2 {
    int n;
    vector<int> g[500005];
    vector<int> gt[500005];
    bool used[500005];
    int order[500005], ords;
    int comp[500005];
    bool istrue[500005];

    void init(int sz) {
        n = 2*sz;
        ords = 0;
        FO(i,0,n) {
            used[i] = false, comp[i] = -1, istrue[i] = false;
            g[i].clear();
            gt[i].clear();
        }
    }

    void imply(int a, int b) {
        g[a].push_back(b);
        g[b^1].push_back(a^1);
        gt[b].push_back(a);
        gt[a^1].push_back(b^1);
    }

    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to])
                dfs1 (to);
        }
        order[ords++] = v;
    }

    void dfs2 (int v, int cl) {
        comp[v] = cl;
        for (size_t i=0; i<gt[v].size(); ++i) {
            int to = gt[v][i];
            if (comp[to] == -1)
                dfs2 (to, cl);
        }
    }

    bool calc() {
        for (int i=0; i<n; ++i)
            if (!used[i])
                dfs1 (i);

        for (int i=0, j=0; i<n; ++i) {
            int v = order[n-i-1];
            if (comp[v] == -1)
                dfs2 (v, j++);
        }

        for (int i=0; i<n; ++i)
            if (comp[i] == comp[i^1]) {
                return 0;
            }
        for (int i=0; i<n; ++i) {
            int ans = comp[i] > comp[i^1] ? i : i^1;
            istrue[ans] = true;
        }
        return 1;
    }
};

int n, m;
vector<tuple<int,int,int,int> > u[50005];

#define C(i) (i)
#define A(i) (i+m)
#define B(i) (i+3*m)
SAT2 s;

bool can(int T) {
    s.init(5*m);
    FO(i,1,n+1) {
        int previ = -1, prevc = -1, prevj = -1;
        for (auto e : u[i]) {
            int c, t, j, ind;
            tie(c,t,j,ind) = e;
            s.imply(Y(A(j)), N(C(ind)));
            s.imply(Y(B(j)), N(C(ind)));
            if (previ != -1) {
                s.imply(Y(A(prevj)), Y(A(j)));
                s.imply(Y(B(j)), Y(B(prevj)));

                s.imply(Y(C(previ)), Y(A(j)));
                s.imply(Y(C(ind)), Y(B(prevj)));
            }

            if (t > T) {
                s.imply(Y(C(ind)), N(C(ind)));
            }

            if (c == prevc) {
                s.imply(N(C(ind)), Y(C(previ)));
                s.imply(N(C(previ)), Y(C(ind)));
            }

            previ = ind;
            prevj = j;
            prevc = c;
        }
    }
    return s.calc();
}

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,m) {
        int x, y, c, t; scanf("%d %d %d %d", &x, &y, &c, &t);
        u[x].emplace_back(c, t, 2*i, i);
        u[y].emplace_back(c, t, 2*i+1, i);
    }
    FO(i,1,n+1) sort(u[i].begin(), u[i].end());
    FO(i,1,n+1) {
        int cnt = 0, prevc = -1;
        for (auto e : u[i]) {
            int c, t, j, ind;
            tie(c,t,j,ind) = e;
            if (c == prevc) cnt++;
            prevc = c;
        }
        if (cnt > 1) {
            printf("No\n");
            return 0;
        }
    }
    int st = 0, e = 1e9+5, b = 1e9+5;
    while (st <= e) {
        int md = (st+e)/2;
        if (can(md)) {
            b = md;
            e = md-1;
        } else st = md+1;
    }
    if (b > 1e9+2) printf("No\n");
    else {
        can(b);
        printf("Yes\n");
        vector<int> v;
        FO(i,0,m) if (s.istrue[Y(C(i))]) v.push_back(i);
        printf("%d %d\n", b, sz(v));
        FO(i,0,sz(v)) printf("%d%c", v[i]+1, " \n"[i+1==sz(v)]);
    }
}