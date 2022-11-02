#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (1e2);

int Val[MAX_VALUES];

int Ask[MAX_VALUES];

int nbValues;

int Query() {
    printf("? ");
    for (int i = 0; i < nbValues; i ++)
    {
        printf("%lld ", Ask[i]);
    }
    cout << endl;
    int ans;
    scanf("%lld", &ans);
    return ans;
}

void Solve() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        Ask[i] = 1;
    }
    for (int i = 1; i < nbValues; i ++)
    {
        Ask[nbValues - 1] = i + 1;
        int a = Query();
        if (a == 0)
        {
            Val[nbValues - 1] = nbValues - i + 1;
            for (int j = 0; j < nbValues - 1; j ++)
            {
                if (Val[j] > 0)
                    Val[j] += Val[nbValues - 1];
            }
            break;
        }
        else
            Val[-- a] = i;
    }
    if (Val[nbValues - 1] == 0)
    {
        for (int j = 0; j < nbValues; j ++)
        {
            Val[j] ++;
        }
    }
    Ask[nbValues - 1] = 1;
    for (int i = 1; i < Val[nbValues - 1]; i ++)
    {
        for (int j = 0; j < nbValues - 1; j ++)
        {
            Ask[j] = Val[nbValues - 1] + 1 - i;
        }
        int a = Query();
        Val[-- a] = i;
    }
    printf("! ");
    for (int i = 0; i < nbValues; i ++)
    {
        printf("%lld ", Val[i]);
    }
    cout << endl;
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}