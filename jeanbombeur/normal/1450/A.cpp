#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//     <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];
char Chaine[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    scanf("%s", Chaine);
    sort(Chaine, Chaine + nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        printf("%c", Chaine[i]);
    }
    printf("\n");
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