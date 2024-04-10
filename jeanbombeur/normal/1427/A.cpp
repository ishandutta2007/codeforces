#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#define int long long
using namespace std;

const int MAX_VALEURS = (100 * 1000);

int Valeurs[MAX_VALEURS];

int nbTests, nbValeurs;

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%d", &nbValeurs);
        int sum = 0;
        for (int i = 0; i < nbValeurs; i ++)
        {
            scanf("%d", &Valeurs[i]);
            sum += Valeurs[i];
        }
        if (sum == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            sort(Valeurs, Valeurs + nbValeurs);
            if (sum > 0)
            {
                for (int i = nbValeurs - 1; i >= 0; i --)
                {
                    printf("%d ", Valeurs[i]);
                }
            }
            else
            {
                for (int i = 0; i < nbValeurs; i ++)
                {
                    printf("%d ", Valeurs[i]);
                }
            }
            printf("\n");
        }
    }
    return;
}

int main() {
    Read();
    return 0;
}