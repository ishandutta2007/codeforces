#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define int long long
using namespace std;

//  <|_|>

//  It's not me who has a problem, it's the world that seems to have a problem with me

const int MAX_VALEURS = (1000 * 1000 + 2);

bool IsComposite[MAX_VALEURS];

int Val[2][MAX_VALEURS];

int Dsu[MAX_VALEURS];

set <int> Amis[MAX_VALEURS];
set <int> OldAmis[MAX_VALEURS];

vector <int> Multiples[2];

int nbValeurs, nbRequetes;

int Find(int a) {
    return Dsu[a] < 0 ? a : Dsu[a] = Find(Dsu[a]);
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b)
        return false;
    if (Dsu[a] > Dsu[b])
        swap(a, b);
    Dsu[a] += Dsu[b];
    Dsu[b] = a;
    return true;
}

void Read() {
    scanf("%lld %lld", &nbValeurs, &nbRequetes);
    for (int i = 0; i < nbValeurs; i ++)
    {
        int a;
        scanf("%lld", &a);
        Val[0][a] = i + 1;
        Val[1][a + 1] = i + 1;
    }
    fill_n(Dsu, nbValeurs, -1);
    for (int i = 2; i < MAX_VALEURS; i ++)
    {
        if (!IsComposite[i])
        {
            Multiples[0].clear();
            Multiples[1].clear();
            for (int k = i; k < MAX_VALEURS; k += i)
            {
                IsComposite[k] = true;
                if (Val[0][k])
                    Multiples[0].push_back(Val[0][k] - 1);
                if (Val[1][k])
                    Multiples[1].push_back(Val[1][k] - 1);
            }
            if (Multiples[0].size())
            {
                for (int a : Multiples[0])
                    Union(a, Multiples[0][0]);
                for (int a : Multiples[1])
                    OldAmis[a].insert(Multiples[0][0]);
            }
        }
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        for (int a : OldAmis[i])
        {
            for (int b : OldAmis[i])
            {
                if (a != b)
                {
                    Amis[a].insert(b);
                    Amis[b].insert(a);
                }
            }
            Amis[i].insert(a);
        }
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (Dsu[i] < 0)
        {
            set <int> nv;
            for (int a : Amis[i])
                nv.insert(Find(a));
            Amis[i] = nv;
        }
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (Dsu[i] >= 0)
        {
            int r = Find(i);
            for (int a : Amis[i])
                Amis[r].insert(Find(a));
            Amis[i].clear();
        }
    }
    /*for (int i = 0; i < nbValeurs; i ++)
    {
        printf("%lld  ", Find(i));
        for (int a : Amis[i])
            printf("%lld ", a);
        printf("\n");
    }*/
    for (int i = 0; i < nbRequetes; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        a = Find(a - 1), b = Find(b - 1);
        if (a == b)
            printf("0\n");
        else
        {
            if (Amis[a].count(b) || Amis[b].count(a))
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return;
}

signed main() {
    Read();
    return 0;
}