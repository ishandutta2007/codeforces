#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int N = 100000;

int n, m, color[N], params[N][3];
std::vector <int> tree[N], queries[N];

struct Node;

Node* null;

struct Node {
    int key, weight, count, size;
    Node* children[2];

    Node(int key, int count) : key(key), weight(rand()), count(count) {
        children[0] = children[1] = null;
        update();
    }

    void update() {
        size = children[0]->size + count + children[1]->size;
    }

    int query(int k) {
        if (this == null) {
            return 0;
        }
        if (key < k) {
            return children[1]->query(k);
        }
        return children[0]->query(k) + count + children[1]->size;
    }
};

void rotate(Node *&x, int t) {
    Node *y = x->children[t];
    x->children[t] = y->children[t ^ 1];
    y->children[t ^ 1] = x;
    x->update();
    y->update();
    x = y;
}

void insert(Node *&v, int key, int delta) {
    if (v == null) {
        v = new Node(key, delta);
    } else if (v->key == key) {
        v->count += delta;
    } else {
        int t = v->key < key;
        insert(v->children[t], key, delta);
        if (v->children[t]->weight < v->weight) {
            rotate(v, t);
        }
    }
    v->update();
}

typedef std::pair <std::map <int, int>*, Node*> Pair;

bool compare(const Pair &a, const Pair &b) {
    return a.first->size() > b.first->size();
}

Pair go(int p, int u) {
    std::map <int, int>* map;
    Node* set = null;
    std::vector <Pair> children;
    foreach (it, tree[u]) {
        int v = *it;
        if (v != p) {
            children.push_back(go(u, v));
        }
    }
    std::sort(children.begin(), children.end(), compare);
    if (children.empty()) {
        map = new std::map <int, int>();
    } else {
        map = children[0].first;
        set = children[0].second;
    }
    for (int i = 1; i < (int)children.size(); ++ i) {
        foreach (it, *(children[i].first)) {
            int k = it->first;
            insert(set, (*map)[k], -1);
            (*map)[k] += it->second;
            insert(set, (*map)[k], 1);
        }
    }
    int k = color[u];
    insert(set, (*map)[k], -1);
    (*map)[k] ++;
    insert(set, (*map)[k], 1);
    foreach (it, queries[u]) {
        params[*it][2] = set->query(params[*it][1]);
    }
    return std::make_pair(map, set);
}

int main() {
    null = new Node(0, 0);
    null->size = 0;
    null->weight = INT_MAX;
    null->children[0] = null->children[1] = null;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", color + i);
    }
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d", params[i], params[i] + 1);
        queries[-- params[i][0]].push_back(i);
    }
    go(-1, 0);
    for (int i = 0; i < m; ++ i) {
        printf("%d\n", params[i][2]);
    }
    return 0;
}