#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  With great power comes great responsability

//  This is my gift, my curse

//  When the student is ready, the teacher will appear. When the student is truly ready, the teacher will disappear.

//  There are no accidents

//  The hardest choices require the strongest wills

//  You're not the only one cursed with knowledge

//  What is better - to be born good, or to overcome your evil nature with great effort ?

//  We must be better

const int MAX_VAL = (200 * 1000);

int Val[MAX_VAL];

int nbLignes, nbColonnes;

void Read() {
    scanf("%lld %lld", &nbLignes, &nbColonnes);
    
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            if ((j == 0 || j == nbColonnes - 1) && (i == 0 || i == nbLignes - 1))
                printf("1");
            else if ((j == 0 || j == nbColonnes - 1) && !(i & 1) && i != nbLignes - 2)
                printf("1");
            else if ((i == 0 || i == nbLignes - 1) && !(j & 1) && j != nbColonnes - 2)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}