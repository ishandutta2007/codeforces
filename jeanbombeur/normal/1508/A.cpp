#include <iostream>
#include <cstdio>
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000);

char Chaines[3][2 * MAX_VALEURS + 1];
char Ans[3 * MAX_VALEURS];

int Nb[3][2];

int nbValeurs;

void Read() {
    scanf("%d\n", &nbValeurs);
    for (int i = 0; i < 6; i ++)
        Nb[i / 2][i % 2] = 0;
    for (int i = 0; i < 3; i ++)
    {
        scanf("%s", Chaines[i]);
        Chaines[i][2 * nbValeurs] = '2';
        for (int j = 0; j < 2 * nbValeurs; j ++)
        {
            Nb[i][Chaines[i][j] - '0'] ++;
        }
    }
    int a = 0, b = 1;
    char c = '0', d = '1';
    for (int i = 0; i < 3; i ++)
    {
        for (int j = i + 1; j < 3; j ++)
        {
            if (Nb[i][0] >= nbValeurs && Nb[j][0] >= nbValeurs)
            {
                a = i;
                b = j;
                c = '0';
                d = '1';
            }
            if (Nb[i][1] >= nbValeurs && Nb[j][1] >= nbValeurs)
            {
                a = i;
                b = j;
                c = '1';
                d = '0';
            }
        }
    }
    int curA = 0, curB = 0, curAns = 0;
    while (curA < 2 * nbValeurs || curB < 2 * nbValeurs)
    {
        if (Chaines[a][curA] == d || Chaines[b][curB] == d)
        {
            Ans[curAns ++] = d;
            if (Chaines[a][curA] == d)
                curA ++;
            if (Chaines[b][curB] == d)
                curB ++;
        }
        else
        {
            Ans[curAns ++] = c;
            if (curA < 2 * nbValeurs)
                curA ++;
            if (curB < 2 * nbValeurs)
                curB ++;
        }
    }
    printf("%s\n", Ans);
    for (int i = 0; i < curAns; i ++)
        Ans[i] = '\0';
    return;
}

int main() {
    int nbTests;
    scanf("%d\n", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}