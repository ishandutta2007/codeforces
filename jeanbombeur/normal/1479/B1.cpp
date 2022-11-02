#include <iostream>
#include <cstdio>
using namespace std;

//    <|_|>

const int MAX_VALEURS = (100 * 1000 + 2);

int Val[MAX_VALEURS];
int Last[MAX_VALEURS];
int Next[MAX_VALEURS];
int Top[2];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    int ans = 0;
    Next[0] = MAX_VALEURS + 2;
    for (int i = 1; i <= nbValeurs; i ++)
    {
        Next[i] = MAX_VALEURS;
        scanf("%d", &Val[i]);
        if (Last[Val[i]] > 0)
        {
            Next[Last[Val[i]]] = i;
        }
        Last[Val[i]] = i;
    }
    for (int i = 1; i <= nbValeurs; i ++)
    {
        if (Val[Top[0]] == Val[i] || Val[Top[1]] == Val[i])
        {
            if (Val[Top[0]] != Val[Top[1]])
            {
                ans ++;
            }
            Top[0] = i;
            Top[1] = i;
        }
        else
        {
            ans ++;
            if (Next[Top[0]] < Next[Top[1]])
            {
                Top[0] = i;
            }
            else
            {
                Top[1] = i;
            }
        }
    }
    printf("%d\n", ans);
    return;
}

int main() {
    int nbTests = 1;
    //scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}