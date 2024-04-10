#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
//  <|_|>
 
//  Why do we fall, sir ?
 
const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (4000 * 1000);

int Occ[4];

int nbPoints;
 
void Read() {
    scanf("%lld", &nbPoints);
    for (int i = 0; i < nbPoints; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Occ[(a & 2) + (b & 2) / 2] ++;
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < 4; i ++)
    {
        sum += Occ[i];
    }
    for (int i = 0; i < 4; i ++)
    {
        ans += ((Occ[i] * (Occ[i] - 1)) * (sum - Occ[i])) / 2;
        ans += (Occ[i] * (Occ[i] - 1) * (Occ[i] - 2)) / 6;
    }
    printf("%lld\n", ans);
    return;
}
 
signed main() {
    Read();
    return 0;
}