#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    explicit Point() {
    }
    explicit Point(int x, int y) : x(x), y(y) {
    }
    bool operator<(Point const& o) const {
        return pair(x, y) < pair(o.x, o.y);
    }
    Point operator+(Point const& o) const {
        return Point{x + o.x, y + o.y};
    }
};

istream& operator>>(istream& is, Point& p) {
    return is >> p.x >> p.y;
}

struct Node {
    int p, size_x, size_y;
    int rank() const { return size_x + size_y; }
    long long cnt() const {
        return (long long)size_x * size_y;
    }
    bool operator==(Node const& o) const {
        return p == o.p && size_x == o.size_x && size_y == o.size_y;
    }
};

struct UndoInfo {
    long long cnt;
    int idx1, idx2;
    Node node1, node2;
    bool operator==(UndoInfo const& o) const {
        return cnt == o.cnt && idx1 == o.idx1 && idx2 == o.idx2 && node1 == o.node1 && node2 == o.node2;
    }
};

int const MAX_COORD = 300'000;

class UnionFind {
public:
    UnionFind(int n) {
        nodes.resize(2 * n + 1);
        for (int i = 1; i <= n; i++)
            nodes[i] = {i, 1, 0};
        for (int i = 1; i <= n; i++)
            nodes[n + i] = {n + i, 0, 1};
    }

    int Find(int x) {
        int & p = nodes[x].p;
        return x == p ? x : Find(p);
    }

    void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);

        Node & node1 = nodes[xRoot];
        Node & node2 = nodes[yRoot];

        undo_infos.push_back({cnt, xRoot, yRoot, node1, node2});

        if (xRoot == yRoot)
            return;

        cnt -= node1.cnt();
        cnt -= node2.cnt();

        if (node1.rank() < node2.rank()) {
            node1.p = yRoot;
            node2.size_x += node1.size_x;
            node2.size_y += node1.size_y;
            cnt += node2.cnt();
        } else {
            node2.p = xRoot;
            node1.size_x += node2.size_x;
            node1.size_y += node2.size_y;
            cnt += node1.cnt();
        }
    }

    bool sameUnion(int x, int y) {
        return Find(x) == Find(y);
    }

    void undo() {
        auto info = undo_infos.back();
        undo_infos.pop_back();
        cnt = info.cnt;
        nodes[info.idx1] = info.node1;
        nodes[info.idx2] = info.node2;
    }

    bool operator==(UnionFind const& o) {
        return cnt == o.cnt && nodes == o.nodes && undo_infos == o.undo_infos;
    }

    long long cnt = 0;
private:
    std::vector<Node> nodes;
    std::vector<UndoInfo> undo_infos;
};

class SegmentTreeRec {
public:
    SegmentTreeRec(int n) : n(n) {
        data.resize(4 * n);
    }

    void add(int x, int y, Point p, int id, int l, int r) {
        if (x >= r || y <= l) {
            // nothing
        } else if (x <= l && r <= y) {
            data[id].push_back(p);
        } else {
            int m = (l + r) >> 1;
            add(x, y, p, id << 1, l, m);
            add(x, y, p, id << 1 | 1, m, r);
        }
    }

    void add(int x, int y, Point p) {
        add(x, y, p, 1, 0, n);
    }

    void dfs(UnionFind & uf, int id, int l, int r) {
        // add points
        for (auto const& point : data[id])
            uf.Union(point.x, point.y + MAX_COORD);

        if (l + 1 == r) {
            // cout solution
            // cout << 1 << ' ';
            cout << uf.cnt << ' ';
        } else {
            int m = (l + r) >> 1;
            dfs(uf, id << 1, l, m);
            dfs(uf, id << 1 | 1, m, r);
        }

        // undo add steps
        for (auto const& point : data[id])
            uf.undo();
    }

    void dfs(UnionFind & uf) {
        dfs(uf, 1, 0, n);
    }

private:
    int n;
    std::vector<vector<Point>> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    SegmentTreeRec st(n);

    map<Point, int> starts;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p;
        if (auto it = starts.find(p); it != starts.end()) {
            st.add(it->second, i, p);
            starts.erase(it);
        } else {
            starts[p] = i;
        }
    }
    for (auto [p, start] : starts) {
        st.add(start, n, p);
    }

    UnionFind uf(MAX_COORD);
    st.dfs(uf);
    cout << endl;
}