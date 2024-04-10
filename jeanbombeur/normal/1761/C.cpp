#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (101);

char Val[MAX_VALUES][MAX_VALUES];

int nbValues;

void Read() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%s", Val[i]);
    }
    for (int i = 0; i < nbValues; i ++)
    {
        vector <int> a;
        a.push_back(i + 1);
        for (int j = 0; j < nbValues; j ++)
        {
            if (Val[j][i] == '1')
                a.push_back(j + 1);
        }
        printf("%lld ", (int)a.size());
        for (int x : a)
            printf("%lld ", x);
        printf("\n");
    }
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}