#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Splay>
struct basic_splay {
    Splay* parent = nullptr;
    Splay* kids[2] = {};

  protected:
    basic_splay() = default;

    Splay* self() { return static_cast<Splay*>(this); }
    const Splay* self() const { return static_cast<const Splay*>(this); }

  private:
    using TwoSplays = pair<Splay*, Splay*>;
    using ThreeSplays = tuple<Splay*, Splay*, Splay*>;

    static int get_size(const Splay* x) { return Splay::get_size(x); }
    static auto get_key(const Splay* x) { return Splay::get_key(x); }

    bool is_root() const { return !parent; }
    bool is_left() const { return !parent || self() == parent->kids[0]; }
    bool is_right() const { return parent && self() == parent->kids[1]; }

    static void adopt_node(Splay* parent, Splay* kid, int8_t side) {
        if (side >= 0)
            parent->kids[side] = kid;
        if (kid)
            kid->parent = parent;
    }

    static void attach_node(Splay* u, Splay* kid, int8_t side) {
        if (kid) {
            adopt_node(u, kid, side);
            u->pushup();
        }
    }

    static void rotate(Splay* u) {
        Splay *p = u->parent, *g = p->parent;
        int8_t u_side = u == p->kids[1];
        int8_t p_side = g ? p == g->kids[1] : -1;
        adopt_node(p, u->kids[!u_side], u_side);
        adopt_node(g, u, p_side);
        adopt_node(u, p, !u_side);
        p->pushup();
    }

    // Cut the edge from u to u->kids[side] and return the kid
    static Splay* detach_kid(Splay* u, int8_t side) {
        Splay* kid = u->kids[side];
        if (kid) {
            kid->parent = u->kids[side] = nullptr;
            u->pushup();
        }
        return kid;
    }

    // Cut the edge from u to its parent and return the parent
    static Splay* detach_parent(Splay* u) {
        Splay* parent = u->parent;
        if (parent) {
            parent->kids[u == parent->kids[1]] = u->parent = nullptr;
            parent->pushup();
        }
        return parent;
    }

    static Splay* min_node(Splay* u) {
        u->pushdown();
        while (u->kids[0])
            u = u->kids[0], u->pushdown();
        return u;
    }

    static Splay* max_node(Splay* u) {
        u->pushdown();
        while (u->kids[1])
            u = u->kids[1], u->pushdown();
        return u;
    }

    static Splay* findroot(Splay* u) {
        while (u->parent)
            u = u->parent, u->pushdown();
        return u;
    }

    static Splay* splay_unsafe(Splay* u) {
        if (!u->parent) {
            return u;
        }
        while (u->parent && u->parent->parent) {
            u->parent->parent->pushdown(), u->parent->pushdown(), u->pushdown();
            bool zigzig = u->is_right() == u->parent->is_right();
            rotate(zigzig ? u->parent : u), rotate(u);
        }
        if (u->parent) {
            u->parent->pushdown(), u->pushdown(), rotate(u);
        }
        u->pushdown(), u->pushup();
        return u;
    }

  public:
    Splay* clone() const {
        Splay* node = new Splay(*self());
        node = node->parent = node->kids[0] = node->kids[1] = nullptr;
        return node;
    }

    friend Splay* splay(Splay* u) {
        return u ? !u->parent ? u->pushdown(), u->pushup(), u : splay_unsafe(u) : nullptr;
    }

    friend Splay* splay(Splay*& tree, Splay* u) { return u ? tree = splay(u) : tree; }

    friend void delete_all(Splay* u) {
        if (u) {
            delete_all(u->kids[0]);
            delete_all(u->kids[1]);
            delete u;
        }
    }

    friend Splay* predecessor(Splay*& tree, Splay* index) {
        if (!index) {
            return back(tree);
        } else if (index->kids[0]) {
            return tree = splay(max_node(index->kids[0]));
        } else {
            tree = splay(index);
            return index->kids[0] ? tree = splay(max_node(index->kids[0])) : nullptr;
        }
    }

