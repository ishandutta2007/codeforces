#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const lint M = 5e5 + 10, MOD = 998244353;

struct Node {
    Node *p, *l, *r;
    int idx, lazy, val, size;

    Node(int idx, int val) : lazy(0), idx(idx), val(val), size(1), p(NULL), l(NULL), r(NULL) {}

    void down() {
        if (!lazy) return;
        val += lazy;
        l ? l->lazy += lazy : 0;
        r ? r->lazy += lazy : 0;
        lazy = 0;
    }
    void update() {
        size = 1 + (r ? r->size : 0) + (l ? l->size : 0);
    }
    void rotate() {
        if (p == NULL) return;
        Node *x = p;
        if (x->p) {
            (x->p->l == x ? x->p->l : x->p->r) = this;
        }
        if (p->l == this) {
            if (r) r->p = x;
            p = x->p; x->p = x->l; x->l = r; r = x;
        }
        else {
            if (l) l->p = x;
            p = x->p; x->p = x->r; x->r = l; l = x;
        }
        x->update(); update();
    }
};

struct SplayTree {
    Node *root; int t_size;

    SplayTree() : root(NULL), t_size(0) {}
    int size() { return t_size; }

    Node *splay(Node *x) {
        while (x->p && x->p->p) {
            if (x == x->p->l ^ x->p == x->p->p->l) {
                x->rotate(); x->rotate();
            }
            else x->p->rotate(), x->rotate();
        }
        if (x->p) x->rotate();
        return root = x;
    }
    Node *lower_bound(int val) {
        Node *head = root, *ret = NULL;
        while (head) {
            head->down();
            if (head->val < val) head = head->r;
            else {
                ret = head; head = head->l;
            }
        }
        if (ret == NULL) return NULL;
        return splay(ret);
    }
    Node *insert(int idx, int val) {
        Node *x = lower_bound(val);
        Node *new_node = new Node(idx, val);
        t_size += 1;

        if (x == NULL) {
            if (root == NULL) {
                root = new_node; return new_node;
            }
            Node *head = root;
            while (head->r) {
                head->down(); head = head->r;
            }
            head->r = new_node; new_node->p = head;
            return splay(new_node);
        }
        if (x->l == NULL) {
            x->l = new_node; new_node->p = x;
            splay(new_node);
            new_node->r->lazy++; return new_node;
        }
        x->down(); x = x->l;
        while (x->r) {
            x->down(); x = x->r;
        }
        x->r = new_node; new_node->p = x;
        splay(new_node);
        new_node->r->lazy++; return new_node;
    }
    void iterate(vector<pint> &Res, Node *cur) {
        if (cur == NULL) return; cur->down();
        iterate(Res, cur->l);
        Res.emplace_back(cur->val, cur->idx);
        iterate(Res, cur->r);
    }
} St;

int n, m;
lint F[M], IF[M];

lint _pow(lint a, lint x = MOD - 2) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        x /= 2; a = a * a % MOD;
    }
    return ret;
}
lint comb(lint n, lint k) {
    return F[n] * IF[n - k] % MOD * IF[k] % MOD;
}
void solve() {
    cin >> n >> m;
    vector<int> A, B, X, Y;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        X.push_back(x); Y.push_back(y);
    }

    SplayTree *St = new SplayTree();
    for (int i = 0; i < m; i++) {
        St->insert(X[i], Y[i]);
    }
    vector<pint> V;
    St->iterate(V, St->root);
    
    set<int> S;
    sort(V.begin(), V.end(), [&](pint a, pint b) {
        return a.vb < b.vb;
        });
    for (auto [a, b] : V) {
        if (a == 1) S.insert(a);
        else {  
            if (S.find(a - 1) != S.end()) S.erase(a - 1);
            S.insert(a);
        }
    }

    int x = S.size();
    cout << comb(n + (n - 1) - x, n) << '\n';
    delete St;
}
int main() {
    F[0] = 1;
    for (int i = 1; i < M; i++) {
        F[i] = F[i - 1] * i % MOD;
    }
    IF[M - 1] = _pow(F[M - 1]);
    for (int i = M - 1; i >= 1; i--) {
        IF[i - 1] = IF[i] * i % MOD;
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }

}