#include <iostream>
#include <cstdio>
using namespace std;
 
//    <|_|>
 
const int MAX_LOG = 20;
const int MAX_VALEURS = (1 << MAX_LOG);

char Entree[MAX_VALEURS];
int Val[MAX_VALEURS];

bool Atteint[MAX_VALEURS];

bool PasZero[MAX_VALEURS];

int nbValeurs, k;

void Read() {
    scanf("%d%d", &nbValeurs, &k);
    scanf("%s", Entree);
    for (int i = 0; i < nbValeurs; i ++)
    {
        Val[i] = Entree[i] - '0';
        PasZero[i] = false;
    }
    int curLog = 1;
    while ((1 << curLog) < nbValeurs)
    {
        curLog ++;
    }
    curLog = min(curLog, k);
    int lastZ = -1;
    if (0 >= k - curLog)
    {
        PasZero[curLog - 1] = true;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (Val[i] == 0)
        {
            lastZ = i;
        }
        if (i - lastZ >= k - curLog)
        {
            PasZero[i + curLog] = true;
        }
    }
    for (int i = 0; i < (1 << curLog); i ++)
    {
        Atteint[i] = false;
    }
    int cur = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        cur <<= 1;
        cur += Val[i];
        if (i >= curLog)
        {
            cur -= (Val[i - curLog] << curLog);
        }
        if (PasZero[i])
        {
            Atteint[cur] = true;
        }
    }
    int maximum = (1 << curLog) - 1;
    while (maximum >= 0 && Atteint[maximum])
    {
        maximum --;
    }
    if (maximum < 0)
    {
        printf("NO\n");
        return;
    }
    int ans = (1 << curLog) - 1 - maximum;
    printf("YES\n");
    for (int i = 0; i < k - curLog; i ++)
    {
        printf("0");
    }
    for (int i = curLog - 1; i >= 0; i --)
    {
        printf("%d", (ans & (1 << i)) >> i);
    }
    printf("\n");
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