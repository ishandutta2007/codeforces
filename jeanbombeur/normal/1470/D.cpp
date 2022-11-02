#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//    <|_|>

const int MAX_NOEUDS = (300 * 1000);

vector <int> Voisins[MAX_NOEUDS];

bool In[MAX_NOEUDS];

bool Poss[MAX_NOEUDS];

int Pris[MAX_NOEUDS];
int nbPris;

int Possib[MAX_NOEUDS];
int deb, fin;

int nbNoeuds, nbAretes;

void Dfs(int noeud) {
    In[noeud] = true;
    for (int a : Voisins[noeud])
    {
        if (!In[a])
        {
            Dfs(a);
        }
    }
    return;
}

void Read() {
    scanf("%d%d", &nbNoeuds, &nbAretes);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        Voisins[i].clear();
        In[i] = false;
        Poss[i] = false;
    }
    for (int i = 0; i < nbAretes; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Voisins[-- a].push_back(-- b);
        Voisins[b].push_back(a);
    }
    Dfs(0);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (!In[i])
        {
            printf("NO\n");
            return;
        }
        In[i] = false;
    }
    nbPris = 0;
    deb = 0;
    fin = 0;
    Possib[fin ++] = 0;
    Poss[0] = true;
    while (deb < fin)
    {
        int a = Possib[deb ++];
        if (!In[a])
        {
            In[a] = true;
            Pris[nbPris ++] = a + 1;
            for (int d : Voisins[a])
            {
                if (!In[d])
                {
                    In[d] = true;
                    for (int nd : Voisins[d])
                    {
                        if (!Poss[nd])
                        {
                            Poss[nd] = true;
                            Possib[fin ++] = nd;
                        }
                    }
                }
            }
        }
    }
    printf("YES\n%d\n", nbPris);
    for (int i = 0; i < nbPris; i ++)
    {
        printf("%d ", Pris[i]);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}