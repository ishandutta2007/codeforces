#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//   <|_|>
// Check yourself before you Shrek yourself
// The hardest choices require the strongest wills

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    int reste = nbValeurs % 11;
    if (nbValeurs < reste * 111)
        printf("NO\n");
    else
        printf("YES\n");
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}