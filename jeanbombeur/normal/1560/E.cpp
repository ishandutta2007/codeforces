#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  A wizard is never late nor early. He arrives precisely when he means to

const int MAX_LETTRES = (5e5 + 1);
const int NB_LETTRES = (26);

char Mot[MAX_LETTRES];

pair <int, int> Last[NB_LETTRES];
int Occ[MAX_LETTRES];

void Solve() {
    scanf("%s", Mot);
    int sz = strlen(Mot);
    for (int i = 0; i < NB_LETTRES; i ++)
    {
        Last[i] = {-1, i};
        Occ[i] = 0;
    }
    for (int i = 0; i < sz; i ++)
    {
        Last[Mot[i] - 'a'].first = i;
        Occ[Mot[i] - 'a'] ++;
    }
    for (int i = 0; i < NB_LETTRES; i ++)
    {
        if (Occ[i] == 0)
            Last[i].first = 1 << 30;
    }
    sort(Last, Last + NB_LETTRES);
    for (int i = 0; i < NB_LETTRES; i ++)
    {
        int cur = Last[i].second;
        if (Occ[cur] > 0 && (Occ[cur] % (i + 1)) > 0)
        {
            printf("-1\n");
            return;
        }
        Occ[cur] /= (i + 1);
    }
    int szOrigin = sz;
    for (int i = 0; i < sz; i ++)
    {
        if (-- Occ[Mot[i] - 'a'] < 0)
            szOrigin = i, i = sz;
    }
    fill_n(Occ, NB_LETTRES, 0LL);
    int cur = szOrigin;
    for (int i = 0; i < NB_LETTRES; i ++)
    {
        int last = Last[i].second;
        if (Last[i].first == 1 << 30)
            i = NB_LETTRES;
        else
        {
            Occ[last] = -1;
            int deb = 0;
            while (deb < szOrigin)
            {
                while (deb < szOrigin && Occ[Mot[deb] - 'a'] < 0)
                    deb ++;
                if (deb < szOrigin && (cur >= sz || Mot[deb] != Mot[cur]))
                {
                    printf("-1\n");
                    return;
                }
                if (deb < szOrigin)
                    deb ++, cur ++;
            }
        }
    }
    for (int i = 0; i < szOrigin; i ++)
    {
        printf("%c", Mot[i]);
    }
    printf(" ");
    for (int i = 0; i < NB_LETTRES; i ++)
    {
        if (Last[i].first < (1 << 30))
            printf("%c", (char)Last[i].second + 'a');
    }
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