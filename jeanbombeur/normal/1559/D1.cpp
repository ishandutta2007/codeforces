#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm Batman

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
        return  - Dsu[find(a)];
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

const int MAX_VALEURS = (200 * 1000);

union_find Foret[2];

vector <int> Libres[2];

int nbNoeuds;
int nbAretes[2];

void Solve() {
    scanf("%lld %lld %lld", &nbNoeuds, &nbAretes[0], &nbAretes[1]);
    for (int i = 0; i < 2; i ++)
    {
        Foret[i].set_to_size(nbNoeuds);
        for (int j = 0; j < nbAretes[i]; j ++)
        {
            int a, b;
            scanf("%lld %lld", &a, &b);
            Foret[i].merge(-- a, -- b);
        }
    }
    printf("%lld\n", nbNoeuds - 1 - max(nbAretes[0], nbAretes[1]));
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (!Foret[0].linked(0, i) && !Foret[1].linked(0, i))
        {
            printf("%lld %lld\n", 1LL, i + 1);
            Foret[0].merge(0, i);
            Foret[1].merge(0, i);
        }
    }
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (Foret[0].linked(0, i) && !Foret[1].linked(0, i))
        {
            Libres[0].push_back(i);
            Foret[1].merge(0, i);
        }
        if (!Foret[0].linked(0, i) && Foret[1].linked(0, i))
        {
            Libres[1].push_back(i);
            Foret[0].merge(0, i);
        }
    }
    int d = min(Libres[0].size(), Libres[1].size());
    for (int i = 0; i < d; i ++)
    {
        printf("%lld %lld\n", Libres[0][i] + 1, Libres[1][i] + 1);
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