    friend Splay* successor(Splay*& tree, Splay* index) {
        if (!index) {
            return front(tree);
        } else if (index->kids[1]) {
            return tree = splay(min_node(index->kids[1]));
        } else {
            tree = splay(index);
            return index->kids[1] ? tree = splay(min_node(index->kids[1])) : nullptr;
        }
    }

    friend Splay* insert_before(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[0]) {
                attach_node(index, item, 0);
            } else {
                attach_node(max_node(index->kids[0]), item, 1);
            }
            return tree = splay(item);
        } else {
            return push_back(tree, item);
        }
    }

    friend Splay* insert_after(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[1]) {
                attach_node(index, item, 1);
            } else {
                attach_node(min_node(index->kids[1]), item, 0);
            }
            return tree = splay(item);
        } else {
            return push_front(tree, item);
        }
    }

    friend Splay* back(Splay*& tree) {
        return tree ? tree = splay(max_node(tree)) : nullptr;
    }

    friend Splay* front(Splay*& tree) {
        return tree ? tree = splay(min_node(tree)) : nullptr;
    }

    friend Splay* push_back(Splay*& tree, Splay* item) {
        if (item) {
            return tree = tree ? attach_node(max_node(tree), item, 1), splay(item) : item;
        }
        return item;
    }

    friend Splay* push_front(Splay*& tree, Splay* item) {
        if (item) {
            tree = tree ? attach_node(min_node(tree), item, 0), splay(item) : item;
        }
        return item;
    }

    friend Splay* pop_back(Splay*& tree) {
        if (tree) {
            Splay* item = splay(max_node(tree));
            tree = detach_kid(item, 0);
            return item;
        }
        return nullptr;
    }

    friend Splay* pop_front(Splay*& tree) {
        if (tree) {
            Splay* item = splay(min_node(tree));
            tree = detach_kid(item, 1);
            return item;
        }
        return nullptr;
    }

    friend void delete_back(Splay*& tree) {
        if (tree) {
            Splay* item = pop_back(tree);
            delete item;
        }
    }

    friend void delete_front(Splay*& tree) {
        if (tree) {
            Splay* item = pop_front(tree);
            delete item;
        }
    }

    // Access the range (L...R). If L,R are both null it accesses everything
    friend Splay* access_exclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* S = nullptr;
        if (L && R) {
            splay(R), splay(L);
            if (R->parent != L) {
                R->parent->pushdown();
                R->pushdown();
                rotate(R);
                R->pushup();
            }
            assert(R->parent == L);
            S = R->kids[R->is_left()];
        } else if (L) {
            S = splay(L)->kids[1];
        } else if (R) {
            S = splay(R)->kids[0];
        } else {
            return tree;
        }
        if (S) {
            S->pushdown(), S->pushup();
        }
        tree = L ? L : R;
        return S;
    }

    friend Splay* access_inclusive(Splay*& tree, Splay* L, Splay* R) {
        return access_exclusive(tree, predecessor(tree, L), successor(tree, R));
    }

    friend Splay* access_range(Splay*& tree, Splay* L, Splay* R) {
        return access_exclusive(tree, predecessor(tree, L), R);
    }

    // Splice the range (L...R). If L,R are both null it splices everything
    friend Splay* splice_exclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_exclusive(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* splice_inclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_inclusive(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* splice_range(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_range(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    // Delete the range (L...R). If L,R are both null it deletes everything
    friend void delete_exclusive(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_exclusive(tree, L, R));
    }

    friend void delete_inclusive(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_inclusive(tree, L, R));
    }

    friend void delete_range(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_range(tree, L, R));
    }

    // Splice (remove but not delete) one item from the sequence
    friend Splay* splice_item(Splay*& tree, Splay* item) {
        return splice_inclusive(tree, item, item);
    }

    friend void delete_item(Splay*& tree, Splay* item) { delete splice_item(tree, item); }

    // Split into two sequences: [...A)[A...)
    friend TwoSplays split_before(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {detach_kid(node, 0), node};
        } else {
            return {tree, nullptr};
        }
    }

    // Split into two sequences: [...A](A...)
    friend TwoSplays split_after(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {node, detach_kid(node, 1)};
        } else {
            return {nullptr, tree};
        }
    }

    // Split into three sequences: [...A)[A...B)[B...)
    friend ThreeSplays split_range(Splay*& tree, Splay* A, Splay* B) {
        auto [mid, c] = split_before(tree, B);
        auto [a, b] = split_before(mid, A);
        return {a, b, c};
    }

    friend Splay* join(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        splay(A), splay(B), assert(A->is_root() && A != B);
        Splay* root = splay(max_node(A));
        attach_node(root, B, 1);
        return root;
    }

    friend Splay* join(Splay* A, Splay* B, Splay* C) { return join(join(A, B), C); }

    friend Splay* join_if_disjoint(Splay* A, Splay* B) {
        if (!A || !B || A == B) {
            return A ? A : B;
        }
        splay(A), splay(B);
        if (A->is_root()) {
            Splay* root = splay(max_node(A));
            attach_node(root, B, 1);
            return root;
        } else {
            return B;
        }
    }

    friend Splay* join_if_disjoint(Splay* A, Splay* B, Splay* C) {
        return join_if_disjoint(join_if_disjoint(A, B), C);
    }

    template <typename... Args>
    [[nodiscard]] static Splay* construct(int N, Args&&... args) {
        if (N == 0) {
            return nullptr;
        } else {
            Splay* node = new Splay(args...);
            attach_node(node, construct(N / 2, args...), 0);
            attach_node(node, construct((N - 1) / 2, args...), 1);
            return node;
        }
    }

    template <typename T>
    [[nodiscard]] static Splay* construct_array(int N, const vector<T>& arr, int s = 0) {
        if (N == 0) {
            return nullptr;
        } else {
            int L = N / 2, R = (N - 1) / 2;
            Splay* node = new Splay(arr[s + L]);
            attach_node(node, construct_array(L, arr, s), 0);
            attach_node(node, construct_array(R, arr, s + 1 + L), 1);
            return node;
        }
    }

    // ***** Order operations

    // Find order of an item (0-indexed)
    friend int order_of_node(Splay*& tree, Splay* item) {
        if (item) {
            tree = splay(item);
            return tree ? get_size(tree->kids[0]) : 0;
        } else {
            return get_size(tree);
        }
    }

    // Find the item with this exact order, or nullptr if order is out of bounds
    friend Splay* find_order(Splay*& tree, int order) {
        if (!tree || order < 0 || order >= get_size(tree)) {
            return nullptr;
        }
        while (true) {
            tree->pushdown();
            int left = get_size(tree->kids[0]);
            if (order < left) {
                tree = tree->kids[0];
            } else if (order > left) {
                order -= left + 1;
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
    }

    // Insert item just before the given order (accepts out of bounds orders)
    friend Splay* insert_order(Splay*& tree, Splay* item, int order) {
        if (!tree) {
            return tree = item;
        } else if (order <= 0) {
            return push_front(tree, item);
        } else if (order >= get_size(tree)) {
            return push_back(tree, item);
        } else {
            return insert_before(tree, find_order(tree, order), item);
        }
    }

    // Access the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend Splay* access_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return access_exclusive(tree, A, B);
        }
    }

    friend Splay* access_order_inclusive(Splay*& tree, int L, int R) {
        return access_order_exclusive(tree, L - 1, R + 1);
    }

    friend Splay* access_order_range(Splay*& tree, int L, int R) {
        return access_order_exclusive(tree, L - 1, R);
    }

    // Splice the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend Splay* splice_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return splice_exclusive(tree, A, B);
        }
    }

    friend Splay* splice_order_inclusive(Splay*& tree, int L, int R) {
        return splice_order_exclusive(tree, L - 1, R + 1);
    }

    friend Splay* splice_order_range(Splay*& tree, int L, int R) {
        return splice_order_exclusive(tree, L - 1, R);
    }

    // Delete the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend void delete_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            delete_exclusive(tree, A, B);
        }
    }

    friend void delete_order_inclusive(Splay*& tree, int L, int R) {
        delete_order_exclusive(tree, L - 1, R + 1);
    }

    friend void delete_order_range(Splay*& tree, int L, int R) {
        delete_order_exclusive(tree, L - 1, R);
    }

    // Splice (remove but not delete) one item from the sequence
    friend Splay* splice_order(Splay*& tree, int order) {
        auto node = find_order(tree, order);
        if (node) {
            tree = join(detach_kid(tree, 0), detach_kid(tree, 1));
            return node;
        } else {
            return nullptr;
        }
    }

    friend void delete_order(Splay*& tree, int order) {
        delete splice_order(tree, order);
    }

    // Split into two sequences: {order(u)<order} {order<=order(u)}
    friend TwoSplays split_order(Splay*& tree, int order) {
        if (order >= 1) {
            return split_before(tree, find_order(tree, order));
        } else {
            return {nullptr, tree};
        }
    }

    // Split into three sequences: {order(u)<L} {L<=order(u)<R} {R<=order(u)}
    friend ThreeSplays split_order_range(Splay*& tree, int L, int R) {
        auto [mid, c] = split_order(tree, R);
        auto [a, b] = split_order(mid, L);
        return {a, b, c};
    }

    // ***** Key operations

    // Find first item s.t. item->key >= key, or nullptr for end (lower_bound)
    template <typename Key>
    friend Splay* after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(get_key(tree) < key)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find first item s.t. item->key > key, or nullptr for end (upper_bound)
    template <typename Key>
    friend Splay* strict_after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find last item s.t. item->key <= key, or nullptr for end (reverse lower_bound)
    template <typename Key>
    friend Splay* before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(key < get_key(tree))) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find last item s.t. item->key < key, or nullptr for end (reverse upper_bound)
    template <typename Key>
    friend Splay* strict_before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (get_key(tree) < key) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find first item s.t. item->key = key
    template <typename Key>
    friend Splay* find_key(Splay*& tree, const Key& key) {
        Splay* last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                tree = tree->kids[0];
            } else if (get_key(tree) < key) {
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
        tree = splay(last);
        return nullptr;
    }

    // Insert item(s) in search position, returning the item splayed
    friend Splay* insert_key(Splay*& tree, Splay* item) {
        if (!item) {
            return tree;
        } else if (!tree) {
            return tree = item;
        } else if (Splay* ahead = after(tree, get_key(item))) {
            return insert_before(tree, ahead, item);
        } else {
            return push_back(tree, item);
        }
    }

    // Access the nodes s.t. L < node->key < R, possibly nullptr if none
    template <typename Key>
    friend Splay* access_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return access_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* access_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return access_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* access_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return access_exclusive(tree, A, B);
    }

    // Splice the range of nodes s.t. L < node->key < R
    template <typename Key>
    friend Splay* splice_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* splice_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* splice_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    // Delete the range of nodes s.t. L < node->key < R
    template <typename Key>
    friend void delete_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        delete_exclusive(tree, A, B);
    }

    template <typename Key>
    friend void delete_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        delete_exclusive(tree, A, B);
    }

    template <typename Key>
    friend void delete_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        delete_exclusive(tree, A, B);
    }

    // Splice the first item with exact given key
    template <typename Key>
    friend Splay* splice_key(Splay*& tree, const Key& key) {
        if (auto item = find_key(tree, key)) {
            return splice_item(tree, item);
        } else {
            return nullptr;
        }
    }

    template <typename Key>
    friend void delete_key(Splay*& tree, const Key& key) {
        delete splice_key(tree, key);
    }

    // Split into two sequences: {node<key} {key<=node}
    template <typename Key>
    friend TwoSplays split_key(Splay*& tree, const Key& key) {
        if (auto succ = after(tree, key)) {
            return split_before(tree, succ);
        } else {
            return {tree, nullptr};
        }
    }

    // Split into three sequences: {node<L} {L<=node<R} {R<=node}
    template <typename Key>
    friend ThreeSplays split_key_range(Splay*& tree, const Key& L, const Key& R) {
        auto [mid, c] = split_key(tree, R);
        auto [a, b] = split_key(mid, L);
        return {a, b, c};
    }

    friend Splay* meld(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        A->pushdown(), B->pushdown();
        auto [L, R] = split_key(B, get_key(A));
        Splay* X = detach_kid(A, 0);
        Splay* Y = detach_kid(A, 1);
        attach_node(A, meld(L, X), 0);
        attach_node(A, meld(R, Y), 1);
        return A;
    }

    friend Splay* meld(Splay* A, Splay* B, Splay* C) { return meld(meld(A, B), C); }

    friend vector<Splay*> unstitch(Splay* A) {
        vector<Splay*> nodes = get_inorder_vector(A);
        for (Splay* node : nodes) {
            node->parent = node->kids[0] = node->kids[1] = nullptr;
            node->pushup();
        }
        return nodes;
    }

    friend Splay* stitch_dfs(const vector<Splay*>& nodes, int L, int R, Splay* parent) {
        if (L >= R) {
            return nullptr;
        }
        int M = (L + R) / 2;
        Splay* root = nodes[M];
        root->parent = parent;
        root->kids[0] = stitch_dfs(nodes, L, M, root);
        root->kids[1] = stitch_dfs(nodes, M + 1, R, root);
        root->pushup();
        return root;
    }

    friend Splay* stitch(const vector<Splay*>& nodes) {
        return stitch_dfs(nodes, 0, nodes.size(), nullptr);
    }

    friend vector<Splay*> get_inorder_vector(Splay* node) {
        vector<Splay*> vec;
        visit_inorder(node, [&vec](Splay* x) { vec.push_back(x); });
        return vec;
    }

    template <typename Fn>
    friend void visit_inorder(Splay* node, Fn&& fn) {
        if (node) {
            node->pushdown();
            auto [a, b] = node->kids;
            visit_inorder(a, fn);
            fn(node);
            visit_inorder(b, fn);
        }
    }

    // ***** Debugging

    friend string format_inorder(Splay* node) {
        int id = 0;
        string s;
        visit_inorder(node, [&](Splay* child) {
            s += " [" + to_string(id++) + "] " + child->format() + '\n';
        });
        return s;
    }
};

