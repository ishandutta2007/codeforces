#include <iostream>
#include <cstdio>
using namespace std;
 
//    <|_|>
 
const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

pair <int, int> Marges[MAX_VALEURS];

int nbValeurs, k;

void Read() {
    scanf("%d%d", &nbValeurs, &k);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (i == 0)
        {
            Marges[i].first = Val[i];
            Marges[i].second = Val[i];
        }
        if (i > 0)
        {
            Marges[i].first = max(Marges[i - 1].first - k + 1, Val[i]);
            Marges[i].second = min(Val[i] + k - 1, Marges[i - 1].second + k - 1);
            if (Marges[i].first > Marges[i].second)
            {
                printf("NO\n");
                return;
            }
        }
        //printf("%d %d\n", Marges[i].first, Marges[i].second);
    }
    if (Marges[nbValeurs - 1].first > Val[nbValeurs - 1] || Marges[nbValeurs - 1].second < Val[nbValeurs - 1])
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    return;
}
 
int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}