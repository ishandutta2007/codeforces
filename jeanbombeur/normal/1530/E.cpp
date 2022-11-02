#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
// #define int long long
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

const int MAX_VALEURS = (200 * 1000);
const int ALPHABET = (26);

char Val[MAX_VALEURS];

int Occ[ALPHABET];

vector <int> Lettres;

int longueur;

void Read() {
    scanf("%s", Val);
    longueur = strlen(Val);
    
    fill_n(Occ, ALPHABET, 0);
    
    int deb = 1 << 30;
    
    for (int i = 0; i < longueur; i ++)
    {
        Occ[Val[i] - 'a'] ++;
        deb = min(deb, Val[i] - 'a');
    }
    
    for (int i = 0; i < ALPHABET; i ++)
    {
        if (Occ[i] > 0)
        {
            if (Occ[i] == 1 && Occ[deb] > 1)
                deb = i;
        }
    }
    
    Lettres.clear();
    
    for (int i = 0; i < ALPHABET; i ++)
    {
        if (i != deb)
        {
            for (int j = 0; j < Occ[i]; j ++)
            {
                Lettres.push_back(i);
            }
        }
    }
    
    if (Occ[deb] == 1)
    {
        printf("%c", 'a' + deb);
        for (int a : Lettres)
        {
            printf("%c", 'a' + a);
        }
        printf("\n");
        return;
    }
    
    int sz = Lettres.size();
    
    if (sz == 0)
    {
        while (Occ[deb] -- > 0)
            printf("%c", 'a' + deb);
        printf("\n");
        return;
    }
    
    int cur = 0;
    
    if ((Occ[deb] - 2) <= sz)
    {
        printf("%c", 'a' + deb);
        Occ[deb] --;
        while (Occ[deb] > 0 || cur < sz)
        {
            if (Occ[deb] -- > 0)
                printf("%c", 'a' + deb);
            if (cur < sz)
                printf("%c", 'a' + Lettres[cur ++]);
        }
        printf("\n");
        return;
    }
    
    printf("%c%c", 'a' + deb, 'a' + Lettres[cur ++]);
    Occ[deb] --;
    
    if (Lettres.back() != Lettres[0])
    {
        while (Occ[deb] -- > 0)
            printf("%c", 'a' + deb);
        int last = cur;
        while (Lettres[last] == Lettres[cur])
            last ++;
        printf("%c", 'a' + Lettres[last]);
        while (cur < last)
            printf("%c", 'a' + Lettres[cur ++]);
        cur ++;
        while (cur < sz)
            printf("%c", 'a' + Lettres[cur ++]);
        printf("\n");
        return;
    }
    
    while (cur < sz)
        printf("%c", 'a' + Lettres[cur ++]);
    while (Occ[deb] -- > 0)
        printf("%c", 'a' + deb);

    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}