#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (400 * 1000);

char Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%s", Val);
    nbValeurs = 0;
    int ans = 0;
    while (Val[nbValeurs] <= 'z' && Val[nbValeurs] >= 'a')
    {
        if (nbValeurs > 0 && Val[nbValeurs] == Val[nbValeurs - 1])
        {
            Val[nbValeurs] = 'A';
            ans ++;
        }
        else if (nbValeurs > 1 && Val[nbValeurs] == Val[nbValeurs - 2])
        {
            Val[nbValeurs] = 'A';
            ans ++;
        }
        nbValeurs ++;
    }
    printf("%d\n", ans);
    return;
}

int main() {
    int nbTests;
    scanf("%d\n", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}