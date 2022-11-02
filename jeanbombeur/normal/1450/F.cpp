#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

pair <int, int> Occ[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    int cut = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        Occ[i] = {0, 0};
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        Occ[Val[i] - 1].first ++;
        if (i > 0 && Val[i] == Val[i - 1])
        {
            Occ[Val[i] - 1].second += 2;
            cut ++;
        }
    }
    Occ[Val[0] - 1].second ++;
    Occ[Val[nbValeurs - 1] - 1].second ++;
    int maximum = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (2 * Occ[i].first > nbValeurs + 1)
        {
            printf("-1\n");
            return;
        }
        if (Occ[i].second > maximum)
        {
            maximum = Occ[i].second;
        }
    }
    printf("%d\n", max(cut, maximum - 2));
    return;
}



int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}