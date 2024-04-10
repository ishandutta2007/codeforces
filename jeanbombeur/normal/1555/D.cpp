#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Petit coup de chance

const int MAX_VALEURS = (300 * 1000);

char Val[MAX_VALEURS];

int Occ[MAX_VALEURS][3][3];

int longueur, nbRequetes;

void Read() {
    scanf("%lld %lld %s", &longueur, &nbRequetes, Val);
    
    for (int i = 0; i < longueur; i ++)
    {
        Occ[i + 1][i % 3][Val[i] - 'a'] ++;
    }
    
    for (int i = 1; i <= longueur; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            for (int k = 0; k < 3; k ++)
            {
                Occ[i][j][k] += Occ[i - 1][j][k];
            }
        }
    }
    
    for (int i = 0; i < nbRequetes; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        a --;
        int mini = (1LL << 60);
        for (int j = 0; j < 3; j ++)
        {
            for (int k = 0; k < 3; k ++)
            {
                if (k != j)
                {
                    int l = 3 ^ j ^ k;
                    int sum = 0;
                    for (int yoyo = 0; yoyo < 3; yoyo ++)
                    {
                        if (j != yoyo)
                            sum += Occ[b][0][yoyo] - Occ[a][0][yoyo];
                        if (k != yoyo)
                            sum += Occ[b][1][yoyo] - Occ[a][1][yoyo];
                        if (l != yoyo)
                            sum += Occ[b][2][yoyo] - Occ[a][2][yoyo];
                    }
                    mini = min(mini, sum);
                }
            }
        }
        printf("%lld\n", mini);
    }
    
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