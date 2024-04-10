#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

// Persistent Array
// Reference: <https://qiita.com/hotman78/items/9c643feae1de087e6fc5>
//            <https://ei1333.github.io/luzhiled/snippets/structure/persistent-array.html>
// - (2^LOG)-ary tree-based
// - Fully persistent
// - `get(root, k)`:  get k-th element
// - `set(root, k, data)`: make new array whose k-th element is updated to data
// - `ch(root, k, data)` : change k-th element and implicitly update root
template <typename T, int LOG>
struct persistent_array {
    T zero;
    struct node {
        T data;
        std::array<node*, 1 << LOG> child;
        node(const T &d) : data(d) {
            std::fill(child.begin(), child.end(), nullptr);
        }
        node(const node &n) : data(n.data) {
            std::copy(n.child.begin(), n.child.end(), child.begin());
        }
    };
    persistent_array(T zero) : zero(zero) {}

    T get(node *t, int k) const {
        if (t == nullptr) {
            return zero;
        }
        return k ? get(t->child[k & ((1 << LOG) - 1)], k >> LOG) : t->data;
    }

    [[nodiscard]] node *set(node *t, int k, const T &data) {
        t = (t == nullptr) ? new node(zero) : new node(*t);
        if (k == 0) {
            t->data = data;
        } else {
            auto ptr = set(t->child[k & ((1 << LOG) - 1)], k >> LOG, data);
            t->child[k & ((1 << LOG) - 1)] = ptr;
        }
        return t;
    }

    void ch(node *&t, int k, const T &data) {
        t = set(t, k, data);
    }

    [[nodiscard]] node *build(const std::vector<T> &vec) {
        node* root = nullptr;
        for (size_t i = 0; i < vec.size(); i++) {
            root = set(root, i, vec[i]);
        }
        return root;
    }
};

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    using bs = bitset<1000>;
    bs zero;
    bs mask;
    REP(i, M) {
        mask.set(i);
    }
    using arr = persistent_array<bs, 4>;

    arr V(zero);
    arr::node* ptr = nullptr;
    REP(i, N) {
        V.ch(ptr, i, zero);
    }
    int ret = 0;

    vector<int> rets { ret };
    vector<arr::node*> ptrs { ptr };

    REP(q, Q)
    {
        int t;
        cin >> t;
        if (t <= 2) {
            int i, j;
            cin >> i >> j;
            i--, j--;
            auto b = V.get(ptr, i);
            ret -= b.count();
            b[j] = 2 - t;
            ret += b.count();
            V.ch(ptr, i, b);
        } else if (t == 3) {
            int i;
            cin >> i;
            i--;
            auto b = V.get(ptr, i);
            ret -= b.count();
            b = b.flip() & mask;
            ret += b.count();
            V.ch(ptr, i, b);
        } else {
            int k;
            cin >> k;
            ret = rets.at(k);
            ptr = ptrs.at(k);
        }
        rets.emplace_back(ret);
        ptrs.emplace_back(ptr);
        cout << ret << '\n';
    }
}