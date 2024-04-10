#include <iostream>
#include <cstdio>
using namespace std;

// <|_|>

const int MAX_VALEURS = (1000 * 1000);

char Val[MAX_VALEURS];

int nbValeurs, nbRequetes, nbTests;

void Read() {
    scanf("%d%d\n", &nbValeurs, &nbRequetes);
    scanf("%s", Val);
    int a = nbValeurs, b = nbValeurs, c = -1, d = -1;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (Val[i] == '0')
        {
            a = min(a, i);
            c = max(c, i);
        }
        else
        {
            b = min(b, i);
            d = max(d, i);
        }
    }
    for (int i = 0; i < nbRequetes; i ++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x --;
        y --;
        if ((x == a || x == b) && (y == c || y == d))
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return;
}

int main() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}