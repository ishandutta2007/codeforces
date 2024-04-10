#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

struct node {
    int id_;
    lint val, cnt;
    node() = default;
    node(int id_, lint v) : id_(id_), val(v), cnt(0) {}
};

using VAL = node;
using DVAL = plint;
template <uint32_t len>
struct RandomizedBinarySearchTree
{
    // Do your RuBeSTy! ( )
    inline uint32_t _rand() // XorShift
    {
        static uint32_t x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        uint32_t t = x ^ (x << 11);
        x = y; y = z; z = w; return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    // 
    DVAL Idval;
    struct Node
    {
        Node *l, *r;
        uint32_t sz; // 
        VAL val; // root, dval==Idval
        DVAL dval; // 
        Node(const VAL &v, const DVAL &dv)
        : l(nullptr), r(nullptr), sz(1), val(v), dval(dv) {}
        Node() {}
    };
    inline Node *_revise_val(Node *t) // tszval
    {
        if (t)
        {
            t->sz = size(t->l) + size(t->r) + 1;
        };
        return t;
    }
    inline void _propagate_dval(DVAL &a, DVAL b) // 
    {
        a.first += b.first;
        a.second += b.second;
    }
    inline void _reflect_dval(Node *a, DVAL b) // 
    {
        a->val.val -= b.first;
        a->val.cnt += b.second;
    }
    vector<Node> data;
    uint32_t d_ptr;

    RandomizedBinarySearchTree(DVAL idval)
    : Idval(idval), d_ptr(0) { data.resize(len); }

    Node *new_tree() { return nullptr; } // 
    static inline uint32_t size(const Node *t) { return t ? t->sz : 0; }
    inline int mem_used() { return (int)d_ptr; }
    inline bool empty(Node *t) { return !t; }
    inline Node *_make_node(const VAL &val) { if (d_ptr >= len) exit(1); return &(data[d_ptr++] = Node(val, Idval)); }
    virtual void _duplicate_node(Node *&) {}


    inline void _resolve_dval(Node *&t) // 
    {
        if (!t) return;
        _duplicate_node(t);
        if (t->dval != Idval) {
            if (t->l) {
                _duplicate_node(t->l);
                _propagate_dval(t->l->dval, t->dval);
            }
            if (t->r) {
                _duplicate_node(t->r);
                _propagate_dval(t->r->dval, t->dval);
            }
            _reflect_dval(t, t->dval);
            t->dval = Idval;
        }
    }

    // lrrootroot
    Node *merge(Node *l, Node *r)
    {
        if (l == nullptr || r == nullptr) return l ? l : r;
        if (l->val.val - l->dval.first > r->val.val - r->dval.first) swap(l, r);
        if (_rand() % (l->sz + r->sz) < l->sz)
        {
            while (r != nullptr)
            {
                _resolve_dval(l);
                VAL v = l->val;
                auto [rl, rr] = split(r, 1);
                if (rl->val.val - rl->dval.first < v.val)
                {
                    l = merge(l, rl);
                    r = rr;
                }
                else
                {
                    r = merge(rl, rr);
                    break;
                }
            }
            _resolve_dval(l);
            l->r = merge(l->r, r);
            return _revise_val(l);
        }
        else
        {
            while (l != nullptr)
            {
                _resolve_dval(r);
                VAL v = r->val;
                auto [ll, lr] = split(l, size(l) - 1);
                if (lr->val.val - lr->dval.first > v.val)
                {
                    r = merge(lr, r);
                    l = ll;
                }
                else
                {
                    l = merge(ll, lr);
                    break;
                }
            }
            _resolve_dval(r);
            r->l = merge(l, r->l);
            return _revise_val(r);
        }
    }

    // [0, k)[k, root->size())root
    // 0nullptr
    pair<Node*, Node*> split(Node *&root, int k) // rootk
    {
        if (root == nullptr) return make_pair(nullptr, nullptr);
        _resolve_dval(root);
        if (k <= (int)size(root->l)) // leftk
        {
            auto p = split(root->l, k);
            root->l = p.second;
            return make_pair(p.first, _revise_val(root));
        }
        else
        {
            auto p = split(root->r, k - size(root->l) - 1);
            root->r = p.first;
            return make_pair(_revise_val(root), p.second);
        }
    }

    // 0-indexedarray[pos]newval
    void insert(Node *&root, int pos, const VAL &newval)
    {
        auto p = split(root, pos);
        root = merge(p.first, merge(_make_node(newval), p.second));
    }

    // 0-indexedarray[pos]pos+1
    void erase(Node *&root, int pos)
    {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        root = merge(p.first, p2.second);
    }

    // 1 array[pos].valupdval
    void set(Node *&root, int pos, const VAL &updval)
    {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        root = merge(p.first, merge(_make_node(updval), p2.second));
    }

    //  [l, r)
    void range_set(Node *&root, int l, int r, const DVAL &adddval)
    {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        _propagate_dval(p2.first->dval, adddval);
        root = merge(p.first, merge(p2.first, p2.second));
    }

    // array[pos].val
    Node range_get(Node *&root, int l, int r)
    {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        _resolve_dval(p2.first);
        Node res = *p2.first;
        root = merge(p.first, merge(p2.first, p2.second));
        return res;
    }
    Node get(Node *&root, int pos)
    {
        return range_get(root, pos, pos + 1);
    }

    // lower_bound
    int lower_bound(Node *root, lint v)
    {
        if (root == nullptr) return 0;
        v += root->dval.first;
        return (v <= root->val.val) ? lower_bound(root->l, v) : lower_bound(root->r, v) + size(root->l) + 1;
    }

    // init
    void assign(Node *&root, const vector<VAL> &init)
    {
        d_ptr = 0;
        int N = init.size();
        root = N ? _assign_range(0, N, init) : new_tree();
    }
    Node *_assign_range(int l, int r, const vector<VAL> &init)
    {
        if (r - l == 1) {
            auto t = _make_node(init[l]);
            return _revise_val(t);
        }
        return merge(_assign_range(l, (l + r) / 2, init), _assign_range((l + r) / 2, r, init));
    }

    // vec
    void dump(Node *t, vector<VAL> &vec)
    {
        if (t == nullptr) return;
        _resolve_dval(t);
        dump(t->l, vec);
        vec.push_back(t->val);
        dump(t->r, vec);
    }

    // gc
    void re_alloc(Node *&root)
    {
        vector<VAL> mem;
        dump(root, mem);
        assign(root, mem);
    }
};


constexpr int INF = 1e9 + 10;
int main()
{
    int N;
    cin >> N;
    vector<pint> qc;
    while (N--)
    {
        int c, q;
        cin >> c >> q;
        qc.emplace_back(-q, c);
    }
    sort(qc.begin(), qc.end());

    int Q;
    cin >> Q;

    constexpr int mem_size = 400000;
    RandomizedBinarySearchTree<mem_size> rbst(make_pair(0, 0));
    auto S = rbst.new_tree();

    vector<pint> query;
    REP(i, Q)
    {
        int b;
        cin >> b;
        query.emplace_back(b, i);
    }
    sort(query.begin(), query.end());
    REP(i, query.size())
    {
        rbst.insert(S, i, node(query[i].second, query[i].first));
    }

    int iter = 0;
    for (auto [_, c] : qc)
    {
        auto [l, r] = rbst.split(S, rbst.lower_bound(S, c));
        if (r != nullptr)
        {
            rbst.range_set(r, 0, rbst.size(r), plint(c, 1));
        }
        S = rbst.merge(l, r);

        iter++;
        if (iter == 10000)
        {
            iter = 0;
            rbst.re_alloc(S);
        }
    }

    vector<node> vec;
    rbst.dump(S, vec);
    vector<int> ret(Q);
    for (auto v : vec) ret[v.id_] = v.cnt;
    for (auto x : ret) cout << x << ' ';
    cout << '\n';
}