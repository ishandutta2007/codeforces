#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

// Finally

const int MAX_VALUES = (2e5);

vector <int> Adj[MAX_VALUES];

int Height[MAX_VALUES];

int nbNodes;

pair <int, int> Dfs(int node, int parent) {
    int sum = 0;
    int maxi = 0;
    for (int dest : Adj[node])
    {
        if (dest != parent)
        {
            pair <int, int> a = Dfs(dest, node);
            sum += a.first;
            maxi = max(maxi, a.second);
        }
    }
    if (maxi < Height[node])
    {
        sum += Height[node] - maxi;
        maxi = Height[node];
    }
    return {sum, maxi};
}

int DfsRoot(int root) {
    int sum = 0;
    int maxi1 = 0, maxi2 = 0;
    for (int dest : Adj[root])
    {
        pair <int, int> a = Dfs(dest, root);
        sum += a.first;
        if (a.second > maxi1)
        {
            maxi2 = maxi1;
            maxi1 = a.second;
        }
        else if (a.second > maxi2)
            maxi2 = a.second;
    }
    return sum + 2 * Height[root] - maxi1 - maxi2;
}

void Solve() {
    scanf("%lld", &nbNodes);
    int root = 0;
    for (int i = 0; i < nbNodes; i ++)
    {
        scanf("%lld", &Height[i]);
        if (Height[i] > Height[root])
            root = i;
    }
    for (int i = 1; i < nbNodes; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Adj[-- a].push_back(-- b);
        Adj[b].push_back(a);
    }
    printf("%lld\n", DfsRoot(root));
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}