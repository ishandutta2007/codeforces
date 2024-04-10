#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (100 * 1000);

pair <int, int> Val[MAX_VALEURS];

int nbValeurs, dist;

int ManhattanDist(pair <int, int> i, pair <int, int> j) {
    return max(i.first - j.first, j.first - i.first) + max(i.second - j.second, j.second - i.second);
}

void Read() {
    scanf("%d %d", &nbValeurs, &dist);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d %d", &Val[i].first, &Val[i].second);
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        int nb = 0;
        for (int j = 0; j < nbValeurs; j ++)
        if (ManhattanDist(Val[i], Val[j]) <= dist)
        {
            nb ++;
        }
        if (nb == nbValeurs)
        {
            printf("1\n");
            return;
        }
    }
    printf("-1\n");
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