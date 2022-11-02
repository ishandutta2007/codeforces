#include <iostream>
#include <cstdio>
using namespace std;

// <|_|>

const int MAX_VALEURS = (1000 * 1000);

int Val[MAX_VALEURS];

int nbValeurs, nbTests;

void Read() {
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("0\n");
        return;
    }
    if (n == 2)
    {
        printf("1\n");
        return;
    }
    if (n == 3 || n % 2 == 0)
    {
        printf("2\n");
        return;
    }
    printf("3\n");
    return;
}

int main() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}