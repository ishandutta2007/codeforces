#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_ENTIERS = (100 * 1000 + 1);
const int MAX_BITS = 20;
const int MOD = (1000 * 1000 * 1000 + 7);

int Vecteurs[MAX_ENTIERS];

int Atteint[MAX_BITS];

int Sol[MAX_ENTIERS];

pair <int ,int> Requetes[MAX_ENTIERS];

int nbEntiers, nbRequetes;

void Init() {
    for (int i = 0; i < MAX_BITS; i ++)
    {
        Atteint[i] = -1;
    }
    return;
}

void Read() {
    scanf("%d%d", &nbEntiers, &nbRequetes);
    for (int i = 0; i < nbEntiers; i ++)
    {
        scanf("%d", &Vecteurs[i]);
    }
    for (int i = 0; i < nbRequetes; i ++)
    {
        scanf("%d%d", &Requetes[i].first, &Requetes[i].second);
    }
    return;
}

void Soustrait(int a, int b) {
    for (int i = 0; i < MAX_BITS; i ++)
    {
        Vecteurs[b] ^= (1 << i) & Vecteurs[a];
    }
    return;
}

void SubAll(int a, int bit) {
    for (int i = a + 1; i < MAX_ENTIERS; i ++)
    {
        if (i != a && (Vecteurs[i] & (1 << bit)) > 0)
        {
            Soustrait(a, i);
        }
    }
    return;
}

void Treat(int act) {
    for (int i = 0; i < MAX_BITS; i ++)
    {
        if ((Vecteurs[act] & (1 << i)) > 0)
        {
            if (Atteint[i] >= 0)
            {
                Soustrait(Atteint[i], act);
            }
            else
            {
                Atteint[i] = act;
                SubAll(act, i);
                return;
            }
        }
    }
    return;
}

void FillSol() {
    int nb = 1;
    for (int i = 0; i < MAX_ENTIERS; i ++)
    {
        Sol[i] = nb;
        if (Vecteurs[i] == 0)
        {
            nb = (2 * nb) % MOD;
        }
    }
    return;
}

int Count(int target, int borne) {
    for (int i = 0; i < MAX_BITS; i ++)
    {
        if ((target & (1 << i)) > 0)
        {
            if (Atteint[i] < 0 || Atteint[i] >= borne)
            {
                return 0;
            }
            else
            {
                target ^= Vecteurs[Atteint[i]];
            }
        }
    }
    if (target != 0)
    {
        return 0;
    }
    return Sol[borne];
}

void Solve() {
    for (int i = 0; i < MAX_ENTIERS; i ++)
    {
        Treat(i);
    }
    FillSol();
    for (int i = 0; i < nbRequetes; i ++)
    {
        printf("%d\n", Count(Requetes[i].second, Requetes[i].first));
    }
    return;
}

void Print() {
    printf("\n");
    for (int i = 0; i < 10; i ++)
    {
        printf("%d\n", Sol[i]);
    }
    return;
}

int main() {
    Init();
    Read();
    Solve();
    //Print();
    return 0;
}