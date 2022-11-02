#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define int long long
using namespace std;

//     <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

map <int, int> Sums;

int nbValeurs, nbRequetes;

int Slicing(int gauche, int droite) {
    if (gauche == droite)
    {
        Sums[Val[gauche]] = 1;
        return Val[gauche];
    }
    int mid = (Val[gauche] + Val[droite]) / 2;
    if (Val[droite] == mid)
    {
        int sum = Val[gauche] * (droite - gauche + 1);
        Sums[sum] = 1;
        return sum;
    }
    for (int i = gauche; i <= droite; i ++)
    {
        if (Val[i] > mid)
        {
            int sum = Slicing(gauche, i - 1) + Slicing(i, droite);
            Sums[sum] = 1;
            return sum;
        }
    }
    return 0;
}

void Read() {
    scanf("%lld%lld\n", &nbValeurs, &nbRequetes);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    sort(Val, Val + nbValeurs);
    Slicing(0, nbValeurs - 1);
    for (int i = 0; i < nbRequetes; i ++)
    {
        int r;
        scanf("%lld", &r);
        if (Sums[r] > 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    Sums.clear();
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}