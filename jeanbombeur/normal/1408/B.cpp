#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
 
const int MAX_NOEUDS = (1000);
 
int Valeurs[MAX_NOEUDS];
 
int nbTests, nbNoeuds, nbDiff;
 
void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%d%d", &nbNoeuds, &nbDiff);
        int nb = 0;
        int last = -1;
        for (int j = 0; j < nbNoeuds; j ++)
        {
            scanf("%d", &Valeurs[j]);
            if (Valeurs[j] > last)
            {
                nb ++;
            }
            last = Valeurs[j];
        }
        int ans = 0;
        ans ++;
        nb -= nbDiff;
        if (nbDiff == 1)
        {
            if (nb > 0)
            {
                ans = -1;
            }
        }
        else
        {
            ans += max(0, (nb + nbDiff - 2) / (nbDiff - 1));
        }
        printf("%d\n", ans);
    }
    return;
}
 
int main() {
    Read();
    return 0;
}