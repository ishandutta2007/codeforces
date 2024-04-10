#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX_NOEUDS = (500 * 1000);

int Valeurs[MAX_NOEUDS];

pair <int, int> Bornes[MAX_NOEUDS];

vector <pair <int, int>> Ajouts[MAX_NOEUDS];

bool Pris[MAX_NOEUDS];

priority_queue <pair <int, int>> Aretes;

int nbTests, nbValeurs;

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%d", &nbValeurs);
        int nbZeros = 0;
        for (int j = 0; j < nbValeurs; j ++)
        {
            scanf("%d", &Valeurs[j]);
            if (Valeurs[j] == 0)
            {
                nbZeros ++;
            }
        }
        for (int i = 0; i < nbValeurs; i ++)
        {
            Bornes[i].first = -1;
            Bornes[i].second = -1;
            Pris[i] = false;
        }
        int nbAct = 0;
        for (int j = 0; j < nbValeurs; j ++)
        {
            if (Valeurs[j] == 0)
            {
                nbAct ++;
            }
            else if (nbAct <= nbZeros / 2)
            {
                Bornes[Valeurs[j] - 1].first = nbAct;
            }
        }
        nbAct = 0;
        for (int j = nbValeurs - 1; j >= 0; j --)
        {
            if (Valeurs[j] == 0)
            {
                nbAct ++;
            }
            else if (nbAct <= nbZeros / 2)
            {
                Bornes[Valeurs[j] - 1].second = nbAct;
            }
        }
        for (int i = 0; i < nbValeurs; i ++)
        {
            if (Bornes[i].first >= 0)
            {
                Ajouts[Bornes[i].first].push_back(make_pair(- Bornes[i].second, i));
            }
        }
        int nbPaires = 0;
        for (int x = nbZeros / 2; x > 0; x --)
        {
            for (pair <int, int> arete : Ajouts[x])
            {
                Aretes.push(arete);
            }
            if (!Aretes.empty())
            {
                Pris[Aretes.top().second] = true;
                nbPaires ++;
                Aretes.pop();
            }
        }
        while (!Aretes.empty())
        {
            Aretes.pop();
        }
        for (int i = 0; i < nbValeurs; i ++)
        {
            Aretes.push(make_pair(Bornes[i].second, i));
        }
        for (int x = nbZeros / 2; x > 0; x --)
        {
            while (Pris[Aretes.top().second])
            {
                Aretes.pop();
            }
            if (Aretes.top().first >= x)
            {
                nbPaires ++;
                Aretes.pop();
            }
        }
        while (!Aretes.empty())
        {
            Aretes.pop();
        }
        for (int i = 0; i < nbValeurs; i ++)
        {
            Ajouts[i].clear();
        }
        printf("%d\n", min(nbZeros / 2, nbPaires));
    }
    return;
}

int main() {
    Read();
    return 0;
}