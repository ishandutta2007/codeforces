#include <algorithm>
#include <limits>
#include <vector>

// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: $O(N)$ (construction), $O(\log N)$ (add / get / prod)
// - RangeAddRangeMin(std::vector<Tp> data_init) : Initialize array x by data_init.
// - add(int begin, int end, Tp vadd) : Update x[i] <- x[i] + vadd for all begin <= i < end.
// - get(int pos) : Get x[pos].
// - prod(int begin, int end) : Get min(x[begin], ..., x[end - 1]).
template <typename Tp, Tp defaultT = std::numeric_limits<Tp>::max() / 2> struct RangeAddRangeMin {
    int N, head;
    std::vector<Tp> range_min, range_add;
    static inline Tp f(Tp x, Tp y) noexcept { return std::min(x, y); }

    inline void _merge(int pos) {
        range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]);
    }
    void initialize(const std::vector<Tp> &data_init) {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        range_min.assign(head * 2, defaultT);
        range_add.assign(head * 2, 0);
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    RangeAddRangeMin() = default;
    RangeAddRangeMin(const std::vector<Tp> &data_init) { initialize(data_init); }
    void _add(int begin, int end, int pos, int l, int r, Tp vadd) noexcept {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end) {
            range_add[pos] += vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    // Add `vadd` to (x_begin, ..., x_{end - 1})
    void add(int begin, int end, Tp vadd) noexcept { return _add(begin, end, 1, 0, head, vadd); }
    Tp _get(int begin, int end, int pos, int l, int r) const noexcept {
        if (r <= begin or end <= l) return defaultT;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    // Return f(x_begin, ..., x_{end - 1})
    Tp get(int pos) const noexcept { return prod(pos, pos + 1); }
    Tp prod(int begin, int end) const noexcept { return _get(begin, end, 1, 0, head); }
};

#include <algorithm>
#include <cassert>
#include <fstream>
#include <string>
#include <vector>

// Permutation tree
// Complexity: O(N log N)
// https://codeforces.com/blog/entry/78898 https://yukicoder.me/problems/no/1720
struct permutation_tree {
    enum NodeType {
        JoinAsc,
        JoinDesc,
        Cut,
        Leaf,
        None,
    };
    struct node {
        NodeType tp;
        int L, R;       // i in [L, R)
        int mini, maxi; // A[i] in [mini, maxi]
        std::vector<int> child;
        int sz() const { return R - L; }
        template <class OStream> friend OStream &operator<<(OStream &os, const node &n) {
            os << "[[" << n.L << ',' << n.R << ")(ch:";
            for (auto i : n.child) os << i << ',';
            return os << ")(tp=" << n.tp << ")]";
        }
    };

    int root;
    std::vector<int> A;
    std::vector<node> nodes;

    void _add_child(int parid, int chid) {
        nodes[parid].child.push_back(chid);
        nodes[parid].L = std::min(nodes[parid].L, nodes[chid].L);
        nodes[parid].R = std::max(nodes[parid].R, nodes[chid].R);
        nodes[parid].mini = std::min(nodes[parid].mini, nodes[chid].mini);
        nodes[parid].maxi = std::max(nodes[parid].maxi, nodes[chid].maxi);
    }

    permutation_tree() : root(-1) {}
    permutation_tree(const std::vector<int> &A_) : root(-1), A(A_) { // A: nonempty perm., 0-origin
        assert(!A.empty());
        RangeAddRangeMin<int> seg((std::vector<int>(A.size())));

        std::vector<int> hi{-1}, lo{-1};
        std::vector<int> st;
        for (int i = 0; i < int(A.size()); ++i) {
            while (hi.back() >= 0 and A[i] > A[hi.back()]) {
                seg.add(hi[hi.size() - 2] + 1, hi.back() + 1, A[i] - A[hi.back()]);
                hi.pop_back();
            }
            hi.push_back(i);
            while (lo.back() >= 0 and A[i] < A[lo.back()]) {
                seg.add(lo[lo.size() - 2] + 1, lo.back() + 1, A[lo.back()] - A[i]);
                lo.pop_back();
            }
            lo.push_back(i);

            int h = nodes.size();
            nodes.push_back({NodeType::Leaf, i, i + 1, A[i], A[i], std::vector<int>{}});

            while (true) {
                NodeType join_tp = NodeType::None;
                if (!st.empty() and nodes[st.back()].maxi + 1 == nodes[h].mini) join_tp = JoinAsc;
                if (!st.empty() and nodes[h].maxi + 1 == nodes[st.back()].mini) join_tp = JoinDesc;

                if (!st.empty() and join_tp != NodeType::None) {
                    const node &vtp = nodes[st.back()];
                    // Insert v as the child of the top node in the stack
                    if (join_tp == vtp.tp) {
                        // Append child to existing Join node
                        _add_child(st.back(), h);
                        h = st.back();
                        st.pop_back();
                    } else {
                        // Make new join node (with exactly two children)
                        int j = st.back();
                        nodes.push_back(
                            {join_tp, nodes[j].L, nodes[j].R, nodes[j].mini, nodes[j].maxi, {j}});
                        st.pop_back();
                        _add_child(nodes.size() - 1, h);
                        h = nodes.size() - 1;
                    }
                } else if (seg.prod(0, i + 1 - nodes[h].sz()) == 0) {
                    // Make Cut node
                    int L = nodes[h].L, R = nodes[h].R, maxi = nodes[h].maxi, mini = nodes[h].mini;
                    nodes.push_back({NodeType::Cut, L, R, mini, maxi, {h}});
                    h = nodes.size() - 1;
                    do {
                        _add_child(h, st.back());
                        st.pop_back();
                    } while (nodes[h].maxi - nodes[h].mini + 1 != nodes[h].sz());
                    std::reverse(nodes[h].child.begin(), nodes[h].child.end());
                } else {
                    break;
                }
            }
            st.push_back(h);
            seg.add(0, i + 1, -1);
        }
        assert(st.size() == 1);
        root = st[0];
    }

    void to_DOT(std::string filename = "") const {
        if (filename.empty()) filename = "permutation_tree_v=" + std::to_string(A.size()) + ".DOT";

        std::ofstream ss(filename);
        ss << "digraph{\n";
        int nleaf = 0;
        for (int i = 0; i < int(nodes.size()); i++) {
            ss << i << "[\n";
            std::string lbl;
            if (nodes[i].tp == NodeType::Leaf) {
                lbl = "A[" + std::to_string(nleaf) + "] = " + std::to_string(A[nleaf]), nleaf++;
            } else {
                lbl += std::string(nodes[i].tp == NodeType::Cut ? "Cut" : "Join") + "\\n";
                lbl += "[" + std::to_string(nodes[i].L) + ", " + std::to_string(nodes[i].R) + ")";
            }
            ss << "label = \"" << lbl << "\",\n";
            ss << "]\n";
            for (const auto &ch : nodes[i].child) ss << i << " -> " << ch << ";\n";
        }
        ss << "{rank = same;";
        for (int i = 0; i < int(nodes.size()); i++) {
            if (nodes[i].tp == NodeType::Leaf) ss << ' ' << i << ';';
        }
        ss << "}\n";
        ss << "}\n";
        ss.close();
    }
};


#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    while (N--) {
        int r, c;
        cin >> r >> c;
        A[r - 1] = c - 1;
    }
    permutation_tree tree(A);

    auto rec = [&](auto &&self, int now) -> long long {
        long long ret = 1;
        const auto &v = tree.nodes[now];
        if (v.tp == permutation_tree::JoinAsc or v.tp == permutation_tree::JoinDesc) {
            ret = (long long)v.child.size() * (v.child.size() - 1) / 2;
        }
        for (auto c : v.child) ret += self(self, c);
        return ret;
    };
    cout << rec(rec, tree.root) << '\n';
}