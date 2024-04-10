#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//   The hardest choices require the strongest wills

const int MAX_VALEURS = (400 * 1000 + 2);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 1; i <= nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    Val[0] = Val[nbValeurs + 1] = 0;
    int ans = 0;
    for (int i = 1; i <= nbValeurs; i ++)
    {
        int d = max(Val[i - 1], Val[i + 1]);
        if (Val[i] > d)
        {
            ans += Val[i] - d;
            Val[i] = d;
        }
        ans += abs(Val[i] - Val[i - 1]);
    }
    ans += Val[nbValeurs];
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}