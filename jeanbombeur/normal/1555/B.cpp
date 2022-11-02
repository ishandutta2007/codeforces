#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Petit coup de chance

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int longueur, largeur;

void Read() {
    scanf("%lld %lld", &longueur, &largeur);
    
    int x1, y1, x2, y2;
    int nouvX, nouvY;
    scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &nouvX, &nouvY);
    
    if (nouvX + x2 - x1 > longueur && nouvY + y2 - y1 > largeur)
    {
        printf("-1\n");
        return;
    }
    
    int ans = (1LL << 60);
    if (nouvX + x2 - x1 <= longueur)
        ans = min(nouvX - x1, x2 - longueur + nouvX);
    if (nouvY + y2 - y1 <= largeur)
    {
        ans = min(ans, nouvY - y1);
        ans = min(ans, y2 - largeur + nouvY);
    }
    
    printf("%lld\n", max(ans, 0LL));
    
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