#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define double long double
using namespace std;

const int MAX_PAIRES = (1000 * 1000);

pair <int, int> Paires[MAX_PAIRES];

int nbPairesTot = 0;

int nbCases;

void Treat(int deb, int fin) {
    if (deb >= fin)
    {
        return;
    }
    int milieu = (deb + fin) / 2;
    Treat(deb, milieu);
    Treat(milieu + 1, fin);
    for (int i = deb; i <= milieu; i ++)
    {
        Paires[nbPairesTot ++] = make_pair(i, fin + deb - i);
    }
    return;
}

void Read() {
    scanf("%d", &nbCases);
    int k = 1;
    while (k <= nbCases)
    {
        k *= 2;
    }
    k /= 2;
    Treat(1, k);
    Treat(nbCases - k + 1, nbCases);
    printf("%d\n", nbPairesTot);
    for (int i = 0; i < nbPairesTot; i ++)
    {
        printf("%d %d\n", Paires[i].first, Paires[i].second);
    }
    return;
}

int main() {
    Read();
    return 0;
}