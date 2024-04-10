#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  It that's what it takes to save the world, it's better to let that world die

const int MAX_CASES = (1e5);

int Perm[MAX_CASES];

int Op[MAX_CASES];
int curOp = 0;

int nbCases;

void Swap(int a) {
    Op[curOp ++] = ++ a;
    for (int i = 0; i < a / 2; i ++)
    {
        swap(Perm[i], Perm[a - 1 - i]);
    }
    return;
}

void Solve() {
    scanf("%lld", &nbCases);
    curOp = 0;
    for (int i = 0; i < nbCases; i ++)
    {
        scanf("%lld", &Perm[i]);
        Perm[i] --;
    }
    for (int i = 0; i < nbCases; i += 2)
    {
        if (Perm[i] & 1)
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = nbCases - 2; i >= 1; i -= 2)
    {
        int a = 0, b = 0;
        for (int j = 0; j < nbCases; j ++)
        {
            if (Perm[j] == i)
                a = j;
            if (Perm[j] == i + 1)
                b = j;
        }
        if (a < b)
        {
            Swap(b);
            a = b - a, b = 0;
            Swap(a - 1);
            Swap(a + 1);
            Swap(2);
            Swap(i + 1);
        }
        else
        {
            Swap(b);
            Swap(a - 1);
            Swap(a + 1);
            Swap(2);
            Swap(i + 1);
        }
    }
    printf("%lld\n", curOp);
    for (int i = 0; i < curOp; i ++)
    {
        printf("%lld ", Op[i]);
    }
    if (curOp)
        printf("\n");
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