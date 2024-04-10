#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm Batman

const int MAX_VALEURS = (200 * 1000);

char Val[MAX_VALEURS];

int nbValeurs;

void Solve() {
    scanf("%lld %s", &nbValeurs, Val);
    for (int i = 1; i < nbValeurs; i ++)
    {
        if (Val[i] == '?' && Val[i - 1] != '?')
            Val[i] = (Val[i - 1] == 'B' ? 'R' : 'B');
    }
    if (Val[nbValeurs - 1] == '?')
        Val[nbValeurs - 1] = 'B';
    for (int i = nbValeurs - 2; i >= 0; i --)
    {
        if (Val[i] == '?')
            Val[i] = (Val[i + 1] == 'B' ? 'R' : 'B');
    }
    printf("%s\n", Val);
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