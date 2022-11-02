#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Petit coup de chance

const int MAX_VALEURS = (200 * 1000);

pair <int, int> Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    
    int sumUp = 0, sumDown = 0;
    
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i].first);
        sumUp += Val[i].first;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i].second);
    }
    
    int mini = (1LL << 60);
    
    for (int i = 0; i < nbValeurs; i ++)
    {
        sumUp -= Val[i].first;
        mini = min(mini, max(sumUp, sumDown));
        sumDown += Val[i].second;
    }
    
    printf("%lld\n", mini);
    
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