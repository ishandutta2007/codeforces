#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//     <|_|>

const int BIG_BURGER = (1000 * 1000);
const int MAX_VALEURS = (1000 * 100);
const int MAX_LOG = 20;

int Val[MAX_VALEURS];

int Mult[MAX_LOG];
int Add[MAX_LOG];

char Op[3];

int nbValeurs;

bool Check(char c)
{
    return (Op[0] == c || Op[1] == c || Op[2] == c);
}

int Calcule(int mask, int rangMax) {
    int ans = 0;
    int prod = Mult[0];
    for (int i = 0; i < rangMax; i ++)
    {
        if (mask & (1 << i))
        {
            prod *= Mult[i + 1];
        }
        else
        {
            ans += prod;
            ans += Add[i];
            prod = Mult[i + 1];
        }
    }
    ans += prod;
    return ans;
}

void Solve(int gauche, int droite) {
    if (gauche > droite)
    {
        return;
    }
    if (gauche > 0)
    {
        printf("+");
    }
    while (Val[gauche] == 1 && gauche < droite)
    {
        printf("1+");
        gauche ++;
    }
    if (Val[gauche] == 1)
    {
        printf("1");
        return;
    }
    int oldDroite = droite;
    while (Val[droite] == 1 && droite >= gauche)
    {
        droite --;
    }
    int prod = 1;
    for (int i = gauche; i <= droite; i ++)
    {
        prod *= Val[i];
        if (prod > BIG_BURGER)
        {
            for (int j = gauche; j < droite; j ++)
            {
                printf("%d*", Val[j]);
            }
            printf("%d", Val[droite]);
            for (int j = droite + 1; j <= oldDroite; j ++)
            {
                printf("+1");
            }
            return;
        }
    }
    prod = 1;
    int sum = 0;
    int cur = 0;
    for (int i = gauche; i <= droite; i ++)
    {
        if (Val[i] == 1 && sum == 0)
        {
            Mult[cur] = prod;
            prod = 0;
        }
        if (Val[i] > 1 && prod == 0)
        {
            Add[cur ++] = sum;
            sum = 0;
            prod = 1;
        }
        if (Val[i] == 1)
        {
            sum ++;
        }
        else
        {
            prod *= Val[i];
        }
    }
    Mult[cur] = prod;
    int maximum = 0;
    int maskMaxi = 0;
    for (int mask = 0; mask < (1 << cur); mask ++)
    {
        if (Calcule(mask, cur) > maximum)
        {
            maximum = Calcule(mask, cur);
            maskMaxi = mask;
        }
    }
    int act = 0;
    for (int i = gauche; i < droite; i ++)
    {
        if (Val[i] > 1 && Val[i + 1] > 1)
        {
            printf("%d*", Val[i]);
        }
        if (Val[i + 1] == 1)
        {
            if (maskMaxi & (1 << act))
            {
                printf("%d*", Val[i]);
            }
            else
            {
                printf("%d+", Val[i]);
            }
        }
        if (Val[i] == 1 && Val[i + 1] > 1)
        {
            if (maskMaxi & (1 << act))
            {
                printf("%d*", Val[i]);
            }
            else
            {
                printf("%d+", Val[i]);
            }
            act ++;
        }
    }
    printf("%d", Val[droite]);
    for (int i = droite + 1; i <= oldDroite; i ++)
    {
        printf("+1");
    }
    return;
}

void Read() {
    scanf("%d", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%d", &Val[i]);
    }
    scanf("%s", Op);
    if (Check('+'))
    {
        if (Check('*'))
        {
            int last = 0;
            for (int i = 0; i < nbValeurs; i ++)
            {
                if (Val[i] == 0)
                {
                    Solve(last, i - 1);
                    if (i > 0)
                    {
                        printf("+");
                    }
                    printf("0");
                    last = i + 1;
                }
            }
            Solve(last, nbValeurs - 1);
            printf("\n");
            return;
        }
        for (int i = 0; i < nbValeurs - 1; i ++)
        {
            printf("%d+", Val[i]);
        }
        printf("%d\n", Val[nbValeurs - 1]);
        return;
    }
    if (Check('*'))
    {
        if (!Check('-'))
        {
            for (int i = 0; i < nbValeurs - 1; i ++)
            {
                printf("%d*", Val[i]);
            }
            printf("%d\n", Val[nbValeurs - 1]);
            return;
        }
        bool t = false;
        for (int i = 0; i < nbValeurs - 1; i ++)
        {
            if (t)
            {
                printf("%d*", Val[i]);
            }
            else if (Val[i] == 0)
            {
                t = true;
                printf("%d*", Val[i]);
            }
            else if (Val[i + 1] == 0)
            {
                printf("%d-", Val[i]);
            }
            else
            {
                printf("%d*", Val[i]);
            }
        }
        printf("%d\n", Val[nbValeurs - 1]);
        return;
    }
    for (int i = 0; i < nbValeurs - 1; i ++)
    {
        printf("%d-", Val[i]);
    }
    printf("%d\n", Val[nbValeurs - 1]);
    return;
}

int main() {
    Read();
    return 0;
}