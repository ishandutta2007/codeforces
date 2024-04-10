#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
const int MAX_NOEUDS = (1000 * 100);
 
int ValGroupe[MAX_NOEUDS];
int ValNoeud[MAX_NOEUDS];

vector <pair <int, int>> Voisins[2 * MAX_NOEUDS];

priority_queue <pair <int, int>> Aretes;

bool In[2 * MAX_NOEUDS];

long long sum = 0;

int nbNoeuds, nbGroupes;

void Add(int noeud) {
    In[noeud] = true;
    for (pair <int, int> dest : Voisins[noeud])
    {
        Aretes.push(dest);
    }
    return;
}

void Read() {
    scanf("%d%d", &nbGroupes, &nbNoeuds);
    for (int i = 0; i < nbGroupes; i ++)
    {
        scanf("%d", &ValGroupe[i]);
    }
    for (int i = 0; i < nbNoeuds; i ++)
    {
        scanf("%d", &ValNoeud[i]);
    }
    for (int i = 0; i < nbGroupes; i ++)
    {
        int nb;
        scanf("%d", &nb);
        for (int j = 0; j < nb; j ++)
        {
            int a;
            scanf("%d", &a);
            int prix = ValNoeud[-- a] + ValGroupe[i];
            sum += prix;
            Voisins[i + MAX_NOEUDS].push_back(make_pair(prix, a));
            Voisins[a].push_back(make_pair(prix, i + MAX_NOEUDS));
        }
    }
    return;
}

void Solve() {
    for (int i = 0; i < 2 * MAX_NOEUDS; i ++)
    {
        if (!In[i])
        {
            Add(i);
        }
        while (!Aretes.empty())
        {
            pair <int, int> x = Aretes.top();
            Aretes.pop();
            if (!In[x.second])
            {
                sum -= x.first;
                Add(x.second);
            }
        }
    }
    printf("%lld\n", sum);
    return;
}
 
int main() {
    Read();
    Solve();
    return 0;
}