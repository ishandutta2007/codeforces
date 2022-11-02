#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
//     <|_|>
 
const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (500 * 1000);
const int MAX_BITS = (500 * 1000);
 
pair <int, int> State[MAX_BITS];
 
int Utiles[MAX_VALEURS];
int taille = 0;
 
int nbValeurs, nbBits;
 
int Find(int a) {
    if (State[a].second < 0)
    {
        return a;
    }
    return State[a].second = Find(State[a].second);
}
 
bool Union(int a, int b) {
    int rA = Find(a);
    int rB = Find(b);
    if (rA == rB)
    {
        return false;
    }
    if (State[rA].second > State[rB].second)
    {
        int c = rA;
        rA = rB;
        rB = c;
    }
    State[rA].second += State[rB].second;
    State[rB].second = rA;
    return true;
}
 
void Act(int a) {
    if (State[a].second < 0)
    {
        return;
    }
    if (State[Find(a)].first == 2)
    {
        State[a].first = 2;
        State[a].second = -1;
    }
    return;
}
 
void Init() {
    for (int i = 0; i < MAX_BITS; i ++)
    {
        State[i].second = -1;
    }
    return;
}
 
void Read() {
    scanf("%d%d", &nbValeurs, &nbBits);
    for (int i = 0; i < nbValeurs; i ++)
    {
        int k, a, b;
        scanf("%d", &k);
        if (k == 1)
        {
            scanf("%d", &a);
            a --;
            a = Find(a);
            if (State[a].first == 0)
            {
                State[a].first = 2;
                Utiles[taille ++] = i;
            }
            if (State[a].first == 1)
            {
                Utiles[taille ++] = i;
                State[a].first = 2;
            }
        }
        else
        {
            scanf("%d%d", &a, &b);
            a --;
            b --;
            a = Find(a);
            b = Find(b);
            if (State[a].first < State[b].first)
            {
                int c = a;
                a = b;
                b = c;
            }
            if (State[a].first == 2)
            {
                if (State[b].first == 0)
                {
                    State[b].first = 2;
                    Utiles[taille ++] = i;
                }
                else if (State[b].first == 1)
                {
                    State[b].first = 2;
                    Utiles[taille ++] = i;
                }
            }
            else if (State[a].first == 1)
            {
                if (State[b].first == 0)
                {
                    Union(a, b);
                    State[b].first = 1;
                    Utiles[taille ++] = i;
                }
                else if (State[b].first == 1)
                {
                    if (Union(a, b))
                    {
                        Utiles[taille ++] = i;
                    }
                }
            }
            else if (State[a].first == 0)
            {
                State[a] = {1, -2};
                State[b] = {1, a};
                Utiles[taille ++] = i;
            }
        }
    }
    long long nbPossib = 1;
    for (int i = 0; i < taille; i ++)
    {
        nbPossib <<= 1;
        nbPossib %= MOD;
    }
    printf("%lld %d\n", nbPossib, taille);
    for (int i = 0; i < taille; i ++)
    {
        printf("%d ", Utiles[i] + 1);
    }
    printf("\n");
    return;
}
 
signed main() {
    Init();
    Read();
    return 0;
}