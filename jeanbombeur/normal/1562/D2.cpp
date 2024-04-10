#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

//  <|_|>

//  Spared no expense

const int MAX_CHARGES = (6e5 + 1);

char Charges[MAX_CHARGES];

int Stack[MAX_CHARGES];
int fin = 0;

int Sz[MAX_CHARGES];

set <int> Sizes[MAX_CHARGES];

int nbCharges, nbQueries;

void Solve() {
    scanf("%lld %lld %s", &nbCharges, &nbQueries, Charges);
    fin = 0;
    for (int i = 0; i < nbCharges; i ++)
    {
        Stack[fin ++] = i & 1;
        Sizes[i].clear();
        Sizes[i + nbCharges].clear();
    }
    int debFin = fin;
    Sizes[debFin].insert(0);
    for (int i = 0; i < nbCharges; i ++)
    {
        int cur = Charges[i] == '+';
        if (Stack[fin - 1] == cur)
            fin --;
        else
            Stack[fin ++] = cur;
        Sz[i] = fin;
        Sizes[fin].insert(i + 1);
    }
    /*for (int i = 0; i < 2 * nbCharges; i ++)
    {
        for (int a : Sizes[i])
            printf("%lld ", a);
        printf("\n");
    }*/
    for (int i = 0; i < nbQueries; i ++)
    {
        int left, right;
        scanf("%lld %lld", &left, &right);
        left --, right --;
        left --;
        int szLeft = (left >= 0 ? Sz[left] : debFin);
        int diff = Sz[right] - szLeft;
        if (diff == 0)
            printf("0\n");
        else
        {
            if ((right - left) & 1)
                printf("1\n");
            else
                printf("2\n%lld ", 1 + (right --));
            int mid = (Sz[right] + szLeft) / 2;
            if (Sz[right] > szLeft)
                printf("%lld\n", *(-- Sizes[mid].upper_bound(right + 1)) + 1);
            else
                printf("%lld\n", *(-- Sizes[mid + 1].upper_bound(right + 1)) + 1);
        }
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