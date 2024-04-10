#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

priority_queue <int> Piles;

int Fibo[MAX_VALUES];

int nbValues;

void Read() {
    scanf("%lld", &nbValues);
    int sum = 0;
    while (!Piles.empty())
        Piles.pop();
    for (int i = 0; i < nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        Piles.push(a);
        sum += a;
    }
    if (sum == 1)
    {
        printf("YES\n");
        return;
    }
    Fibo[0] = Fibo[1] = 1;
    int cur = 2, _sum = 2;
    while (_sum < sum)
    {
        Fibo[cur] = Fibo[cur - 1] + Fibo[cur - 2];
        _sum += Fibo[cur ++];
    }
    if (_sum != sum)
    {
        printf("NO\n");
        return;
    }
    int last = 0;
    while (cur --)
    {
        if (Piles.empty())
        {
            printf("NO\n");
            return;
        }
        int a = Piles.top();
        Piles.pop();
        if (a < Fibo[cur])
        {
            printf("NO\n");
            return;
        }
        if (last)
            Piles.push(last);
        last = a - Fibo[cur];
    }
    printf("YES\n");
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