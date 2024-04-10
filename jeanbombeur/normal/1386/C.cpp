#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_NOEUDS = (200 * 1000);

struct node {
    int pere = -1;
    int coef = 1;
};

struct mvt {
    int noeud;
    int pere;
    int coef;
};

node Dsu[MAX_NOEUDS];

mvt Pile[MAX_NOEUDS];
int fin = 0;

int Last[MAX_NOEUDS];

pair <int, int> Aretes[MAX_NOEUDS];

int nbNoeuds, nbAretes, nbJours;

void Read() {
    scanf("%d%d%d", &nbNoeuds, &nbAretes, &nbJours);
    for (int i = 0; i < nbAretes; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Aretes[i] = make_pair(-- a, -- b);
    }
    return;
}

pair <int, int> Find(int noeud, int color, int rang) {
    if (rang > 100)
    {
        printf("42666\n");
        return make_pair(-1, -1);
    }
    if (Dsu[noeud].pere < 0)
    {
        return make_pair(noeud, color * Dsu[noeud].coef);
    }
    return Find(Dsu[noeud].pere, color * Dsu[noeud].coef, rang + 1);
}

bool Union(int id) {
    int a = Aretes[id].first;
    int b = Aretes[id].second;
    pair <int, int> rA = Find(a, 1, 0);
    pair <int, int> rB = Find(b, 1, 0);
    if (rA.first == rB.first)
    {
        mvt act;
        act.noeud = -1;
        act.pere = -1;
        act.coef = 0;
        Pile[fin ++] = act;
        if (rA.second == rB.second)
        {
            return false;
        }
        return true;
    }
    int szA = Dsu[rA.first].pere;
    int szB = Dsu[rB.first].pere;
    mvt act;
    act.coef = 1;
    if (szB < szA)
    {
        act.noeud = rA.first;
        act.pere = szA;
        if (rA.second == rB.second)
        {
            Dsu[rA.first].coef *= -1;
            act.coef = -1;
        }
        Dsu[rA.first].pere = rB.first;
        Dsu[rB.first].pere += szA;
        Pile[fin ++] = act;
        return true;
    }
    act.noeud = rB.first;
    act.pere = szB;
    if (rA.second == rB.second)
    {
        Dsu[rB.first].coef *= -1;
        act.coef = -1;
    }
    Dsu[rB.first].pere = rA.first;
    Dsu[rA.first].pere += szB;
    Pile[fin ++] = act;
    return true;
}

void Undo() {
    mvt act = Pile[-- fin];
    if (act.noeud < 0)
    {
        return;
    }
    int r = Dsu[act.noeud].pere;
    Dsu[act.noeud].pere = act.pere;
    Dsu[act.noeud].coef *= act.coef;
    Dsu[r].pere -= act.pere;
    return;
}

void Treat(int l1, int l2, int r1, int r2) {
    //printf("%d %d %d %d\n", l1, l2, r1, r2);
    if (l2 < l1)
    {
        return;
    }
    int lmid = (l1 + l2) / 2;
    int rmid = max(lmid, r1);
    int c = 0;
    int d = 0;
    bool t = true;
    bool u = true;
    Last[lmid] = 0;
    for (int i = l1; i < lmid; i ++)
    {
        if (!Union(i))
        {
            t = false;
            u = false;
            rmid = r2;
            Last[lmid] = 1;
        }
        d ++;
    }
    for (int i = r2; i >= max(r1, lmid); i --)
    {
        if (u)
        {
            if (!Union(i))
            {
                u = false;
                rmid = i;
            }
            c ++;
        }
    }
    Last[lmid] += rmid;
    for (int i = 0; i < c; i ++)
    {
        Undo();
    }
    c = 0;
    if (!Union(lmid))
    {
        t = false;
    }
    d ++;
    if (t)
    {
        Treat(lmid + 1, l2, max(lmid + 1, rmid), r2);
    }
    if (!t)
    {
        for (int i = lmid + 1; i <= l2; i ++)
        {
            Last[i] = nbAretes;
        }
        //Treat(lmid + 1, l2, nbAretes, nbAretes);
    }
    for (int i = 0; i < d; i ++)
    {
        Undo();
    }
    for (int i = r2; i > rmid; i --)
    {
        t = Union(i);
        c ++;
    }
    Treat(l1, lmid - 1, r1, rmid);
    for (int i = 0; i < c; i ++)
    {
        Undo();
    }
    return;
}

void Solve() {
    Treat(0, nbAretes - 1, 0, nbAretes - 1);
    for (int i = 0; i < nbJours; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (Last[-- a] <= (-- b))
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return;
}

void Print() {
    for (int i = 0; i < nbAretes; i ++)
    {
        printf("%d\n", Last[i]);
    }
    return;
}

int main() {
    Read();
    Solve();
    //Print();
    return 0;
}