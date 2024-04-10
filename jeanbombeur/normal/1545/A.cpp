#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
 
//    <|_|>
//
 
const int MAX_VALEURS = (200 * 1000);
 
pair <int, int> Val[MAX_VALEURS];
 
int nbValeurs;
 
void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i].first);
        Val[i].second = i;
    }
    sort(Val, Val + nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        int sum = (Val[i].second & 1) - (i & 1);
        while (i + 1 < nbValeurs && Val[i + 1].first == Val[i].first)
        {
            i ++;
            sum += (Val[i].second & 1) - (i & 1);
        }
        if (sum)
        {
            printf("NO\n");
            return;
        }
    }
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