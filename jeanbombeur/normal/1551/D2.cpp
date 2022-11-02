#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Ah shit, here we go again

const int MAX_VALEURS = (200 * 1000);
const int MAX_LIGNES = (100);

char Ans[MAX_LIGNES][MAX_LIGNES];

int nbLignes, nbColonnes, nbHorizontaux;

void Solve() {
    scanf("%lld %lld %lld", &nbLignes, &nbColonnes, &nbHorizontaux);
    bool t = false;
    if (nbLignes & 1)
    {
        t = true;
        swap(nbLignes, nbColonnes);
        nbHorizontaux = ((nbLignes * nbColonnes) >> 1) - nbHorizontaux;
    }
    if ((nbHorizontaux & 1) || (nbHorizontaux > nbLignes * (nbColonnes >> 1)))
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for (int i = 0; i < nbLignes; i += 2)
    {
        int cur = 'a' + (i % 26);
        for (int j = 0; j < nbColonnes; j ++)
        {
            if (j + 1 < nbColonnes && nbHorizontaux > 0)
            {
                nbHorizontaux -= 2;
                Ans[i][j] = Ans[i][j + 1] = cur ++;
                Ans[i + 1][j] = Ans[i + 1][j + 1] = cur ++;
                j ++;
            }
            else
                Ans[i][j] = Ans[i + 1][j] = cur ++;
            if (cur > 'z')
                cur = 'a';
        }
    }
    if (t)
    {
        for (int i = 0; i < nbColonnes; i ++)
        {
            for (int j = 0; j < nbLignes; j ++)
            {
                printf("%c", Ans[j][i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            printf("%c", Ans[i][j]);
        }
        printf("\n");
    }
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}