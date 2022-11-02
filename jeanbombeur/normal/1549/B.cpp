#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
//  <|_|>
 
//  Why do we fall, sir ?

const int MAX_VALEURS = (200 * 1000 + 1);

char Pions[2][MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld %s %s", &nbValeurs, Pions[0], Pions[1]);
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (Pions[1][i] == '1' && i && Pions[0][i - 1] == '1')
            ans ++;
        else if (Pions[1][i] == '1' && Pions[0][i] == '0')
        {
            ans ++;
            Pions[0][i] = '0';
        }
        else if (Pions[1][i] == '1' && Pions[0][i + 1] == '1')
        {
            ans ++;
            Pions[0][i + 1] = '2';
        }
    }
    printf("%lld\n", ans);
    return;
}
 
signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Read();
    return 0;
}