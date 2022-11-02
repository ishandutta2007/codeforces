#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  The hardest choices require the strongest wills
//  We must be better

const int MAX_VALEURS = (1000 * 1000);

int Val[MAX_VALEURS];

vector <int> Sommes;

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        if (Val[i] < 0)
            Val[i] = - Val[i];
    }
    Sommes.clear();
    for (int m = 0; m < (1 << nbValeurs); m ++)
    {
        int sum = 0;
        for (int i = 0; i < nbValeurs; i ++)
        {
            if (m & (1 << i))
                sum += Val[i];
        }
        Sommes.push_back(sum);
    }
    sort(Sommes.begin(), Sommes.end());
    for (int i = 1; i < (int)Sommes.size(); i ++)
    {
        if (Sommes[i] == Sommes[i - 1])
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
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