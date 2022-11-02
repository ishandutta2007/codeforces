#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#define int long long
using namespace std;

const int MAX_VALEURS = (52);

int Valeurs[MAX_VALEURS];

int nbShuffles = 0;
vector <vector <int>> Shuffles;

int nbCartes;

void Melange(vector <int> melange) {
    Shuffles.push_back(melange);
    nbShuffles ++;
    vector <vector <int>> cartes;
    int cur = 0;
    for (int k : melange)
    {
        vector <int> nv;
        for (int i = 0; i < k; i ++)
        {
            nv.push_back(Valeurs[cur ++]);
        }
        cartes.push_back(nv);
    }
    cur = 0;
    reverse(cartes.begin(), cartes.end());
    for (vector <int> l : cartes)
    {
        for (int k : l)
        {
            Valeurs[cur ++] = k;
        }
    }
    return;
}

void Read() {
    scanf("%d", &nbCartes);
    for (int i = 0; i < nbCartes; i ++)
    {
        scanf("%d", &Valeurs[i]);
    }
    return;
}

void Next(int act, bool sens) {
    if (!sens)
    {
        if (act == 1 && Valeurs[nbCartes - 1] == 1)
        {
            return;
        }
        int id = 0;
        for (int i = 0; i < nbCartes; i ++)
        {
            if (Valeurs[i] == act)
            {
                id = i;
            }
        }
        vector <int> melange;
        for (int i = 0; i < act - 1; i ++)
        {
            melange.push_back(1);
        }
        melange.push_back(id - act + 2);
        if (id < nbCartes - 1)
        {
            melange.push_back(nbCartes - id - 1);
        }
        Melange(melange);
        return;
    }
    int id = 0;
    for (int i = 0; i < nbCartes; i ++)
    {
        if (Valeurs[i] == act)
        {
            id = i;
        }
    }
    vector <int> melange;
    if (id > 0)
    {
        melange.push_back(id);
    }
    melange.push_back(nbCartes - act - id + 1);
    for (int i = 0; i < act - 1; i ++)
    {
        melange.push_back(1);
    }
    Melange(melange);
    return;
}

void Solve() {
    bool t = false;
    for (int i = 1; i < nbCartes; i ++)
    {
        Next(i, t);
        t = !t;
    }
    if (Valeurs[0] != 1)
    {
        vector <int> nv;
        for (int i = 0; i < nbCartes; i ++)
        {
            nv.push_back(1);
        }
        Melange(nv);
    }
    printf("%d\n", nbShuffles);
    for (vector <int> i : Shuffles)
    {
        printf("%d ", (int)i.size());
        for (int j : i)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    return;
}

int main() {
    Read();
    Solve();
    return 0;
}