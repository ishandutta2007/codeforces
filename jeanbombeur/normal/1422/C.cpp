#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_CHIFFRES = (1000 * 1000);

int Chiffres[MAX_CHIFFRES];

int Puissances[MAX_CHIFFRES];

int Coef[MAX_CHIFFRES];

char Entree[MAX_CHIFFRES];

void Read() {
    for (int i = 0; i < MAX_CHIFFRES; i ++)
    {
        Entree[i] = 'A';
    }
    int nbChiffres = 0;
    scanf("%s", Entree);
    while ('0' <= Entree[nbChiffres] && Entree[nbChiffres] <= '9')
    {
        Chiffres[nbChiffres] = Entree[nbChiffres] - '0';
        nbChiffres ++;
    }
    int x = 1;
    for (int i = 0; i < nbChiffres; i ++)
    {
        Puissances[i] = x;
        x *= 10;
        x %= MOD;
    }
    x = 0;
    for (int i = 0; i < nbChiffres; i ++)
    {
        Coef[i] = x;
        x += Puissances[i] * (i + 1);
        x %= MOD;
    }
    int sum = 0;
    for (int i = 0; i < nbChiffres; i ++)
    {
        sum += Chiffres[i] * Coef[nbChiffres - i - 1];
        sum %= MOD;
        int d = ((i + 1) * i) / 2;
        d %= MOD;
        d *= Puissances[nbChiffres - i - 1];
        d %= MOD;
        sum += Chiffres[i] * d;
        sum %= MOD;
    }
    printf("%lld\n", sum);
    return;
}

signed main() {
    Read();
    return 0;
}