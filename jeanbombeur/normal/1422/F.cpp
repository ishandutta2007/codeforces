#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEUR = (200 * 1000 + 1);
const int HAUTEUR = 17;
const int TAILLE_ARBRE = (1 << HAUTEUR);
const int NB_PREMIERS = 86;

int Tree_Inf[2 * TAILLE_ARBRE][NB_PREMIERS];
vector <pair <int, int>> Tree_Sup[2 * TAILLE_ARBRE][2];

bool Premier[MAX_VALEUR];

vector <int> PremiersInf;

int MaxIntervalle[NB_PREMIERS];

int Prev[MAX_VALEUR];

int nbValeurs, nbRequetes;

int ExpRapide(int a, int n) {
    if (n <= 0)
    {
        return 1;
    }
    int ans = ExpRapide(a, n / 2);
    ans *= ans;
    ans %= MOD;
    if (n % 2 == 1)
    {
        return (ans * a) % MOD;
    }
    return ans % MOD;
}

void FindPremiers() {
    for (int i = 2; i < MAX_VALEUR; i ++)
    {
        Premier[i] = true;
    }
    for (int i = 2; i < MAX_VALEUR; i ++)
    {
        if (Premier[i])
        {
            for (int j = 2 * i; j < MAX_VALEUR; j += i)
            {
                Premier[j] = false;
            }
            if (i * i < MAX_VALEUR)
            {
                PremiersInf.push_back(i);
            }
            else
            {
                //printf("%lld ", i);
            }
        }
    }
    //printf("\n");
    return;
}

void InitTree() {
    for (int i = TAILLE_ARBRE - 1; i > 0; i --)
    {
        for (int j = 0; j < NB_PREMIERS; j ++)
        {
            Tree_Inf[i][j] = max(Tree_Inf[2 * i][j], Tree_Inf[2 * i + 1][j]);
        }
    }
    for (int i = TAILLE_ARBRE - 1; i > 0; i --)
    {
        vector <pair <int, int>> nv;
        for (pair <int, int> d : Tree_Sup[2 * i][0])
        {
            nv.push_back(d);
        }
        for (pair <int, int> d : Tree_Sup[2 * i + 1][0])
        {
            nv.push_back(d);
        }
        sort(nv.begin(), nv.end());
        vector <pair <int, int>> nouv;
        for (int j = 0; j < (int)nv.size(); j ++)
        {
            if (j == 0 || nv[j].first != nv[j - 1].first)
            {
                nouv.push_back(nv[j]);
            }
        }
        Tree_Sup[i][0] = nouv;
    }
    return;
}

void SortTree() {
    for (int i = 2 * TAILLE_ARBRE - 1; i > 0; i --)
    {
        vector <pair <int, int>> nv;
        for (pair <int, int> d : Tree_Sup[i][0])
        {
            nv.push_back(make_pair(d.second, d.first));
        }
        sort(nv.begin(), nv.end());
        Tree_Sup[i][0] = nv;
        vector <pair <int, int>> nouv;
        int tot = 1;
        for (int j = 0; j < (int)nv.size(); j ++)
        {
            tot *= nv[j].second;
            tot %= MOD;
            nouv.push_back(make_pair(tot, 42));
        }
        Tree_Sup[i][1] = nouv;
    }
    return;
}

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        int a;
        scanf("%lld", &a);
        for (int j = 0; j < NB_PREMIERS; j ++)
        {
            while (a % PremiersInf[j] == 0)
            {
                a /= PremiersInf[j];
                Tree_Inf[i + TAILLE_ARBRE][j] ++;
            }
        }
        vector <pair <int, int>> nouv;
        if (a > 1)
        {
            //printf("%lld\n", a);
            nouv.push_back(make_pair(a, Prev[a]));
            Prev[a] = i + TAILLE_ARBRE;
        }
        Tree_Sup[TAILLE_ARBRE + i][0] = nouv;
    }
    scanf("%lld", &nbRequetes);
    return;
}

int Clear() {
    int prod = 1;
    for (int i = 0; i < NB_PREMIERS; i ++)
    {
        prod *= ExpRapide(PremiersInf[i], MaxIntervalle[i]);
        prod %= MOD;
        MaxIntervalle[i] = 0;
    }
    return prod;
}

void MaxPetits(int gauche, int droite) {
    if (gauche > droite)
    {
        return;
    }
    if (gauche % 2 == 1)
    {
        for (int i = 0; i < NB_PREMIERS; i ++)
        {
            MaxIntervalle[i] = max(MaxIntervalle[i], Tree_Inf[gauche][i]);
        }
        MaxPetits(gauche + 1, droite);
        return;
    }
    if (droite % 2 == 0)
    {
        for (int i = 0; i < NB_PREMIERS; i ++)
        {
            MaxIntervalle[i] = max(MaxIntervalle[i], Tree_Inf[droite][i]);
        }
        MaxPetits(gauche, droite - 1);
        return;
    }
    MaxPetits(gauche / 2, droite / 2);
    return;
}

int Dicho(int noeud, int borne) {
    int gauche = -1;
    int droite = (int)Tree_Sup[noeud][0].size() - 1;
    int milieu = (gauche + droite + 1) / 2;
    while (gauche < droite)
    {
        if (Tree_Sup[noeud][0][milieu].first >= borne)
        {
            droite = milieu - 1;
        }
        else
        {
            gauche = milieu;
        }
        milieu = (droite + gauche + 1) / 2;
    }
    if (gauche < 0)
    {
        return 1;
    }
    return Tree_Sup[noeud][1][milieu].first;
}

int ProdSurIntervalle(int gauche, int droite, int borne) {
    if (gauche > droite)
    {
        return 1;
    }
    if (gauche % 2 == 1)
    {
        return Dicho(gauche, borne) * ProdSurIntervalle(gauche + 1, droite, borne) % MOD;
    }
    if (droite % 2 == 0)
    {
        return Dicho(droite, borne) * ProdSurIntervalle(gauche, droite - 1, borne) % MOD;
    }
    return ProdSurIntervalle(gauche / 2, droite / 2, borne) % MOD;
}

void PRINT(int noeud, int prof) {
    if (noeud >= 2 * TAILLE_ARBRE)
    {
        return;
    }
    PRINT(2 * noeud + 1, prof + 1);
    for (int i = 0; i < prof; i ++)
    {
        printf("\t");
    }
    for (pair <int, int> d : Tree_Sup[noeud][0])
    {
        printf("%lld %lld  ", d.first, d.second);
    }
    for (int j = 0; j < NB_PREMIERS; j ++)
    {
        //printf("%lld ", Tree_Inf[noeud][j]);
    }
    printf("\n");
    PRINT(2 * noeud, prof + 1);
    return;
}

void Solve() {
    int last = 0;
    for (int i = 0; i < nbRequetes; i ++)
    {
        int gauche, droite;
        scanf("%lld%lld", &gauche, &droite);
        gauche = (gauche + last) % nbValeurs;
        droite = (droite + last) % nbValeurs;
        gauche += TAILLE_ARBRE;
        droite += TAILLE_ARBRE;
        int ans = 1;
        MaxPetits(min(gauche, droite), max(gauche, droite));
        ans *= Clear();
        ans *= ProdSurIntervalle(min(gauche, droite), max(gauche, droite), min(gauche, droite));
        ans %= MOD;
        printf("%lld\n", ans);
        last = ans % nbValeurs;
    }
    return;
}

signed main() {
    FindPremiers();
    Read();
    InitTree();
    SortTree();
    //PRINT(1, 0);
    Solve();
    return 0;
}