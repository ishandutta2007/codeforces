#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Spared no expense

const int MAX_CHARGES = (6e5 + 1);

char Charges[MAX_CHARGES];

int Stack[MAX_CHARGES];
int fin = 0;

int Sz[MAX_CHARGES];

int nbCharges, nbQueries;

void Solve() {
    scanf("%lld %lld %s", &nbCharges, &nbQueries, Charges);
    fin = 0;
    for (int i = 0; i < nbCharges; i ++)
    {
        Stack[fin ++] = i & 1;
    }
    int debFin = fin;
    for (int i = 0; i < nbCharges; i ++)
    {
        int cur = Charges[i] == '+';
        if (Stack[fin - 1] == cur)
            fin --;
        else
            Stack[fin ++] = cur;
        Sz[i] = fin;
    }
    for (int i = 0; i < nbQueries; i ++)
    {
        int left, right;
        scanf("%lld %lld", &left, &right);
        left --, right --;
        left --;
        int diff = Sz[right] - (left >= 0 ? Sz[left] : debFin);
        if ((right - left) & 1)
            printf("1\n");
        else if (diff == 0)
            printf("0\n");
        else
            printf("2\n");
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