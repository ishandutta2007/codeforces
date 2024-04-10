#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (3e5);

struct edge {
    int a, b, val;
};

pair <int, int> Dsu[MAX_VALUES];

edge Edges[MAX_VALUES];

int nbNodes, nbElves;

pair <int, int> Find(int node, int p = 0) {
    return Dsu[node].first < 0 ? make_pair(node, p) : Find(Dsu[node].first, p ^ Dsu[node].second);
}

bool Union(int a, int b, int p) {
    pair <int, int> rA = Find(a);
    pair <int, int> rB = Find(b);
    if (rA.first == rB.first)
        return (rA.second ^ rB.second) == p;
    if (Dsu[rA.first].first > Dsu[rB.first].first)
        swap(rA, rB);
    Dsu[rA.first].first += Dsu[rB.first].first;
    Dsu[rB.first] = {rA.first, p ^ rA.second ^ rB.second};
    return true;
}

void Solve() {
    scanf("%lld %lld", &nbNodes, &nbElves);
    fill_n(Dsu, nbNodes, make_pair(-1, 0));
    for (int i = 0; i < nbNodes - 1; i ++)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        Edges[i] = {-- a, -- b, c};
    }
    bool correct = true;
    for (int i = 0; i < nbNodes - 1; i ++)
    {
        int c = Edges[i].val;
        if (c >= 0)
            correct &= Union(Edges[i].a, Edges[i].b, __builtin_popcount(c) & 1);
    }
    for (int i = 0; i < nbElves; i ++)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        correct &= Union(-- a, -- b, c);
    }
    if (!correct)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for (int i = 0; i < nbNodes - 1; i ++)
    {
        printf("%lld %lld ", Edges[i].a + 1, Edges[i].b + 1);
        if (Edges[i].val >= 0)
            printf("%lld\n", Edges[i].val);
        else if (Find(Edges[i].a).first == Find(Edges[i].b).first)
            printf("%lld\n", Find(Edges[i].a).second ^ Find(Edges[i].b).second);
        else
        {
            printf("0\n");
            Union(Edges[i].a, Edges[i].b, 0);
        }
    }
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}