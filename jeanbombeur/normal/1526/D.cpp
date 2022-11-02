#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//   <|_|>
// Check yourself before you Shrek yourself
// The hardest choices require the strongest wills

const int MAX_VALEURS = (100 * 1000);

char Mot[MAX_VALEURS];

char Key[4] = {'A', 'N', 'O', 'T'};

bool EstPris[4];
int Pris[4];

int NbTypes[4];
int NbPaires[4][4];

int nbValeurs;

int Exhaustif(int cur, int sum) {
    if (cur == 4)
        return sum;
    pair <int, int> ans = {-1, -1};
    for (int j = 0; j < 4; j ++)
    {
        if (!EstPris[j])
        {
            EstPris[j] = true;
            Pris[cur] = j;
            for (int k = 0; k < cur; k ++)
                sum += NbPaires[j][Pris[k]];
            int act = Exhaustif(cur + 1, sum);
            if (act > ans.first)
            {
                ans.first = act;
                ans.second = j;
            }
            for (int k = 0; k < cur; k ++)
                sum -= NbPaires[j][Pris[k]];
            EstPris[j] = false;
        }
    }
    EstPris[ans.second] = true;
    Pris[cur] = ans.second;
    Exhaustif(cur + 1, sum);
    EstPris[ans.second] = false;
    return ans.first;
}

void Read() {
    scanf("%s", Mot);
    nbValeurs = strlen(Mot);
    for (int i = 0; i < 4; i ++)
    {
        NbTypes[i] = 0;
        for (int j = 0; j < 4; j ++)
        {
            NbPaires[i][j] = 0;
        }
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        int cur = 3;
        if (Mot[i] == 'A')
            cur = 0;
        else if (Mot[i] == 'N')
            cur = 1;
        else if (Mot[i] == 'O')
            cur = 2;
        NbTypes[cur] ++;
        for (int j = 0; j < 4; j ++)
        {
            NbPaires[j][cur] += NbTypes[j];
        }
    }
    Exhaustif(0, 0);
    for (int j = 0; j < 4; j ++)
    {
        for (int i = 0; i < NbTypes[Pris[j]]; i ++)
        {
            printf("%c", Key[Pris[j]]);
        }
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