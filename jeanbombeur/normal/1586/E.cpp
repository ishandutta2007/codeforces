#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
// #define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (3e5);

struct union_find {
    vector <int> Dsu;
    int size = 0;
    
    bool using_rb = false;
    vector <pair <int, int>> MergesDone;
    pair <int, int> null_merge = {-1, -1};
    
    // call this if you want to enable rollbacks (to do at the start !)
    void use_rollbacks() {
        using_rb = true;
        return;
    }
    
    // remember to call this at the start !
    void set_to_size(int n) {
        Dsu.resize(n, -1);
        size = n;
        return;
    }
    
    // destroys everything : ready to be used again !
    void clear() {
        Dsu.clear();
        MergesDone.clear();
        size = 0;
        return;
    }
    
    // finds the root of node a and compresses on the way
    int find(int a) {
        return Dsu[a] < 0 ? a : Dsu[a] = find(Dsu[a]);
    }
    
    // finds the root of node a without compressing
    int find_rb(int a) {
        return Dsu[a] < 0 ? a : find_rb(Dsu[a]);
    }
    
    // merges the components of nodes a and b (small into large)
    bool merge(int a, int b) {
        if (using_rb)
            a = find_rb(a), b = find_rb(b);
        else
            a = find(a), b = find(b);
        if (a == b)
        {
            if (using_rb)
                MergesDone.push_back(null_merge);
            return false;
        }
        if (Dsu[a] > Dsu[b])
            swap(a, b);
        if (using_rb)
            MergesDone.push_back({b, Dsu[b]});
        Dsu[a] += Dsu[b];
        Dsu[b] = a;
        return true;
    }
    
    // returns true iff nodes a and b are in the same component
    bool linked(int a, int b) {
        if (using_rb)
            return find_rb(a) == find_rb(b);
        return find(a) == find(b);
    }
    
    // returns the size of the component of node a
    int get_size_of(int a) {
        if (using_rb)
            return - Dsu[find_rb(a)];
        return - Dsu[find(a)];
    }
    
    // rollbacks the last nb merge operations (even if they merged nothing !)
    void rollback(int nb = 1) {
        nb = min(nb, (int)MergesDone.size());
        for (int i = 0; i < nb; i ++)
        {
            pair <int, int> a = MergesDone.back();
            MergesDone.pop_back();
            if (a != null_merge)
                Dsu[Dsu[a.first]] -= a.second, Dsu[a.first] = a.second;
        }
        return;
    }
};

vector <int> Adj[MAX_VALUES];

vector <int> Path;

int Val[MAX_VALUES];

pair <int, int> Asks[MAX_VALUES];

int nbNodes, nbEdges, nbQueries;

union_find dsu;

int FindPath(int node, int parent, int target) {
    if (node == target)
        return 1;
    int dist = 0;
    for (int dest : Adj[node])
    {
        if (dest ^ parent)
        {
            int a = FindPath(dest, node, target);
            if (a > 0)
                dist = a + 1;
        }
    }
    if (dist > 0)
        Path.push_back(node);
    return dist;
}

void Solve() {
    scanf("%d %d", &nbNodes, &nbEdges);
    dsu.set_to_size(nbNodes);
    for (int i = 0; i < nbEdges; i ++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (dsu.merge(-- a, -- b))
        {
            Adj[a].push_back(b);
            Adj[b].push_back(a);
        }
    }
    scanf("%d", &nbQueries);
    for (int i = 0; i < nbQueries; i ++)
    {
        scanf("%d %d", &Asks[i].first, &Asks[i].second);
        Val[-- Asks[i].first] ++;
        Val[-- Asks[i].second] ++;
    }
    int sum = 0;
    for (int i = 0; i < nbNodes; i ++)
    {
        sum += Val[i] & 1;
    }
    if (sum > 0)
    {
        printf("NO\n%d\n", sum >> 1);
        return;
    }
    printf("YES\n");
    for (int i = 0; i < nbQueries; i ++)
    {
        Path.clear();
        Path.push_back(Asks[i].second);
        FindPath(Asks[i].first, -1, Asks[i].second);
        reverse(Path.begin(), Path.end());
        printf("%d\n", (int)Path.size());
        for (int a : Path)
            printf("%d ", a + 1);
        printf("\n");
    }
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