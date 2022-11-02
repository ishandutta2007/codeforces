#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//    <|_|>

const int MAX_LETTRES = 1000;

char Mot[MAX_LETTRES];

int taille;

void Read() {
    scanf("%s", Mot);
    taille = strlen(Mot);
    bool a = false, b = false;
    for (int i = 1; i < taille; i ++)
    {
        if (Mot[i] == Mot[i - 1])
        {
            if (Mot[i] == '1')
                a = true;
            if (a && Mot[i] == '0')
                b = true;
        }
    }
    if (b)
        printf("NO\n");
    else
        printf("YES\n");
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