#include <bits/stdc++.h>
using namespace std;

struct Node;

std::deque<Node> cache;

Node* fetch_new() {
    cache.emplace_back();
    return &cache.back();
}

Node* fetch_new(Node const& node) {
    cache.emplace_back(node);
    return &cache.back();
}

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    std::pair<int, int> data = {std::numeric_limits<int>::max(), -1};

    void build(int l, int r) {
        if (l + 1 < r) {
            int m = (l + r) / 2;
            left = fetch_new();
            right = fetch_new();
            left->build(l, m);
            right->build(m, r);
        }
    }

    Node* set(int pos, int x, int l, int r) {
        Node* neww = fetch_new(*this);

        if (l + 1 == r) {
            neww->data = {x, pos};
        } else {
            int m = (l + r) / 2;
            if (pos < m)
                neww->left = neww->left->set(pos, x, l, m);
            else
                neww->right = neww->right->set(pos, x, m, r);
            neww->data = std::min(neww->left->data, neww->right->data);
        }
        return neww;
    }

    std::pair<int, int> min(int bl, int br, int l, int r) {
        if (bl >= r || br <= l)
            return {std::numeric_limits<int>::max(), -1};

        if (bl <= l && r <= br)
            return data;

        int m = (l + r) / 2;
        return std::min(left->min(bl, br, l, m), right->min(bl, br, m, r));
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int M = 5e5 + 1;

    vector<int> last(M, -1);
    vector<Node*> start(n + 1, nullptr);
    start[0] = fetch_new();
    start[0]->build(0, n);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto node = start[i];
        if (last[x] != -1)
            node = node->set(last[x], std::numeric_limits<int>::max(), 0, n);
        start[i+1] = node->set(i, last[x], 0, n);
        last[x] = i;
        v[i] = x;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto [min, pos] = start[r+1]->min(l, r+1, 0, n);
        if (min < l)
            cout << v[pos] << '\n';
        else
            cout << 0 << '\n';
    }
}