#include <bits/stdc++.h>

const int INF = 2e9;

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int priority;
    int size;
    int value;
    int add;

    explicit Node(int value): left(nullptr), right(nullptr), value(value) {
        priority = rand() ^ (rand() << 16);
        size = 1;
        add = 0;
    }
};

int getSize(Node *node) {
    return node ? node->size: 0;
}

void addToNode(Node *node, int value) {
    if (node) {
        node->value += value;
        node->add += value;
    }
}

void push(Node *node) {
    if (!node) return;
    addToNode(node->left, node->add);
    addToNode(node->right, node->add);
    node->add = 0;
}

void recalc(Node *node) {
    node->size = 1 + getSize(node->left) + getSize(node->right);
}

Node* Merge(Node *left, Node *right) {
    if (!right)
        return left;
    if (!left)
        return right;
    push(left);
    push(right);
    if (left->priority > right->priority) {
        left->right = Merge(left->right, right);
        recalc(left);
        return left;
    } else {
        right->left = Merge(left, right->left);
        recalc(right);
        return right;
    }
}

std::pair<Node*, Node*> Split(Node *node, int value) {
    if (!node)
        return {nullptr, nullptr};
    push(node);
    if (node->value < value) {
        Node *left, *right;
        std::tie(left, right) = Split(node->right, value);
        node->right = left;
        recalc(node);
        return {node, right};
    } else {
        Node *left, *right;
        std::tie(left, right) = Split(node->left, value);
        node->left = right;
        recalc(node);
        return {left, node};
    }
}

std::pair<Node*, Node*> SplitByKey(Node *node, int k) {
    if (!node)
        return {nullptr, nullptr};
    push(node);
    if (getSize(node->left) < k) {
        Node *left, *right;
        std::tie(left, right) = SplitByKey(node->right, k - 1 - getSize(node->left));
        node->right = left;
        recalc(node);
        return {node, right};
    } else {
        Node *left, *right;
        std::tie(left, right) = SplitByKey(node->left, k);
        node->left = right;
        recalc(node);
        return {left, node};
    }
}

void query(Node* &root, int ql, int qr) {
    Node *left, *mid, *right;
    Node *last;
    tie(left, right) = Split(root, ql);
    tie(mid, right) = Split(right, qr);
    tie(last, right) = SplitByKey(right, 1);
    delete last;
    addToNode(mid, 1);
    root = Merge(left, Merge(new Node(ql), Merge(mid, right)));
}

signed main() {
    //freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> qleft(n), qright(n);
    for (int i = 0; i < n; ++i) {
        cin >> qleft[i] >> qright[i];
    }

    Node *root = new Node(-INF);
    for (int i = 1; i <= n + 2; ++i) {
        root = Merge(root, new Node(INF + i));
    }
    for (int i = 0; i < n; ++i) {
        query(root, qleft[i], qright[i]);
    }

    Node *left, *right;
    tie(left, right) = Split(root, INF);
    cout << getSize(left) - 1 << '\n';
}