#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//     <|_|>

const int INFINI = (1000 * 1000 * 1000);
const int MAX_NOEUDS = 200;
const int MAX_ARETES = 2000;

int MinDist[MAX_NOEUDS][MAX_NOEUDS];

pair <int, int> Aretes[MAX_ARETES];

int nbNoeuds, nbAretes;

void Init() {
    for (int i = 0; i < MAX_NOEUDS; i ++)
    {
        for (int j = i + 1; j < MAX_NOEUDS; j ++)
        {
            MinDist[i][j] = INFINI;
            MinDist[j][i] = INFINI;
        }
    }
    return;
}

void Read() {
    scanf("%d%d", &nbNoeuds, &nbAretes);
    for (int i = 0; i < nbAretes; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        MinDist[-- a][-- b] = 1;
        MinDist[b][a] = 1 - 2 * c;
        Aretes[i] = {a, b};
    }
    for (int i = 0; i < nbNoeuds; i ++)
    {
        for (int j = 0; j < nbNoeuds; j ++)
        {
            for (int k = 0; k < nbNoeuds; k ++)
            {
                MinDist[j][k] = min(MinDist[j][k], MinDist[j][i] + MinDist[i][k]);
            }
        }
    }
    pair <int, int> dep;
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (MinDist[i][i] < 0)
        {
            printf("NO\n");
            return;
        }
        for (int j = 0; j < nbNoeuds; j ++)
        {
            if (MinDist[i][j] > MinDist[dep.first][dep.second])
            {
                dep = {i, j};
            }
        }
    }
    for (int i = 0; i < nbAretes; i ++)
    {
        if (max(MinDist[dep.first][Aretes[i].first] - MinDist[dep.first][Aretes[i].second], MinDist[dep.first][Aretes[i].second] - MinDist[dep.first][Aretes[i].first]) != 1)
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n%d\n", MinDist[dep.first][dep.second]);
    for (int i = 0; i < nbNoeuds; i ++)
    {
        printf("%d ", MinDist[dep.first][i]);
    }
    printf("\n");
    return;
}

int main() {
    Init();
    Read();
    return 0;
}