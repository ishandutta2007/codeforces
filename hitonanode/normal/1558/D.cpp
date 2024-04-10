#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using lint = long long;


// Lazy randomized binary search tree
template <int LEN, class S, S (*op)(S, S), class F, S (*reversal)(S), S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct lazy_rbst {
    // Do your RuBeSTy! ( )
    inline uint32_t _rand() { // XorShift
        static uint32_t x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        uint32_t t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    struct Node {
        Node *l, *r;
        S val, sum;
        F lz;
        bool is_reversed;
        int sz;
        Node(const S &v) : l(nullptr), r(nullptr), val(v), sum(v), lz(id()), is_reversed(false), sz(1) {}
        Node() : l(nullptr), r(nullptr), lz(id()), is_reversed(false), sz(0) {}
        template <class OStream> friend OStream &operator<<(OStream &os, const Node &n) {
            os << '[';
            if (n.l) os << *(n.l) << ',';
            os << n.val << ',';
            if (n.r) os << *(n.r);
            return os << ']';
        }
    };
    using Nptr = Node *;
    std::array<Node, LEN> data;
    int d_ptr;

    int size(Nptr t) const { return t != nullptr ? t->sz : 0; }

    lazy_rbst() : d_ptr(0) {}

protected:
    Nptr update(Nptr t) {
        t->sz = 1;
        t->sum = t->val;
        if (t->l) {
            t->sz += t->l->sz;
            t->sum = op(t->l->sum, t->sum);
        }
        if (t->r) {
            t->sz += t->r->sz;
            t->sum = op(t->sum, t->r->sum);
        }
        return t;
    }

    void all_apply(Nptr t, F f) {
        t->val = mapping(f, t->val);
        t->sum = mapping(f, t->sum);
        t->lz = composition(f, t->lz);
    }
    void _toggle(Nptr t) {
        auto tmp = t->l;
        t->l = t->r, t->r = tmp;
        t->sum = reversal(t->sum);
        t->is_reversed ^= true;
    }

    void push(Nptr &t) {
        _duplicate_node(t);
        if (t->lz != id()) {
            if (t->l) {
                _duplicate_node(t->l);
                all_apply(t->l, t->lz);
            }
            if (t->r) {
                _duplicate_node(t->r);
                all_apply(t->r, t->lz);
            }
            t->lz = id();
        }
        if (t->is_reversed) {
            if (t->l) _toggle(t->l);
            if (t->r) _toggle(t->r);
            t->is_reversed = false;
        }
    }

    virtual void _duplicate_node(Nptr &) {}

    Nptr _make_node(const S &val) {
        if (d_ptr >= LEN) throw;
        return &(data[d_ptr++] = Node(val));
    }

public:
    Nptr new_tree() { return nullptr; } // 

    int mem_used() const { return d_ptr; }
    bool empty(Nptr t) const { return t == nullptr; }

    // lrrootroot
    Nptr merge(Nptr l, Nptr r) {
        if (l == nullptr or r == nullptr) return l != nullptr ? l : r;
        if (_rand() % uint32_t(l->sz + r->sz) < uint32_t(l->sz)) {
            push(l);
            l->r = merge(l->r, r);
            return update(l);
        } else {
            push(r);
            r->l = merge(l, r->l);
            return update(r);
        }
    }

    // [0, k)[k, root->size())root
    // 0nullptr
    std::pair<Nptr, Nptr> split(Nptr &root, int k) { // rootk
        if (root == nullptr) return std::make_pair(nullptr, nullptr);
        push(root);
        if (k <= size(root->l)) { // leftk
            auto p = split(root->l, k);
            root->l = p.second;
            return std::make_pair(p.first, update(root));
        } else {
            auto p = split(root->r, k - size(root->l) - 1);
            root->r = p.first;
            return std::make_pair(update(root), p.second);
        }
    }

    // 0-indexedarray[pos] x 
    void insert(Nptr &root, int pos, const S &x) {
        auto p = split(root, pos);
        root = merge(p.first, merge(_make_node(x), p.second));
    }

    // 0-indexedarray[pos]pos+1
    void erase(Nptr &root, int pos) {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        root = merge(p.first, p2.second);
    }

    // 1 array[pos].valupdval
    void set(Nptr &root, int pos, const S &x) {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        _duplicate_node(p2.first);
        *p2.first = Node(x);
        root = merge(p.first, merge(p2.first, p2.second));
    }

    //  [l, r)
    void apply(Nptr &root, int l, int r, const F &f) {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        all_apply(p2.first, f);
        root = merge(p.first, merge(p2.first, p2.second));
    }

    // array[pos].val
    S prod(Nptr &root, int l, int r) {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        if (p2.first != nullptr) push(p2.first);
        S res = p2.first->sum;
        root = merge(p.first, merge(p2.first, p2.second));
        return res;
    }

    S get(Nptr &root, int pos) { return prod(root, pos, pos + 1); }

    template <bool (*g)(S)> int max_right(Nptr root, const S &e) {
        return max_right(root, e, [](S x) { return g(x); });
    }
    template <class G> int max_right(Nptr root, const S &e, G g) {
        assert(g(e));
        if (root == nullptr) return 0;
        push(root);
        Nptr now = root;
        S prod_now = e;
        int sz = 0;
        while (true) {
            if (now->l != nullptr) {
                push(now->l);
                auto pl = op(prod_now, now->l->sum);
                if (g(pl)) {
                    prod_now = pl;
                    sz += now->l->sz;
                } else {
                    now = now->l;
                    continue;
                }
            }
            auto pl = op(prod_now, now->val);
            if (!g(pl)) return sz;
            prod_now = pl, sz++;
            if (now->r == nullptr) return sz;
            push(now->r);
            now = now->r;
        }
    }

    template <bool (*g)(S)> int min_left(Nptr root, const S &e) {
        return min_left(root, e, [](S x) { return g(x); });
    }
    template <class G> int min_left(Nptr root, const S &e, G g) {
        assert(g(e));
        if (root == nullptr) return 0;
        push(root);
        Nptr now = root;
        S prod_now = e;
        int sz = size(root);
        while (true) {
            if (now->r != nullptr) {
                push(now->r);
                auto pr = op(now->r->sum, prod_now);
                if (g(pr)) {
                    prod_now = pr;
                    sz -= now->r->sz;
                } else {
                    now = now->r;
                    continue;
                }
            }
            auto pr = op(now->val, prod_now);
            if (!g(pr)) return sz;
            prod_now = pr, sz--;
            if (now->l == nullptr) return sz;
            push(now->l);
            now = now->l;
        }
    }

    void reverse(Nptr &root) { _duplicate_node(root), _toggle(root); }
    void reverse(Nptr &root, int l, int r) {
        auto p2 = split(root, r);
        auto p1 = split(p2.first, l);
        reverse(p1.second);
        root = merge(merge(p1.first, p1.second), p2.second);
    }

    // init
    void assign(Nptr &root, const std::vector<S> &init) {
        d_ptr = 0;
        int N = init.size();
        root = N ? _assign_range(0, N, init) : new_tree();
    }
    Nptr _assign_range(int l, int r, const std::vector<S> &init) {
        if (r - l == 1) {
            Nptr t = _make_node(init[l]);
            return update(t);
        }
        return merge(_assign_range(l, (l + r) / 2, init), _assign_range((l + r) / 2, r, init));
    }

    // vec
    void dump(Nptr &t, std::vector<S> &vec) {
        if (t == nullptr) return;
        push(t);
        dump(t->l, vec);
        vec.push_back(t->val);
        dump(t->r, vec);
    }

    // gc
    void re_alloc(Nptr &root) {
        std::vector<S> mem;
        dump(root, mem);
        assign(root, mem);
    }
};

using S = int;
S op(S l, S r) { return l > r ? l : r; }
using F = pair<bool, int>;
S reversal(S x) { return x; }
S mapping(F f, S x) { return f.first ? f.second + x : x; }
F composition(F f, F g) {
    if (!f.first) return g;
    if (!g.first) return f;
    return {true, f.second + g.second};
}
F id() { return {false, 0}; }

lint power(lint x, lint n, lint MOD)
{
    lint ans = 1;
    while (n) {
        if (n & 1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
       n >>= 1;
    }
    return ans;
}

vector<lint> facs;
constexpr int md = 998244353;

lazy_rbst<1000000, S, op, F, reversal, mapping, composition, id> tree;
int solve() {
    int N, M;
    cin >> N >> M;
    vector<int> ys(M);
    for (auto &y : ys) cin >> y >> y;
    auto root = tree.new_tree();
    tree.insert(root, 0, 0);
    for (int y : ys) {
        const int len = root->sz;
        int lo = tree.max_right(root, -100, [&](int v) { return v < y - 1; });
        if (lo == len) {
            tree.insert(root, len, y);
        } else if (tree.get(root, lo) == y - 1) {
            tree.apply(root, lo, len, {true, 1});
        } else {
            tree.apply(root, lo, len, {true, 1});
            tree.insert(root, lo, y);
        }
    }
    int sz = tree.size(root);
    if (tree.get(root, 0) == 0) sz--;
    sz = N - 1 - sz;
    return lint(facs[N + sz]) * power(lint(facs[N]) * facs[sz] % md, md - 2, md) % md;
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    facs.assign(401010, 1);
    for (int i = 1; i < int(facs.size()); i++) facs[i] = lint(i) * facs[i - 1] % md;
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}