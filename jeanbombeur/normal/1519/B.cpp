#include <iostream>
#include <cstdio>
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbLignes, nbColonnes, cible;

void Read() {
    scanf("%d%d%d", &nbLignes, &nbColonnes, &cible);
    if (cible + 1 == nbLignes * nbColonnes)
        printf("YES\n");
    else
        printf("NO\n");
    return;
}

signed main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}