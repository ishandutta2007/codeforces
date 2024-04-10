#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
struct Node {
    Node *ch[2], *p;
    int id, l, r;
    bool rev;
    Node(int id) : ch{nullptr, nullptr}, p(nullptr), id(id), l(id), r(id), rev(false) {}
    friend int getl(Node *p) {
        if (p == nullptr) {
            return -1;
        } else {
            return p -> l;
        }
    }
    friend int getr(Node *p) {
        if (p == nullptr) {
            return -1;
        } else {
            return p -> r;
        }
    }
    friend void reverse(Node *p) {
        if (p != nullptr) {
            std::swap(p -> ch[0], p -> ch[1]);
            std::swap(p -> l, p -> r);
            p -> rev ^= 1;
        }
    }
    void push() {
        if (rev) {
            reverse(ch[0]);
            reverse(ch[1]);
            rev = false;
        }
    }
    void pull() {
        if (getl(ch[0]) != -1) {
            l = getl(ch[0]);
        } else if (id != -1) {
            l = id;
        } else {
            l = getl(ch[1]);
        }
        if (getr(ch[1]) != -1) {
            r = getr(ch[1]);
        } else if (id != -1) {
            r = id;
        } else {
            r = getr(ch[0]);
        }
    }
    bool isroot() {
        return p == nullptr || p -> ch[0] != this && p -> ch[1] != this;
    }
    bool pos() {
        return p -> ch[1] == this;
    }
    void rotate() {
        Node *q = p;
        bool x = !pos();
        q -> ch[!x] = ch[x];
        if (ch[x] != nullptr)
            ch[x] -> p = q;
        p = q -> p;
        if (!q -> isroot())
            q -> p -> ch[q -> pos()] = this;
        ch[x] = q;
        q -> p = this;
        pull();
        q -> pull();
    }
    void splay() {
        std::vector<Node *> s;
        for (Node *i = this; !i -> isroot(); i = i -> p)
            s.push_back(i -> p);
        while (!s.empty()) {
            s.back() -> push();
            s.pop_back();
        }
        push();
        while (!isroot()) {
            if (!p -> isroot()) {
                if (pos() == p -> pos()) {
                    p -> rotate();
                } else {
                    rotate();
                }
            }
            rotate();
        }
        pull();
    }
    void access() {
        for (Node *i = this, *q = nullptr; i != nullptr; q = i, i = i -> p) {
            i -> splay();
            i -> ch[1] = q;
            i -> pull();
        }
        splay();
    }
    void makeroot() {
        access();
        reverse(this);
    }
};
void link(Node *x, Node *y) {
    x -> makeroot();
    x -> p = y;
}
void split(Node *x, Node *y) {
    x -> makeroot();
    y -> access();
}
void cut(Node *x, Node *y) {
    split(x, y);
    x -> p = y -> ch[0] = nullptr;
    y -> pull();
}
std::vector<int> fa;
std::vector<std::vector<int>> e;
std::vector<std::pair<int, int>> edge;
std::vector<Node *> nodev, nodee;
int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
void dfs(int u, int p) {
    for (int v : e[u]) {
        if (v != p) {
            dfs(v, u);
            split(nodev[u], nodev[v]);
            int i = nodev[v] -> r;
            std::cout << u + 1 << " " << v + 1 << " " << edge[i].first + 1 << " " << edge[i].second + 1 << std::endl;
            nodee[i] -> splay(); 
            nodee[i] -> id = -1;
            nodee[i] -> pull();
            cut(nodee[i], nodev[find(v) == find(edge[i].first) ? edge[i].second : edge[i].first]);
            fa[find(v)] = u;
            link(nodee[i], nodev[u]);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    e.resize(n);
    fa.resize(n);
    std::iota(fa.begin(), fa.end(), 0);
    edge.resize(n - 1);
    nodev.resize(n);
    nodee.resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
        nodev[i] = new Node(-1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        edge[i] = std::make_pair(u, v);
        nodee[i] = new Node(i);
        link(nodee[i], nodev[u]);
        link(nodee[i], nodev[v]);
    }
    std::cout << n - 1 << "\n";
    dfs(0, -1);
    return 0;
}