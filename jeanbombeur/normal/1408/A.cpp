#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_NOEUDS = (1000);

int Valeurs[MAX_NOEUDS][3];

int nbTests, nbNoeuds;

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%d", &nbNoeuds);
        for (int j = 0; j < 3; j ++)
        {
            for (int k = 0; k < nbNoeuds; k ++)
            {
                scanf("%d", &Valeurs[k][j]);
            }
        }
        printf("%d ", Valeurs[0][0]);
        int last = 0;
        for (int j = 1; j < nbNoeuds - 1; j ++)
        {
            if (Valeurs[j][0] == Valeurs[j - 1][last])
            {
                printf("%d ", Valeurs[j][1]);
                last = 1;
            }
            else
            {
                printf("%d ", Valeurs[j][0]);
                last = 0;
            }
        }
        for (int j = 0; j < 3; j ++)
        {
            if (Valeurs[nbNoeuds - 1][j] != Valeurs[0][0] && Valeurs[nbNoeuds - 1][j] != Valeurs[nbNoeuds - 2][last])
            {
                printf("%d\n", Valeurs[nbNoeuds - 1][j]);
                j = 42;
            }
        }
    }
    return;
}

int main() {
    Read();
    return 0;
}