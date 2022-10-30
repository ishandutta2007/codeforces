#include <vector>
//#include <functional>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 200000;

int n, m, size[N];
long long result;
std::vector<int> tree[N];

void dfs(int p, int u)
{
    for (auto&& v : tree[u]) {
        if (v != p) {
            dfs(u, v);
            result += std::min(size[v], m + m - size[v]);
            size[u] += size[v];
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(size, 0, sizeof(size));
    for (int i = 0; i < m + m; ++ i) {
        int u;
        scanf("%d", &u);
        size[u - 1] ++;
    }
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    result = 0;
    dfs(-1, 0);
    std::cout << result << std::endl;
}