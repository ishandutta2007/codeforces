#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  It's not me who has a problem, it's the world that seems to have a problem with me

const int MAX_VALEURS = (200 * 1000);

char Val[2][MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%s %s", Val[0], Val[1]);
    int a = strlen(Val[0]), b = strlen(Val[1]);
    for (int i = 0; i < a; i ++)
    {
        for (int j = i; j < a; j ++)
        {
            bool t = true;
            int cur = 0;
            for (int k = i; k <= j; k ++)
            {
                if (Val[0][k] != Val[1][cur ++])
                    t = false;
            }
            for (int k = j - 1; k >= 0; k --)
            {
                if (cur == b)
                    k = 0;
                else if (Val[0][k] != Val[1][cur ++])
                    t = false;
            }
            if (cur < b)
                t = false;
            if (t)
            {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}