#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbValeurs, interdit;

void Read() {
    scanf("%d%d", &nbValeurs, &interdit);
    int sum = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        sum += Val[i];
    }
    if (sum == interdit)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    sort(Val, Val + nbValeurs);
    sum = 0;
    int last = -1;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (sum + Val[i] != interdit)
        {
            sum += Val[i];
            printf("%d ", Val[i]);
        }
        else
        {
            last = i;
        }
    }
    if (last >= 0)
    {
        printf("%d", Val[last]);
    }
    printf("\n");
    return;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}