#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
 
const int INFINI = (2000 * 1000 * 1000 + 1);
const int MAX_NOEUDS = (100 * 1000 + 2);
 
vector <int> Voisins[MAX_NOEUDS];
 
pair <int, int> Coord[MAX_NOEUDS];
 
pair <int, int> Tri[MAX_NOEUDS];
 
int Dist[MAX_NOEUDS];
 
bool Vu[MAX_NOEUDS];
 
priority_queue <pair <int, int>> Djikstra;
 
int taille, nbNoeuds;
 
void Init() {
    for (int i = 0; i < MAX_NOEUDS; i ++)
    {
        Dist[i] = INFINI;
    }
    return;
}
 
void Read() {
    scanf("%lld%lld", &taille, &nbNoeuds);
    scanf("%lld%lld", &Coord[nbNoeuds].first, &Coord[nbNoeuds].second);
    scanf("%lld%lld", &Coord[nbNoeuds + 1].first, &Coord[nbNoeuds + 1].second);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        scanf("%lld%lld", &Coord[i].first, &Coord[i].second);
        Tri[i].first = Coord[i].first;
        Tri[i].second = i;
        Voisins[i].push_back(nbNoeuds + 1);
        Voisins[nbNoeuds].push_back(i);
    }
    Voisins[nbNoeuds].push_back(nbNoeuds + 1);
    sort(Tri, Tri + nbNoeuds);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (i > 0)
        {
            Voisins[Tri[i].second].push_back(Tri[i - 1].second);
        }
        if (i + 1 < nbNoeuds)
        {
            Voisins[Tri[i].second].push_back(Tri[i + 1].second);
        }
    }
    for (int i = 0; i < nbNoeuds; i ++)
    {
        Tri[i].first = Coord[i].second;
        Tri[i].second = i;
    }
    sort(Tri, Tri + nbNoeuds);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (i > 0)
        {
            Voisins[Tri[i].second].push_back(Tri[i - 1].second);
        }
        if (i + 1 < nbNoeuds)
        {
            Voisins[Tri[i].second].push_back(Tri[i + 1].second);
        }
    }
    return;
}
 
int Distance(int a, int b) {
    int dh = max(Coord[a].first - Coord[b].first, Coord[b].first - Coord[a].first);
    int dv = max(Coord[a].second - Coord[b].second, Coord[b].second - Coord[a].second);
    if (b != nbNoeuds + 1)
    {
        return min(dv, dh);
    }
    return dv + dh;
}
 
void Treat(int noeud) {
    if (Vu[noeud])
    {
        return;
    }
    Vu[noeud] = true;
    int act = Dist[noeud];
    for (int dest : Voisins[noeud])
    {
        int nvDist = act + Distance(noeud, dest);
        if (Dist[dest] > nvDist)
        {
            Dist[dest] = nvDist;
            Djikstra.push(make_pair(- nvDist, dest));
        }
    }
    return;
}
 
void Solve() {
    Djikstra.push(make_pair(0, nbNoeuds));
    Dist[nbNoeuds] = 0;
    while (!Djikstra.empty())
    {
        pair <int, int> x = Djikstra.top();
        Djikstra.pop();
        Treat(x.second);
    }
    for (int i = 0; i < nbNoeuds; i ++)
    {
        //printf("%lld\n", Dist[i]);
    }
    printf("%lld\n", Dist[nbNoeuds + 1]);
    return;
}
 
void Print() {
    for (int i = 0; i < nbNoeuds; i ++)
    {
        for (int dest : Voisins[i])
        {
            printf("%lld ", Distance(i, dest));
        }
        printf("\n");
    }
    return;
}
 
signed main() {
    Init();
    Read();
    Solve();
    //Print();
    return 0;
}