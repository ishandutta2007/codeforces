#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Right on time

const int MAX_VALUES = (2e5);

char Val[MAX_VALUES];

int Mex, Xor;

void Solve() {
    scanf("%lld %lld", &Mex, &Xor);
    Mex --;
    if ((Mex & 3) == 1 || ((Mex & 3) == 2))
        Xor ^= 1;
    if (!(Mex & 1))
        Xor ^= Mex;
    if (Xor == 0)
        printf("%lld\n", Mex + 1);
    else if (Xor == (Mex + 1))
        printf("%lld\n", Mex + 3);
    else
        printf("%lld\n", Mex + 2);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}