#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
 
//   <|_|>
 
const int MAX_VALEURS = (100);
 
int Val[MAX_VALEURS][MAX_VALEURS];
 
int Minimum[MAX_VALEURS];
 
vector <int> Valeurs;
 
int nbPoints, nbCoureurs;
 
void Read() {
    scanf("%lld%lld", &nbPoints, &nbCoureurs);
    Valeurs.clear();
    for (int i = 0; i < nbCoureurs; i ++)
    {
        Minimum[i] = (1LL << 60);
    }
    for (int i = 0; i < nbPoints; i ++)
    {
        for (int j = 0; j < nbCoureurs; j ++)
        {
            scanf("%lld", &Val[i][j]);
            Val[i][j] = Val[i][j] * 10000 + i * 100 + j;
            Valeurs.push_back(Val[i][j]);
        }
        sort(Val[i], Val[i] + nbCoureurs);
    }
    sort(Valeurs.begin(), Valeurs.end());
    int borne = Valeurs[nbCoureurs - 1];
    for (int i = 0; i < nbPoints; i ++)
    {
        int dep = 0;
        while (dep < nbCoureurs && Minimum[dep] <= borne)
        {
            dep ++;
        }
        for (int j = 0; j < nbCoureurs; j ++)
        {
            int cur = (nbCoureurs - dep + j) % nbCoureurs;
            printf("%lld ", Val[i][cur] / 10000);
            Minimum[j] = min(Minimum[j], Val[i][cur]);
        }
        printf("\n");
    }
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