#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  It's not me who has a problem, it's the world that seems to have a problem with me

const int MAX_VALEURS = (300 * 1000);

int Val[MAX_VALEURS];

int NbFixes[MAX_VALEURS];

bool Vu[MAX_VALEURS];

vector <int> ATester;
vector <int> Ans;

int nbValeurs, nbSwaps;

void Read() {
    scanf("%lld %lld", &nbValeurs, &nbSwaps);
    fill_n(NbFixes, nbValeurs, 0);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        -- Val[i];
        NbFixes[(i + nbValeurs - Val[i]) % nbValeurs] ++;
    }
    ATester.clear();
    Ans.clear();
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (NbFixes[i] + 2 * nbSwaps >= nbValeurs)
            ATester.push_back(i);
    }
    for (int shift : ATester)
    {
        int nbMin = 0;
        fill_n(Vu, nbValeurs, false);
        for (int i = 0; i < nbValeurs; i ++)
        {
            if (!Vu[i])
            {
                Vu[i] = true;
                int next = (Val[i] + nbValeurs + shift) % nbValeurs;
                while (next != i)
                {
                    Vu[next] = true;
                    nbMin ++;
                    next = (Val[next] + nbValeurs + shift) % nbValeurs;
                }
            }
        }
        // printf("%lld %lld\n", shift, nbMin);
        if (nbMin <= nbSwaps)
            Ans.push_back(shift);
    }
    printf("%lld ", (int)Ans.size());
    for (int a : Ans)
    {
        printf("%lld ", a);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}