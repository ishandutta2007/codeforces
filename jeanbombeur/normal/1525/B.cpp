#include <iostream>
#include <cstdio>
using namespace std;

//   <|_|>

const int MAX_VAL = (50);

int Val[MAX_VAL];

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    bool t = true;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
        if (Val[i] != i + 1)
            t = false;
    }
    if (t)
    {
        printf("0\n");
        return;
    }
    if (Val[0] == 1 || Val[nbValeurs - 1] == nbValeurs)
    {
        printf("1\n");
        return;
    }
    if (Val[0] == nbValeurs && Val[nbValeurs - 1] == 1)
    {
        printf("3\n");
        return;
    }
    printf("2\n");
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