#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NOEUDS = (100 * 1000);

struct ratio {
    int num, denom;
};

vector <pair <int, int>> Voisins[MAX_NOEUDS];

int Couleur[MAX_NOEUDS];
ratio Valeur[MAX_NOEUDS];
int Vu[MAX_NOEUDS];

ratio diff = {0, 1};

vector <int> IndicesActuels;

int nbNoeuds, nbAretes;

int Pgcd(int a, int b) {
    if (b == 0)
    {
        return a;
    }
    return Pgcd(b, a % b);
}

ratio Simp(ratio a) {
    if (a.denom < 0)
    {
        a.num *= -1;
        a.denom *= -1;
    }
    int d = Pgcd(max(a.num, - a.num), a.denom);
    return {a.num / d, a.denom / d};
}

ratio operator-(ratio a, ratio b) {
    return Simp({a.num * b.denom - a.denom * b.num, a.denom * b.denom});
}

bool operator<(ratio a, ratio b) {
    return a.num * b.denom < a.denom * b.num;
}

bool operator!=(ratio a, ratio b) {
    return a.num != b.num || a.denom != b.denom;
}

void Read() {
    scanf("%d%d", &nbNoeuds, &nbAretes);
    for (int i = 0; i < nbAretes; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Voisins[-- a].push_back(make_pair(-- b, c));
        Voisins[b].push_back(make_pair(a, c));
    }
    return;
}

bool Transmet(int noeud, int val) {
    //printf("%d %d %d\n", noeud, Valeur[noeud].num, Valeur[noeud].denom);
    for (pair <int, int> dest : Voisins[noeud])
    {
        //printf(":%d %d %d\n", noeud, dest.first, dest.second);
        if (Vu[dest.first] == val)
        {
            if (val == 1 && Couleur[dest.first] == Couleur[noeud])
            {
                ratio sum = {dest.second, 1};
                diff = sum - Valeur[noeud] - Valeur[dest.first];
                diff.denom *= 2;
                if (Couleur[noeud] == 0)
                {
                    diff.num *= -1;
                }
                return true;
            }
            if (val == 2)
            {
                ratio x = {dest.second, 1};
                if (Valeur[noeud] != x - Valeur[dest.first])
                {
                    return true;
                }
            }
        }
        if (Vu[dest.first] < val)
        {
            if (val == 1)
            {
                IndicesActuels.push_back(dest.first);
            }
            ratio x = {dest.second, 1};
            Valeur[dest.first] = x - Valeur[noeud];
            Couleur[dest.first] = 1 - Couleur[noeud];
            Vu[dest.first] = val;
            if (Transmet(dest.first, val))
            {
                return true;
            }
        }
    }
    return false;
}

void Ajuste(vector <int> Indices) {
    vector <ratio> Valeurs;
    for (int i : Indices)
    {
        //printf("%d ", i);
        if (Couleur[i] == 1)
        {
            Valeur[i].num *= -1;
        }
        Valeurs.push_back(Valeur[i]);
    }
    //for (ratio a : Valeurs)
    //{
        //printf("%d %d :: ", a.num, a.denom);
    //}
    sort(Valeurs.begin(), Valeurs.end());
    ratio milieu = Valeurs[(int)Indices.size() / 2];
    for (int i : Indices)
    {
        Valeur[i] = Valeur[i] - milieu;
        if (Couleur[i] == 1)
        {
            Valeur[i].num *= -1;
        }
    }
    return;
}

void Solve() {
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (Vu[i] == 0)
        {
            IndicesActuels.clear();
            IndicesActuels.push_back(i);
            Valeur[i] = {0, 1};
            Vu[i] = 1;
            bool t = Transmet(i, 1);
            Valeur[i] = Valeur[i] - diff;
            //printf("%d %d\n", Valeur[i].num, Valeur[i].denom);
            Vu[i] = 2;
            if (Transmet(i, 2))
            {
                printf("NO\n");
                return;
            }
            if (!t)
            {
                Ajuste(IndicesActuels);
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < nbNoeuds; i ++)
    {
        printf("%f ", ((double)Valeur[i].num / (double)Valeur[i].denom));
    }
    printf("\n");
    return;
}

int main() {
    Read();
    Solve();
    return 0;
}