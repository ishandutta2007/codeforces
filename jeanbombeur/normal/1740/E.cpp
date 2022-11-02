#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_NODES = (1e5);

int Parent[MAX_NODES];
int Prof[MAX_NODES];

int DP[MAX_NODES];

int nbNodes;

void Read() {
    scanf("%lld", &nbNodes);
    for (int i = 1; i < nbNodes; i ++)
    {
        scanf("%lld", &Parent[i]);
        Parent[i] --;
        Prof[i] ++;
    }
    for (int i = nbNodes - 1; i; i --)
    {
        DP[i] = max(DP[i], Prof[i]);
        Prof[Parent[i]] = max(Prof[Parent[i]], Prof[i] + 1);
        DP[Parent[i]] += DP[i];
    }
    printf("%lld\n", max(DP[0], Prof[0]));
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