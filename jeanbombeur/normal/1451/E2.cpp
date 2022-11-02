#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// <|_|>

const int MAX_VALEURS = (1000 * 1000);

int Val[MAX_VALEURS];
pair <int, int> Triees[MAX_VALEURS];

int nbValeurs;

int Ask(int a, int b, int c) {
    if (c == 0)
    {
        printf("XOR ");
    }
    else
    {
        printf("OR ");
    }
    printf("%d %d\n", a, b);
    cout.flush();
    int ans;
    scanf("%d", &ans);
    return ans;
}

void Read() {
    scanf("%d", &nbValeurs);
    int un = nbValeurs - 1;
    int deux = nbValeurs - 1;
    int dep = -1;
    Val[0] = 0;
    Triees[0] = make_pair(0, 1);
    for (int i = 1; i < nbValeurs; i ++)
    {
        Val[i] = Ask(1, i + 1, 0);
        if (Val[i] == 1)
        {
            un = i;
        }
        if (Val[i] == 2)
        {
            deux = i;
        }
        Triees[i] = make_pair(Val[i], i + 1);
    }
    sort(Triees, Triees + nbValeurs);
    for (int i = 0; i < nbValeurs - 1; i ++)
    {
        if (Triees[i].first == Triees[i + 1].first && dep < 0)
        {
            dep = Ask(Triees[i].second, Triees[i + 1].second, 1);
            dep ^= Triees[i].first;
        }
    }
    if (dep < 0)
    {
        dep = 0;
        int cur = Ask(1, un + 1, 1);
        for (int bit = 1; bit < 16; bit ++)
        {
            if ((cur & (1 << bit)) > 0)
            {
                dep += (1 << bit);
            }
        }
        cur = Ask(1, deux + 1, 1);
        if ((cur & 1) > 0)
        {
            dep += 1;
        }
    }
    printf("! ");
    for (int i = 0; i < nbValeurs; i ++)
    {
        printf("%d ", Val[i] ^ dep);
    }
    printf("\n");
    return;
}

int main() {
    Read();
    return 0;
}