#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  With great power comes great responsability

//  This is my gift, my curse

//  When the student is ready, the teacher will appear. When the student is truly ready, the teacher will disappear.

//  There are no accidents

//  The hardest choices require the strongest wills

//  You're not the only one cursed with knowledge

//  What is better - to be born good, or to overcome your evil nature with great effort ?

//  We must be better

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

bool Vu[MAX_VALEURS];

vector <int> Libres;

int nbPersonnes;

void Read() {
    scanf("%lld", &nbPersonnes);
    
    fill_n(Vu, nbPersonnes, false);
    
    for (int i = 0; i < nbPersonnes; i ++)
    {
        scanf("%lld", &Val[i]);
        Vu[-- Val[i]] = true;
    }
    
    Libres.clear();
    for (int i = 0; i < nbPersonnes; i ++)
    {
        if (!Vu[i])
            Libres.push_back(i);
        Vu[i] = false;
    }
    printf("%lld\n", nbPersonnes - Libres.size());
    
    int last = -1;
    
    if (Libres.size())
    {
        last = Libres.back();
        Vu[Val[last]] = true;
    }
    int cur = 0;
    
    for (int i = 0; i < nbPersonnes; i ++)
    {
        if (!Vu[Val[i]] || i == last)
        {
            Vu[Val[i]] = true;
            printf("%lld ", ++ Val[i]);
        }
        else
        {
            if (Libres[cur] == i)
                swap(Libres[cur], Libres[cur + 1]);
            printf("%lld ", Libres[cur ++] + 1);
        }
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}