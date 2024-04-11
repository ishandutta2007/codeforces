#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))

const int maxn = 605;

//#define LOCAL
set< pair<int, int> > edges;

vector<int> unite(const vector<int> &A, const vector<int> &B) {
    vector<int> res;
    for (auto i: A) res.push_back(i);
    for (auto i: B) res.push_back(i);
    return res;
}

int ask(const vector<int> &a) {
    #ifdef LOCAL
    assert(sz(a) > 0);
        int ans = 0;
        for (auto i: a) {
            for (auto j: a) {
                if (edges.count({i, j})) {
                    ++ans;
                }
            }
        }
        return ans;
    #else
    if (sz(a) < 2) return 0;
        cout << "?" << ' ' << sz(a) << endl;
        for (auto i: a) {
            cout << i << ' ';
        }
        cout << endl;
        int x;
        cin >> x;
        return x;
    #endif
}

void yes(const vector<int> &a) {
    cout << "Y " << sz(a) << endl;
    for (auto i: a) {
        cout << i << ' ';
    }
    cout << endl;
    exit(0);
}

void no(const vector<int> &a) {
    cout << "N " << sz(a) << endl;
    for (auto i: a) {
        cout << i << ' ';
    }
    cout << endl;
    exit(0);
}

pair<int, int> find_edge(vector<int> A, vector<int> B) {
    if (A.empty() || B.empty()) return {0, 0};
    int a = ask(A);
    int b = ask(B);
    int ab = ask(unite(A, B));
    if (ab == a + b) {
        return {0, 0};
    }
    for (int it = 0; it < 2; ++it) {
        if (it == 1) a = ask(A);
        while (sz(B) > 1) {
            vector<int> fi, se;
            for (int i = 0; i < sz(B); ++i) {
                if (i < sz(B) / 2) {
                    fi.push_back(B[i]);
                } else {
                    se.push_back(B[i]);
                }
            }
            int x = ask(fi);
            int y = ask(unite(A, fi));
            if (x + a == y) {
                B = se;
            } else {
                B = fi;
            }
        }
        A.swap(B);
    }
    return {A[0], B[0]};
}

pair<int, int> find_edge(vector<int> A) {
    if (ask(A) == 0) return {0, 0};
    while (sz(A) > 1) {
        vector<int> fi, se;
        for (int i = 0; i < sz(A); ++i) {
            if (i < sz(A) / 2) {
                fi.push_back(A[i]);
            } else {
                se.push_back(A[i]);
            }
        }
        int x = ask(fi);
        int y = ask(se);
        if (x > 0) A = fi;
        else if (y > 0) A = se;
        else return find_edge(fi, se);
    }
}

int n;
int parent[maxn];
int h[maxn];
int color[maxn];

int getlca(int u, int v) {
    while (h[u] > h[v]) u = parent[u];
    while (h[v] > h[u]) v = parent[v];
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

void restore_no(int u, int v) {
    int lca = getlca(u, v);
    vector<int> ans;
    while (u != lca) {
        ans.push_back(u);
        u = parent[u];
    }
    ans.push_back(lca);
    vector<int> t;
    while (v != lca) {
        t.push_back(v);
        v = parent[v];
    }
    reverse(t.begin(), t.end());
    for (auto i: t) ans.push_back(i);
    no(ans);
}

void restore_yes() {
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (color[i]) ans.push_back(i);
    }
    yes(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    
    #ifdef LOCAL
        n = 4;
        edges = {{1, 4}, {1, 3}, {3, 2}, {2, 4}};
    #else
        cin >> n;
    #endif
    color[1] = 0;
    parent[1] = 1;
    for (int i = 2; i <= n; ++i) {
        vector<int> taken;
        vector<int> other;
        for (int j = 1; j <= n; ++j) {
            if (!parent[j]) {
                other.push_back(j);
            } else {
                taken.push_back(j);
            }
        }
        int u, v;
        tie(u, v) = find_edge(taken, other);
        assert(parent[u] && !parent[v]);
        parent[v] = u;
        color[v] = !color[u];
        h[v] = h[u] + 1;
    }
    
    vector<int> white, black;
    for (int i = 1; i <= n; ++i) {
        if (color[i]) black.push_back(i);
        else white.push_back(i);
    }
    int u, v;
    tie(u, v) = find_edge(white);
    if (u != 0) {
        restore_no(u, v);
    }
    tie(u, v) = find_edge(black);
    if (u != 0) {
        restore_no(u, v);
    }
    restore_yes();
}