// Remember: updates should generally maintain that the current node is up-to-date (does
// not need pushup) but may need pushdown.
struct Splay : basic_splay<Splay> {
    int size = 1;
    int key;
    int value = 0;

    explicit Splay(int key, int value) : key(key), value(value) {}

    static auto get_key(const Splay* x) { return x->key; }
    static int get_size(const Splay* x) { return x ? x->size : 0; }
    static int get_value(const Splay* x) { return x ? x->value : 0; }

    void pushdown() {
        if (kids[0])
            kids[0]->value = value;
        if (kids[1])
            kids[1]->value = value;
    }

    void pushup() { size = 1 + get_size(kids[0]) + get_size(kids[1]); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, Splay*> trees;
    vector<Splay*> index(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        push_back(trees[A[i]], index[i] = new Splay(i, A[i]));
    }
    auto get = [&](int i) {
        splay(index[i]);
        int v = index[i]->value;
        trees[v] = index[i];
        return v;
    };
    int Q;
    cin >> Q;
    while (Q--) {
        if (int t; cin >> t, t == 1) {
            int i, w;
            cin >> i >> w, i--;
            int v = get(i);
            splice_item(trees[v], index[i]);
            index[i]->value = w;
            insert_key(trees[w], index[i]);
        } else if (t == 2) {
            int i;
            cin >> i, i--;
            int v = get(i);
            cout << v << '\n';
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            int m = (l + r + 1) / 2;

            Splay* high = nullptr;
            Splay* low = nullptr;
            auto it = trees.lower_bound(m);
            while (it != end(trees) && it->first <= r) {
                high = meld(high, it->second);
                trees.erase(it++);
            }
            while (it != begin(trees) && prev(it)->first >= l) {
                low = meld(low, prev(it)->second);
                trees.erase(prev(it));
            }
            if (high) {
                high = trees[r + 1] = meld(trees[r + 1], high);
                high->value = r + 1;
            }
            if (low) {
                low = trees[l - 1] = meld(trees[l - 1], low);
                low->value = l - 1;
            }
        } else {
            assert(false);
        }
    }
    return 0;
}