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
    int cur = b - 1;
    for (int i = a - 1; i >= 0; i --)
    {
        if (cur >= 0 && Val[0][i] == Val[1][cur])
            cur --;
        else
            i --;
    }
    if (cur == -1)
        printf("YES\n");
    else
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