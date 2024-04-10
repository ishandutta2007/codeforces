#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Ah shit, here we go again

const int MAX_VALEURS = (200 * 1000);

int nbLignes, nbColonnes, nbHorizontaux;

void Solve() {
    scanf("%lld %lld %lld", &nbLignes, &nbColonnes, &nbHorizontaux);
    if (nbLignes & 1)
    {
        swap(nbLignes, nbColonnes);
        nbHorizontaux = ((nbLignes * nbColonnes) >> 1) - nbHorizontaux;
    }
    if ((nbHorizontaux & 1) || (nbHorizontaux > nbLignes * (nbColonnes >> 1)))
        printf("NO\n");
    else
        printf("YES\n");
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