#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int n;

void Read() {
    scanf("%lld", &n);
    int x = n / 2;
    for (int i = 0; i < x; i ++)
    {
        printf("a");
    }
    printf("b");
    for (int i = 1; i < x; i ++)
    {
        printf("a");
    }
    if ((n & 1) && n > 1)
        printf("c");
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}