#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int N = 100000;
const int D = 20;

int n, m;
std::vector <int> tree[N];

int jump[N][D], depth[N], position[N], order[N];

void prepare(int p, int u) {
    static int node_count = 0;
    order[node_count] = u;
    position[u] = node_count ++;
    depth[u] = p == -1 ? 0 : depth[p] + 1;
    jump[u][0] = p;
    for (int i = 0; jump[u][i] != -1; ++ i) {
        jump[u][i + 1] = jump[jump[u][i]][i];
    }
    foreach (iter, tree[u]) {
        int v = *iter;
        if (v != p) {
            prepare(u, v);
        }
    }
}

int get_lca(int u, int v) {
    if (depth[u] > depth[v]) {
        std::swap(u, v);
    }
    for (int i = 0; i < D; ++ i) {
        if (depth[v] - depth[u] >> i & 1) {
            v = jump[v][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = D - 1; i >= 0; -- i) {
        if (jump[u][i] != jump[v][i]) {
            u = jump[u][i];
            v = jump[v][i];
        }
    }
    return jump[u][0];
}

int get_distance(int u, int v) {
    int w = get_lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

int edge_count;
std::set <int> set;

void add_node(int u) {
    int p = position[u];
    assert(!set.count(p));
    if ((int)set.size() == 0) {
        set.insert(p);
        return;
    }
    std::set <int> :: iterator it = set.lower_bound(p);
    if (it == set.begin()) {
        edge_count += get_distance(u, order[*it]);
    } else {
        std::set <int> :: iterator it2 = it;
        it2 --;
        if (it == set.end()) {
            edge_count += get_distance(u, order[*it2]);
        } else {
            edge_count -= get_distance(order[*it], order[*it2]);
            edge_count += get_distance(u, order[*it]);
            edge_count += get_distance(u, order[*it2]);
        }
    }
    set.insert(p);
}

void remove_node(int u) {
    int p = position[u];
    assert(set.count(p));
    if ((int)set.size() == 1) {
        set.erase(p);
        return;
    }
    std::set <int> :: iterator it = set.lower_bound(p);
    if (it == set.begin()) {
        std::set <int> :: iterator it2 = it;
        it2 ++;
        edge_count -= get_distance(u, order[*it2]);
    } else {
        std::set <int> :: iterator it2 = it;
        it2 --;
        std::set <int> :: iterator it3 = it;
        it3 ++;
        if (it3 == set.end()) {
            edge_count -= get_distance(u, order[*it2]);
        } else {
            edge_count += get_distance(order[*it2], order[*it3]);
            edge_count -= get_distance(u, order[*it2]);
            edge_count -= get_distance(u, order[*it3]);
        }
    }
    set.erase(p);
}

int get_cost() {
    if (set.empty()) {
        return 0;
    }
    return edge_count + get_distance(order[*set.begin()], order[*set.rbegin()]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --, b --;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    memset(jump, -1, sizeof(jump));
    prepare(-1, 0);
    edge_count = 0;
    int result = 0;
    for (int i = 0, j = 0; i < n; ++ i) {
        add_node(i);
        while (get_cost() > 2 * (m - 1)) {
            remove_node(j ++);
        }
        result = std::max(result, i - j + 1);
    }
    printf("%d\n", result);
    return 0;
}