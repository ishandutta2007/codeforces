#include <bits/stdc++.h>
using namespace std;

int n, m, q;

struct Query
{
    int l, r;
    int idx;
};

struct Segment
{
    int cnt = 0;
    array<pair<int, int>, 10> bl, br;

    Segment() {
        bl = {{ {0, 0} }};
        br = {{ {0, 0} }};
    }
};

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void Union(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x < y)
            parent[y] = x;
        if (x > y)
            parent[x] = y;
    }
};

Segment combine(Segment a, Segment b) {
    UnionFind uf(50);
    for (int i = 0; i < n; i++) {
        if (a.br[i].first == b.bl[i].first) {
            uf.Union(a.br[i].second, b.bl[i].second + 25);
        }
    }
    array<int, 50> values = {{ -1 }};
    fill(values.begin(), values.end(), -1);
    int used = 1;
    Segment res;

    res.cnt = a.cnt + b.cnt;
    for (int i = 0; i < n; i++) {
        int p = uf.find(a.bl[i].second);
        if (values[p] == -1) {
            values[p] = used++;
        }
        res.bl[i] = {a.bl[i].first, values[p]};
    }
    for (int i = 0; i < n; i++) {
        int p = uf.find(b.br[i].second + 25);
        if (values[p] == -1) {
            values[p] = used++;
        }
        res.br[i] = {b.br[i].first, values[p]};
    }

    for (int i = 0; i < n; i++) {
        int p = uf.find(a.br[i].second);
        if (values[p] == -1) {
            values[p] = used++;
            res.cnt++;
        }
        p = uf.find(b.bl[i].second + 25);
        if (values[p] == -1) {
            values[p] = used++;
            res.cnt++;
        }
    }
    return res;
}

class SegmentTree {
public:
    vector<Segment> data;
    int size;

    SegmentTree(int n) {
        this->size = n;
        data.resize(2*n);
    }

    Segment range(int left, int right) {
        left += size;
        right += size;

        Segment rl = data[left++];
        Segment rr = data[--right];
        while (left < right) {
            if (left & 1) rl = combine(rl, data[left++]);
            if (right & 1) rr = combine(data[--right], rr);
            left >>= 1;
            right >>= 1;
        }
        return combine(rl, rr);
    }  
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    vector<vector<int>> flag(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> flag[i][j];
        }
    }

    SegmentTree st(m);

    for (int i = 0; i < m; i++) {
        Segment& s = st.data[m + i];
        s.cnt = 0;
        for (int j = 0; j < n; j++) {
            if (j == 0 || flag[j][i] != flag[j-1][i]) {
                s.bl[j] = {flag[j][i], j + 1};
            } else
                s.bl[j] = s.bl[j-1];
        }
        s.br = s.bl;
    }
    for (int i = m - 1; i >= 0; i--) {
        st.data[i] = combine(st.data[i*2], st.data[i*2+1]);
    }

    vector<Query> queries(q);
    for (int idx = 0; idx < q; idx++) {
        auto& query = queries[idx];
        query.idx = idx;
        cin >> query.l >> query.r;
    }

    for (auto qs : queries) {
        auto r = st.range(qs.l-1, qs.r);
        set<int> s;
        for (auto i : r.bl)
            s.insert(i.second);
        for (auto i : r.br)
            s.insert(i.second);
        s.insert(0);
        cout << s.size() - 1 + r.cnt << endl;
    }
    
    return 0;
}