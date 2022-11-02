#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

const int MAX_NOEUDS = (100);

int Valeurs[MAX_NOEUDS][MAX_NOEUDS];

int nbTests, nbLignes, nbColonnes;

void Read() {
    scanf("%lld", &nbTests);
    for (int t = 0; t < nbTests; t ++)
    {
        int sum = 0;
        scanf("%lld%lld", &nbLignes, &nbColonnes);
        for (int j = 0; j < nbLignes; j ++)
        {
            for (int k = 0; k < nbColonnes; k ++)
            {
                scanf("%lld", &Valeurs[j][k]);
            }
        }
        for (int i = 0; i < nbLignes / 2; i ++)
        {
            for (int j = 0; j < nbColonnes / 2; j ++)
            {
                int a = Valeurs[i][j];
                int b = Valeurs[nbLignes - i - 1][j];
                int c = Valeurs[i][nbColonnes - j - 1];
                int d = Valeurs[nbLignes - i - 1][nbColonnes - j - 1];
                int mid = max(min(a, b), min(c, d));
                //printf("%d\n", mid);
                sum += max(mid - a, a - mid);
                sum += max(mid - b, b - mid);
                sum += max(mid - c, c - mid);
                sum += max(mid - d, d - mid);
            }
        }
        if (nbLignes % 2 == 1)
        {
            int lig = nbLignes / 2;
            for (int j = 0; j < nbColonnes / 2; j ++)
            {
                int a = Valeurs[lig][j];
                int b = Valeurs[lig][nbColonnes - j - 1];
                sum += max(a - b, b - a);
            }
        }
        if (nbColonnes % 2 == 1)
        {
            int col = nbColonnes / 2;
            for (int j = 0; j < nbLignes / 2; j ++)
            {
                int a = Valeurs[j][col];
                int b = Valeurs[nbLignes - j - 1][col];
                sum += max(b - a, a - b);
            }
        }
        printf("%lld\n", sum);
    }
    return;
}

signed main() {
    Read();
    return 0;
}