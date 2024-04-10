#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define double long double
using namespace std;

const int MAX_VOLEURS = (2000);
const int MAX_NOEUDS = (1000 * 1000 + 42);

pair <int, int> Voleurs[MAX_VOLEURS];
pair <int, int> Lampes[MAX_VOLEURS];

int AbsMin[MAX_NOEUDS];

int MvtMin[MAX_NOEUDS];

int nbVoleurs, nbLampes;

void Read() {
    scanf("%d%d", &nbVoleurs, &nbLampes);
    for (int i = 0; i < nbVoleurs; i ++)
    {
        scanf("%d%d", &Voleurs[i].first, &Voleurs[i].second);
    }
    for (int i = 0; i < nbLampes; i ++)
    {
        scanf("%d%d", &Lampes[i].first, &Lampes[i].second);
    }
    sort(Lampes, Lampes + nbLampes);
    sort(Voleurs, Voleurs + nbVoleurs);
    int maximum = 0;
    int droite = nbLampes - 1;
    for (int i = MAX_NOEUDS - 1; i >= 0; i --)
    {
        while (droite >= 0 && Lampes[droite].first >= i)
        {
            maximum = max(maximum, Lampes[droite --].second + 1);
        }
        AbsMin[i] = maximum;
    }
    return;
}

void Calcule(int noeud) {
    int absAct = Voleurs[noeud].first;
    int ordAct = Voleurs[noeud].second;
    int mvAct = 0;
    int act = 0;
    while (Lampes[act].first < absAct)
    {
        act ++;
    }
    while (act < nbLampes)
    {
        mvAct += Lampes[act].first - absAct;
        absAct = Lampes[act].first;
        int diff = max(0, AbsMin[absAct] - ordAct);
        MvtMin[mvAct] = max(MvtMin[mvAct], diff);
        act ++;
    }
    return;
}

void FindMin() {
    for (int i = 0; i < nbVoleurs; i ++)
    {
        Calcule(i);
    }
    for (int i = MAX_NOEUDS - 2; i >= 0; i --)
    {
        MvtMin[i] = max(MvtMin[i], MvtMin[i + 1]);
    }
    int minimum = (1000 * 1000 * 1000);
    for (int i = 0; i < MAX_NOEUDS; i ++)
    {
        minimum = min(minimum, i + MvtMin[i]);
    }
    printf("%d\n", minimum);
    return;
}

int main() {
    Read();
    FindMin();
    return 0;
}