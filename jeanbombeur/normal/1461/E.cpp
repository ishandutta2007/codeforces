#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define bgint __int128
#define int long long
using namespace std;

//     <|_|>

const int MAX_VALEURS = (1000 * 1000);

int Residus[MAX_VALEURS];

int dep, inf, sup, nbJours, perte, ajout;

void Read() {
    scanf("%lld%lld%lld%lld%lld%lld", &dep, &inf, &sup, &nbJours, &perte, &ajout);
    if (perte > ajout)
    {
        bgint cur = dep - ajout;
        if (dep + ajout <= sup)
        {
            cur = dep;
        }
        bgint delta = perte - ajout;
        if ((bgint)nbJours * delta + inf > cur)
        {
            printf("No\n");
            return;
        }
        printf("Yes\n");
        return;
    }
    bgint nbJoursPasses = 0;
    bgint cur = dep;
    while (nbJoursPasses < nbJours)
    {
        bgint delta = (cur - inf) / perte;
        cur -= delta * perte;
        nbJoursPasses += delta;
        if (Residus[cur - inf] ++ > 0)
        {
            printf("Yes\n");
            return;
        }
        if (cur + ajout > sup && nbJoursPasses < nbJours)
        {
            printf("No\n");
            return;
        }
        cur += ajout;
    }
    printf("Yes\n");
    return;
}

signed main() {
    Read();
    return 0;
}