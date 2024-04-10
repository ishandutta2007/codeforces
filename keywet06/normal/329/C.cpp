#include <bits/stdc++.h>

using namespace std;

const int N = 131072;
const int M = 10000000;

int n, m, tot;
int deg[N];

std::vector<int> v[N];

std::set<std::pair<int, int> > edges, used;

int rd21() {
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        int add = (rand() & (((1 << 7) - 1) << 7)) >> 7;
        ret |= (add << (i * 7));
    }
    return ret;
}

bool eval() {
    used.clear();
    for (int i = 0; i < n; ++i) {
        v[i].clear();
        deg[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int node1 = -1, node2 = -1;
        int inn = 0, limit = 100000;
        while (true) {
            ++tot;
            if (tot > M) return false;
            ++inn;
            if (inn > limit) return false;
            node1 = rd21() % n;
            while (deg[node1] >= 2) {
                ++tot;
                if (tot > M) return false;
                ++inn;
                if (inn > limit) return false;
                node1 = rd21() % n;
            }
            node2 = rd21() % n;
            while (deg[node2] >= 2) {
                ++tot;
                if (tot > M) return false;
                ++inn;
                if (inn > limit) return false;
                node2 = rd21() % n;
            }
            if (node1 == node2) continue;
            if (node1 > node2) swap(node1, node2);
            if (edges.find(make_pair(node1, node2)) != edges.end()) continue;
            if (used.find(make_pair(node1, node2)) != used.end()) continue;
            break;
        }
        ++deg[node1], ++deg[node2];
        v[node1].push_back(node2);
        used.insert(make_pair(node1, node2));
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        std::cin >> node1 >> node2;
        --node1, --node2;
        edges.insert(make_pair(min(node1, node2), max(node1, node2)));
    }
    tot = 0;
    while (true) {
        if (eval()) {
            for (int i = 0; i < n; ++i) {
                for (int c = 0; c < (int)v[i].size(); ++c) {
                    std::cout << i + 1 << ' ' << v[i][c] + 1 << '\n';
                }
            }
            return 0;
        }
        if (tot > M) break;
    }
    std::cout << -1 << '\n';
    return 0;
}