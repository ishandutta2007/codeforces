#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Petit coup de chance

const int MAX_NOEUDS = (1000 * 1000);

struct arete {
    int dep, fin, cout;
    bool ans;
};

vector <pair <int, int>> Voisins[MAX_NOEUDS];
int Pere[MAX_NOEUDS];
int Couleur[MAX_NOEUDS];
int Order[MAX_NOEUDS];

int Tree[2 * MAX_NOEUDS];
int Fenwick[2 * MAX_NOEUDS];
int Dsu[MAX_NOEUDS];
int In[MAX_NOEUDS];
int Out[MAX_NOEUDS];

arete Aretes[MAX_NOEUDS];

int cnt, num;

int nbNoeuds, nbRequetes;

int GetMin(int gauche, int droite) {
    int ans = 1 << 30;
    for (; gauche < droite; gauche >>= 1, droite >>= 1)
    {
        if (gauche & 1)
            ans = min(ans, Tree[gauche ++]);
        if (droite & 1)
            ans = min(ans, Tree[-- droite]);
    }
    return ans;
}

void Add(int a, int d) {
    for (int i = a; i < 2 * MAX_NOEUDS; i |= (i + 1))
        Fenwick[i] += d;
    return;
}

int GetSum(int a) {
    int ans = 0;
    for (int i = ++ a; i > 0; i &= (i - 1))
        ans += Fenwick[i - 1];
    return ans;
}

int Find(int noeud) {
    if (Dsu[noeud] < 0)
        return noeud;
    return Dsu[noeud] = Find(Dsu[noeud]);
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

void EulerTour(int noeud, int pere, int color) {
    int curNum = num ++;
    Order[curNum] = noeud;
    In[noeud] = cnt;
    Tree[cnt ++] = curNum;
    Pere[noeud] = pere;
    Couleur[noeud] = color;
    for (pair <int, int> dest : Voisins[noeud])
    {
        if (dest.first != pere)
        {
            EulerTour(dest.first, noeud, color ^ dest.second);
            Tree[cnt ++] = curNum;
        }
    }
    Out[noeud] = cnt;
    return;
}

void Read() {
    scanf("%lld %lld", &nbNoeuds, &nbRequetes);
    fill_n(Dsu, nbNoeuds, -1);
    for (int i = 0; i < nbRequetes; i ++)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        Aretes[i] = {-- a, -- b, c, false};
        if (Union(a, b))
        {
            Aretes[i].ans = true;
            Voisins[a].push_back({b, c});
            Voisins[b].push_back({a, c});
        }
    }
    cnt = MAX_NOEUDS, num = 0;
    for (int i = 0; i < nbNoeuds; i ++)
    {
        if (In[i] == 0)
            EulerTour(i, -1, 0);
    }
    
    for (int i = MAX_NOEUDS - 1; i > 0; i --)
    {
        Tree[i] = min(Tree[2 * i], Tree[2 * i + 1]);
    }
    
    for (int i = 0; i < nbRequetes; i ++)
    {
        if (!Aretes[i].ans && (Couleur[Aretes[i].dep] ^ Couleur[Aretes[i].fin] ^ Aretes[i].cout) == 1)
        {
            int a = Aretes[i].dep, b = Aretes[i].fin;
            if (In[a] > In[b])
                swap(a, b);
            int lca = Order[GetMin(In[a], Out[b])];
            if (GetSum(In[a]) + GetSum(In[b]) - 2 * GetSum(In[lca]) == 0)
            {
                while (a != lca)
                {
                    Add(In[a], 1);
                    Add(Out[a], -1);
                    a = Pere[a];
                }
                while (b != lca)
                {
                    Add(In[b], 1);
                    Add(Out[b], -1);
                    b = Pere[b];
                }
                Aretes[i].ans = true;
            }
        }
    }
    
    for (int i = 0; i < nbRequetes; i ++)
    {
        if (Aretes[i].ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return;
}

signed main() {
    Read();
    return 0;
}