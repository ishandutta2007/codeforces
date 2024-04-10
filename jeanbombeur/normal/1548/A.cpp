#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Why do we fall, sir ?

const int MAX_VALEURS = (1000 * 1000);

int NbSup[MAX_VALEURS];

int ans = 0;

int nbNoeuds, nbAretes, nbRequetes;

void Read() {
    scanf("%lld %lld", &nbNoeuds, &nbAretes);
    ans = nbNoeuds;
    for (int i = 0; i < nbAretes; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        a --, b --;
        ans -= NbSup[min(a, b)] ++ == 0;
    }
    scanf("%lld", &nbRequetes);
    
    for (int i = 0; i < nbRequetes; i ++)
    {
        int a;
        scanf("%lld", &a);
        if (a == 3)
            printf("%lld\n", ans);
        else
        {
            int b, c;
            scanf("%lld %lld", &b, &c);
            b --, c --;
            if (a == 1)
                ans -= NbSup[min(b, c)] ++ == 0;
            else
                ans += -- NbSup[min(b, c)] == 0;
        }
    }
    
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Read();
    return 0;
}