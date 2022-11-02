#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_LONGUEUR = (300 * 1000);

int Valeur[MAX_LONGUEUR];

int nbTests, longueur, mod;

void Read() {
    scanf("%d", &nbTests);
    for (int k = 0; k < nbTests; k ++)
    {
        scanf("%d%d", &longueur, &mod);
        char c;
        scanf("%c", &c);
        bool t = true;
        for (int i = 0; i < mod; i ++)
        {
            Valeur[i] = 0;
        }
        for (int i = 0; i < longueur; i ++)
        {
            scanf("%c", &c);
            int x = Valeur[i % mod];
            if (c == '0')
            {
                if (x == 2)
                {
                    t = false;
                }
                Valeur[i % mod] = 1;
            }
            if (c == '1')
            {
                if (x == 1)
                {
                    t = false;
                }
                Valeur[i % mod] = 2;
            }
        }
        int a = 0, b = 0;
        for (int j = 0; j < mod; j ++)
        {
            if (Valeur[j] == 1)
            {
                a ++;
            }
            if (Valeur[j] == 2)
            {
                b ++;
            }
        }
        if (2 * a > mod || 2 * b > mod)
        {
            t = false;
        }
        if (t)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return;
}

int main() {
    Read();
    return 0;
}