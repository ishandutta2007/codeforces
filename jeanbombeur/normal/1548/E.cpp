#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Why do we fall, sir ?

const int MAX_VALEURS = (200 * 1000 + 2);

int Tree[2 * MAX_VALEURS];

int Fenwick[MAX_VALEURS];

pair <int, int> Order[MAX_VALEURS];
pair <int, int> Inter[2 * MAX_VALEURS];

int Lignes[MAX_VALEURS];
int Colonnes[MAX_VALEURS];

int BornesLignes[MAX_VALEURS];
int BornesColonnes[MAX_VALEURS];

pair <int, int> Pile[MAX_VALEURS];
int fin = 0;

int nbLignes, nbColonnes, target;

int GetMax(int gauche, int droite, int val) {
    int ans = 0;
    for (gauche += val, droite += val; gauche < droite; gauche >>= 1, droite >>= 1)
    {
        if (gauche & 1)
            ans = max(ans, Tree[gauche ++]);
        if (droite & 1)
            ans = max(ans, Tree[-- droite]);
    }
    return ans;
}

void Add(int i) {
    int d = i & 1 ? -1 : 1;
    i >>= 1;
    for (int a = Colonnes[i]; a < MAX_VALEURS; a |= (a + 1))
        Fenwick[a] += d;
    return;
}

int GetSum(int i) {
    int ans = 0;
    for (++ i; i > 0; i &= (i - 1))
        ans += Fenwick[i - 1];
    return ans;
}

void Read() {
    scanf("%lld %lld %lld", &nbLignes, &nbColonnes, &target);
    for (int i = 1; i <= nbLignes; i ++)
    {
        scanf("%lld", &Lignes[i]);
    }
    Lignes[0] = Lignes[nbLignes + 1] = 1 << 30;
    nbLignes += 2;
    for (int i = 1; i <= nbColonnes; i ++)
    {
        scanf("%lld", &Colonnes[i]);
    }
    Colonnes[0] = Colonnes[nbColonnes + 1] = 1 << 30;
    nbColonnes += 2;
    for (int i = 0; i < nbLignes; i ++)
    {
        Tree[i + nbLignes] = Lignes[i];
        Order[i] = {Lignes[i], i};
    }
    sort(Order, Order + nbLignes);
    for (int i = nbLignes - 1; i > 0; i --)
    {
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);
    }
    Pile[fin ++] = {-1, 0};
    for (int i = 0; i < nbLignes; i ++)
    {
        while (Pile[fin - 1].first > Lignes[i])
            fin --;
        BornesLignes[i] = GetMax(Pile[fin - 1].second, i, nbLignes);
        Pile[fin ++] = {Lignes[i], i + 1};
    }
    fin = 0;
    Pile[fin ++] = {-1, nbLignes};
    for (int i = nbLignes - 1; i >= 0; i --)
    {
        while (Pile[fin - 1].first >= Lignes[i])
            fin --;
        BornesLignes[i] = min(BornesLignes[i], GetMax(i, Pile[fin - 1].second, nbLignes));
        Pile[fin ++] = {Lignes[i], i};
    }
    for (int i = 0; i < nbColonnes; i ++)
    {
        Tree[i + nbColonnes] = Colonnes[i];
    }
    for (int i = nbColonnes - 1; i > 0; i --)
    {
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);
    }
    fin = 0;
    Pile[fin ++] = {-1, 0};
    for (int i = 0; i < nbColonnes; i ++)
    {
        while (Pile[fin - 1].first > Colonnes[i])
            fin --;
        BornesColonnes[i] = GetMax(Pile[fin - 1].second, i, nbColonnes);
        Pile[fin ++] = {Colonnes[i], i + 1};
    }
    fin = 0;
    Pile[fin ++] = {-1, nbColonnes};
    for (int i = nbColonnes - 1; i >= 0; i --)
    {
        while (Pile[fin - 1].first >= Colonnes[i])
            fin --;
        BornesColonnes[i] = min(BornesColonnes[i], GetMax(i, Pile[fin - 1].second, nbColonnes));
        Pile[fin ++] = {Colonnes[i], i};
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        BornesLignes[i] = max(BornesLignes[i], Lignes[i]);
    }
    for (int i = 0; i < nbColonnes; i ++)
    {
        BornesColonnes[i] = max(BornesColonnes[i], Colonnes[i]);
        Inter[2 * i] = {target - BornesColonnes[i], 2 * i};
        Inter[2 * i + 1] = {target - Colonnes[i], 2 * i + 1};
    }
    sort(Inter, Inter + 2 * nbColonnes);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < nbLignes; i ++)
    {
        while (cur < 2 * nbColonnes && Inter[cur].first < Order[i].first)
            Add(Inter[cur ++].second);
        ans += GetSum(target - Order[i].first) - GetSum(target - BornesLignes[Order[i].second]);
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    Read();
    return 0;
}