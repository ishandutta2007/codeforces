#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_VALEURS = (200 * 1000 + 1);
const int MAX_BIT = (31);

int Val[MAX_VALEURS];
int Bit[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    int nb = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        for (int j = 0; j < MAX_BIT; j ++)
        {
            if (Bit[i] == 0 && (1 << j) > Val[i])
            {
                Bit[i] = j;
            }
        }
    }
    Val[nbValeurs] = (1 << 30);
    for (int i = 0; i < nbValeurs - 2; i ++)
    {
        int droite = i + 2;
        int sum = Val[i + 1];
        while (sum < (1 << Bit[i]))
        {
            if ((Val[i] ^ Val[droite]) == sum && Val[i] > Val[droite])
            {
                nb ++;
                //printf("%d %d\n", i, droite);
            }
            sum += Val[droite ++];
        }
    }
    for (int i = 0; i < nbValeurs / 2; i ++)
    {
        int a = Val[i];
        Val[i] = Val[nbValeurs - i - 1];
        Val[nbValeurs - i - 1] = a;
    }
    for (int i = 0; i < nbValeurs - 2; i ++)
    {
        int droite = i + 2;
        int sum = Val[i + 1];
        while (sum < (1 << Bit[nbValeurs - i - 1]))
        {
            if ((Val[i] ^ Val[droite]) == sum && Val[i] >= Val[droite])
            {
                nb ++;
                //printf("%d %d\n", nbValeurs - i - 1, nbValeurs - droite - 1);
            }
            sum += Val[droite ++];
        }
    }
    printf("%d\n", nb);
    return;
}

int main() {
    Read();
    return 0;
}