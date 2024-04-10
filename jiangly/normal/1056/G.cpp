#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;

struct Tree {
    Tree *l;
    Tree *r;
    int x;
    int siz;
    Tree(Tree *v) { *this = *v; }
    Tree(int x = 0) : l(nullptr), r(nullptr), x(x), siz(1) {}
    void pull() {
        siz = 1;
        if (l != nullptr) {
            siz += l->siz;
        }
        if (r != nullptr) {
            siz += r->siz;
        }
    }
};

int cnt = 0;
constexpr int N = 1e7;
Tree pool[N];

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

template<class... T>
Tree *newTree(T... x) {
    Tree *t = &pool[cnt++];
    *t = Tree(x...);
    return t;
}

Tree *merge(Tree *a, Tree *b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    Tree *t;
    if (int(rnd() % (a->siz + b->siz)) < a->siz) {
        t = newTree(a);
        t->r = merge(t->r, b);
    } else {
        t = newTree(b);
        t->l = merge(a, t->l);
    }
    t->pull();
    return t;
}

std::pair<Tree *, Tree *> split(Tree *t, int k) {
    if (t == nullptr || k == 0) {
        return {nullptr, t};
    }
    if (t->siz == k) {
        return {t, nullptr};
    }
    int szl = t->l == nullptr ? 0 : t->l->siz;
    Tree *u = newTree(t);
    if (k <= szl) {
        auto [a, b] = split(t->l, k);
        u->l = b;
        u->pull();
        return {a, u};
    } else {
        auto [a, b] = split(t->r, k - 1 - szl);
        u->r = a;
        u->pull();
        return {u, b};
    }
}

Tree *build(const std::vector<int> &a, int l, int r) {
    if (l == r) {
        return nullptr;
    }
    
    int m = (l + r) / 2;
    auto t = newTree(a[m]);
    t->l = build(a, l, m);
    t->r = build(a, m + 1, r);
    t->pull();
    return t;
}

void dfs(Tree *t, std::vector<int> &a) {
    if (t == nullptr) {
        return;
    }
    dfs(t->l, a);
    a.push_back(t->x);
    dfs(t->r, a);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    int s;
    i64 t;
    std::cin >> s >> t;
    s--;
    
    while (t % n != 0) {
        if (s < m) {
            s = (s + t) % n;
        } else {
            s = (s - t % n + n) % n;
        }
        t--;
    }
    
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 0);
    
    auto f = build(a, 0, n);
    
    for (int i = 1; i < n; i++) {
        if (cnt > N - 10000) {
            a.clear();
            dfs(f, a);
            cnt = 0;
            f = build(a, 0, n);
        }
        Tree *a, *b;
        
        if (m + i <= n) {
            a = split(split(f, m + i).first, i).second;
        } else {
            a = merge(split(f, i).second, split(f, i + m - n).first);
        }
        
        if (m - i >= 0) {
            b = split(split(f, n - i).first, m - i).second;
        } else {
            b = merge(split(f, m - i + n).second, split(f, n - i).first);
        }
        
        f = merge(a, b);
    }
    a.clear();
    dfs(f, a);
    
    t /= n;
    std::vector<int> vis(n, -1);
    
    int cur = 0;
    while (t > 0 && vis[s] < 0) {
        vis[s] = cur++;
        s = a[s];
        t--;
    }
    
    t %= (cur - vis[s]);
    
    while (t > 0) {
        s = a[s];
        t--;
    }
    
    std::cout << s + 1 << "\n";
    
    return 0;
}