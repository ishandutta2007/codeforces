#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//   <|_|>

const int MAX_VALEURS = (5000);

int Val[2][MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < 2; i ++)
    {
        for (int j = 0; j < nbValeurs; j ++)
        {
            scanf("%lld", &Val[i][j]);
        }
    }
    int reference = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        reference += Val[0][i] * Val[1][i];
    }
    int maximum = reference;
    for (int middle = 0; middle < nbValeurs; middle ++)
    {
        int cur = reference;
        for (int ecart = 1; ecart <= min(middle, nbValeurs - middle - 1); ecart ++)
        {
            cur -= Val[0][middle - ecart] * Val[1][middle - ecart];
            cur -= Val[0][middle + ecart] * Val[1][middle + ecart];
            cur += Val[0][middle - ecart] * Val[1][middle + ecart];
            cur += Val[0][middle + ecart] * Val[1][middle - ecart];
            maximum = max(maximum, cur);
        }
        cur = reference;
        for (int ecart = 0; ecart <= min(middle - 1, nbValeurs - middle - 1); ecart ++)
        {
            cur -= Val[0][middle - ecart - 1] * Val[1][middle - ecart - 1];
            cur -= Val[0][middle + ecart] * Val[1][middle + ecart];
            cur += Val[0][middle - ecart - 1] * Val[1][middle + ecart];
            cur += Val[0][middle + ecart] * Val[1][middle - ecart - 1];
            maximum = max(maximum, cur);
        }
    }
    printf("%lld\n", maximum);
    return;
}

signed main() {
    Read();
    return 0;
}