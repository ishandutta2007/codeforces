#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
//  <|_|>
 
//  Why do we fall, sir ?
 
const int MAX_VALEURS = (6000);
 
pair <int, int> Points[MAX_VALEURS];
 
long long Occ[MAX_VALEURS][16][4];
 
int nbPoints;
 
int Gcd(int a, int b) {
    return b == 0 ? a : Gcd(b, a % b);
}
 
void Read() {
    scanf("%d", &nbPoints);
    for (int i = 0; i < nbPoints; i ++)
    {
        scanf("%d %d", &Points[i].first, &Points[i].second);
    }
    for (int i = 0; i < nbPoints; i ++)
    {
        for (int j = i + 1; j < nbPoints; j ++)
        {
            int d1 = Points[j].first - Points[i].first;
            int d2 = Points[j].second - Points[i].second;
            int d = Gcd(abs(d1), abs(d2)) & 3;
            d1 += (1 << 30), d2 += (1 << 30);
            d1 &= 3, d2 &= 3;
            Occ[i][(d1 << 2) | d2][d] ++;
            d1 ^= 3, d2 ^= 3;
            d1 ++, d2 ++;
            d1 &= 3, d2 &= 3;
            Occ[j][(d1 << 2) | d2][d] ++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < nbPoints; i ++)
    {
        for (int a = 0; a < 16; a ++)
        {
            for (int b = a; b < 16; b ++)
            {
                if ((a & 5) == (b & 5))
                {
                    int area = (a >> 2) * (b & 3) - (b >> 2) * (a & 3);
                    area = abs(area) & 3;
                    area |= 8;
                    int opp = 2;
                    if (a == b)
                        opp = 0;
                    for (int k = 0; k < 4; k ++)
                    {
                        int other = (area - opp - k) & 3;
                        long long cur = 0;
                        if (a == b)
                        {
                            if (other == k)
                                cur = (Occ[i][a][k] * (Occ[i][a][k] - 1)) / 2;
                            else if (k < other)
                                cur = Occ[i][a][k] * Occ[i][a][other];
                        }
                        else
                            cur = Occ[i][a][k] * Occ[i][b][other];
                        if (other & 1)
                            cur *= 3;
                        ans += cur;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans / 3);
    return;
}
 
signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Read();
    return 0;
}