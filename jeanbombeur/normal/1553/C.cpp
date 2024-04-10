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

char Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%s", Val);
    int mini = 10;
    for (int m = 0; m < (1 << 10); m ++)
    {
        bool t = true;
        for (int k = 0; k < 10; k ++)
        {
            if (((m & (1 << k)) && Val[k] == '0') || (!(m & (1 << k)) && Val[k] == '1'))
                t = false;
        }
        if (t)
        {
            int a[2] = {0, 0};
            for (int k = 0; k < 10; k ++)
            {
                if (m & (1 << k))
                    a[k & 1] ++;
                if (!(k & 1))
                {
                    if (a[0] > a[1] + (10 - k) / 2)
                        mini = min(mini, k + 1);
                    if (a[0] + (8 - k) / 2 < a[1])
                        mini = min(mini, k + 1);
                }
                else
                {
                    if (abs(a[0] - a[1]) > (9 - k) / 2)
                        mini = min(mini, k + 1);
                }
            }
        }
    }
    printf("%lld\n", mini);
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