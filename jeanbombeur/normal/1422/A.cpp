#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_NOEUDS = (100 * 1000);

int Valeurs[MAX_NOEUDS];

int nbTests, nbNoeuds;

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", max(a, max(b, c)));
    }
    return;
}

int main() {
    Read();
    return 0;
}