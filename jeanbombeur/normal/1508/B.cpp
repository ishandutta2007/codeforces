#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000 + 1);
const int MAX_LOG = 61;

int Val[MAX_VALEURS];

int nbValeurs, num;

void Read() {
    scanf("%lld%lld", &nbValeurs, &num);
    num --;
    if (nbValeurs < MAX_LOG && (num >> (nbValeurs - 1)) > 0)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        Val[i] = 0;
    }
    for (int i = 0; i < min(nbValeurs - 1, MAX_LOG); i ++)
    {
        if ((num & (1LL << i)) > 0)
            Val[nbValeurs - i - 2] = 1;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        int next = i;
        while (Val[next] == 1)
            next ++;
        for (int j = next; j >= i; j --)
        {
            printf("%lld ", j + 1);
        }
        i = next;
    }
    printf("\n");
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