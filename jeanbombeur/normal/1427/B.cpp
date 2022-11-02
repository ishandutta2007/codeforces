#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#define int long long
using namespace std;

const int MAX_VALEURS = (100 * 1000);

char Valeurs[MAX_VALEURS];

int Trous[MAX_VALEURS];

int nbTests, nbValeurs, nbChange;

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%d%d\n", &nbValeurs, &nbChange);
        int nbTrous = 0;
        int last = 0;
        int nbDef = 0;
        int tot = 0;
        int first = -1;
        for (int i = 0; i < nbValeurs; i ++)
        {
            scanf("%c ", &Valeurs[i]);
            if (Valeurs[i] == 'L')
            {
                last ++;
                nbDef ++;
            }
            else
            {
                if (first < 0)
                {
                    first = i;
                    last = 0;
                    tot --;
                }
                if (last > 0)
                {
                    Trous[nbTrous ++] = last;
                    last = 0;
                    tot ++;
                }
                else
                {
                    tot += 2;
                }
            }
        }
        sort(Trous, Trous + nbTrous);
        int act = 0;
        while (act < nbTrous)
        {
            if (nbChange >= Trous[act])
            {
                tot += 2 * Trous[act] + 1;
                nbDef -= Trous[act];
                nbChange -= Trous[act ++];
            }
            else
            {
                act = nbTrous;
            }
        }
        if (first < 0)
        {
            tot += max(2 * nbChange - 1, 0);
        }
        else
        {
            tot += 2 * min(nbDef, nbChange);
        }
        printf("%d\n", tot);
    }
    return;
}

int main() {
    Read();
    return 0;
}