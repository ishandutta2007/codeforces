#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
 
//    <|_|>
 
const int MAX_CHAINES = (1000 * 1000 + 1);

int Chaines[MAX_CHAINES];

int Occ[MAX_CHAINES];

int nbChaines, nbNoeuds;

int LSB(int a) {
    return a & (-a);
}

int Sum(int a) {
    if (a <= 0)
    {
        return 0;
    }
    return Occ[a] + Sum(a - LSB(a));
}

void Add(int a, int k) {
    if (a >= MAX_CHAINES)
    {
        return;
    }
    Occ[a] += k;
    Add(a + LSB(a), k);
    return;
}

void Read() {
    scanf("%lld%lld", &nbChaines, &nbNoeuds);
    for (int i = 0; i < nbChaines; i ++)
    {
        scanf("%lld", &Chaines[i]);
    }
    sort(Chaines, Chaines + nbChaines);
    int nb = 1;
    int curMin = 1;
    Add(1, 1);
    Add(2, -1);
    int firstMinimum = -1;
    for (int i = nbChaines - 1; i >= 0; i --)
    {
        nb += Chaines[i] - 2;
        while (Sum(curMin) == 0)
        {
            curMin ++;
        }
        if (firstMinimum >= 0 && curMin + 2 > firstMinimum)
        {
            int ct = 0;
            int cur = curMin - 1;
            while (ct < nbNoeuds)
            {
                ct += Sum(++ cur);
            }
            printf("%lld\n", cur - 1);
            return;
        }
        Add(curMin, -1);
        Add(curMin + 1, 1);
        Add(curMin + 2, 2);
        Add(curMin + 2 + Chaines[i] / 2, -1);
        Add(curMin + 2 + (Chaines[i] - 1) / 2, -1);
        if (nb >= nbNoeuds && firstMinimum < 0)
        {
            int ct = 0;
            int cur = curMin - 1;
            while (ct < nbNoeuds)
            {
                ct += Sum(++ cur);
            }
            firstMinimum = cur;
        }
    }
    if (firstMinimum >= 0)
    {
        int ct = 0;
        int cur = curMin - 1;
        while (ct < nbNoeuds)
        {
            ct += Sum(++ cur);
        }
        printf("%lld\n", cur - 1);
        return;
    }
    printf("-1\n");
    return;
}

signed main() {
    Read();
    return 0;
}