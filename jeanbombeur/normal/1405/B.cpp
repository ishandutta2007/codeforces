#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

const int MAX_LONGUEUR = (100 * 1000);

int Valeurs[MAX_LONGUEUR];

int nbTests, longueur;

void Read() {
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%lld", &longueur);
        for (int j = 0; j < longueur; j ++)
        {
            scanf("%lld", &Valeurs[j]);
        }
        int marge = 0;
        int tot = 0;
        for (int j = longueur - 1; j > 0; j --)
        {
            if (Valeurs[j] <= 0)
            {
                marge -= Valeurs[j];
            }
            else
            {
                if (marge >= Valeurs[j])
                {
                    marge -= Valeurs[j];
                }
                else
                {
                    Valeurs[j] -= marge;
                    marge = 0;
                    tot += Valeurs[j];
                }
            }
        }
        printf("%lld\n", tot);
    }
    return;
}

signed main() {
    Read();
    return 0;
}