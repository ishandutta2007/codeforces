#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#define int long long
using namespace std;
 
//  <|_|>
 
//  It's not me who has a problem, it's the world that seems to have a problem with me
 
const int MAX_VALEURS = (300 * 1000 + 2);
 
int Fenwick[2][MAX_VALEURS];
 
int nbValeurs;
 
void Add(int i, int d, int id) {
    for (; i < MAX_VALEURS; i |= (i + 1))
        Fenwick[id][i] += d;
    return;
}
 
int RangeSum(int a, int b, int id) {
    int ans = 0;
    b = min(b, MAX_VALEURS);
    for (; b > a; b &= (b - 1))
        ans += Fenwick[id][b - 1];
    for (; b < a; a &= (a - 1))
        ans -= Fenwick[id][a - 1];
    return ans;
}
 
void Read() {
    scanf("%lld", &nbValeurs);
    int ans = 0;
    int prefSum = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        int a;
        scanf("%lld", &a);
        ans += prefSum;
        ans += a * i;
        ans -= RangeSum(0, a + 1, 1);
        for (int k = a; k < MAX_VALEURS; k += a)
        {
            ans -= k * RangeSum(k, k + a, 0);
            Add(k, a, 1);
        }
        Add(a, 1, 0);
        prefSum += a;
        printf("%lld ", ans);
    }
    printf("\n");
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