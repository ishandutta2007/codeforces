#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (5e5 + 1);

int Val[MAX_VALUES];

int nbValues, target;

void Read() {
    scanf("%lld %lld", &nbValues, &target);
    for (int i = 0; i < nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        Val[a] ++;
    }
    for (int i = 1; i < target; i ++)
    {
        if (Val[i] % (i + 1))
        {
            printf("No\n");
            return;
        }
        Val[i + 1] += Val[i] / (i + 1);
    }
    printf("Yes\n");
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}