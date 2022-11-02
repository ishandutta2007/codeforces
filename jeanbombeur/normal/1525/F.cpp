#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//   <|_|>

const int INFINI = (1000 * 1000 * 1000);
const int MAX_SALLES = (50);

vector <int> Voisins[2 * MAX_SALLES];

int Couplage[2 * MAX_SALLES];
bool Vu[2 * MAX_SALLES];

int DP[MAX_SALLES][MAX_SALLES];

pair <int, int> Points[MAX_SALLES];

int VertexCover[MAX_SALLES];
int tailleCover = 0;

vector <int> Answer;

int nbSalles, nbTunnels, nbVagues;

void Clear() {
    for (int i = 0; i < 2 * MAX_SALLES; i ++)
    {
        Vu[i] = false;
    }
    return;
}

bool Dfs(int noeud, int pere) {
    Vu[noeud] = true;
    if (noeud >= MAX_SALLES)
    {
        if (Couplage[noeud] < 0)
        {
            Couplage[noeud] = pere;
            return true;
        }
        if (!Vu[Couplage[noeud]] && Dfs(Couplage[noeud], noeud))
        {
            Couplage[noeud] = pere;
            return true;
        }
        return false;
    }
    for (int dest : Voisins[noeud])
    {
        if (dest != pere && !Vu[dest] && Dfs(dest, noeud))
        {
            Couplage[noeud] = dest;
            return true;
        }
    }
    return false;
}

void FindVertexCover() {
    for (int i = 0; i < nbSalles; i ++)
    {
        if (Couplage[i] < 0 && Dfs(i, -1))
            Clear();
    }
    Clear();
    for (int i = 0; i < nbSalles; i ++)
    {
        if (Couplage[i] < 0)
            Dfs(i, -1);
    }
    for (int i = 0; i < nbSalles; i ++)
    {
        if (Couplage[i] >= 0 && !Vu[i])
            VertexCover[tailleCover ++] = i;
    }
    for (int i = MAX_SALLES; i < nbSalles + MAX_SALLES; i ++)
    {
        if (Couplage[i] >= 0 && Vu[i])
            VertexCover[tailleCover ++] = i;
    }
    return;
}

void SolveDP() {
    for (int i = 0; i < nbSalles; i ++)
    {
        for (int j = 0; j < nbSalles; j ++)
        {
            DP[i][j] = - INFINI;
        }
    }
    for (int i = 0; i < nbSalles - tailleCover; i ++)
    {
        DP[0][i] = 0;
    }
    for (int i = 1; i < nbSalles; i ++)
    {
        for (int j = 0; j < nbSalles; j ++)
        {
            int pts = Points[i - 1].first;
            for (int k = j; k >= i - 1; k --)
            {
                DP[i][j] = max(DP[i][j], DP[i - 1][k] + pts);
                pts = max(0LL, pts - Points[i - 1].second);
            }
        }
    }
    return;
}

void Read() {
    scanf("%lld%lld%lld", &nbSalles, &nbTunnels, &nbVagues);
    for (int i = 0; i < nbSalles; i ++)
    {
        Couplage[i] = -1;
        Couplage[i + MAX_SALLES] = -1;
    }
    for (int i = 0; i < nbTunnels; i ++)
    {
        int a, b;
        scanf("%lld%lld", &a, &b);
        b += MAX_SALLES;
        Voisins[-- a].push_back(-- b);
        Voisins[b].push_back(a);
    }
    for (int i = 0; i < nbVagues; i ++)
    {
        scanf("%lld%lld", &Points[i].first, &Points[i].second);
    }
    return;
}

void Backtrack(int salle, int nbSafe) {
    if (salle == 0)
        return;
    int pts = Points[salle - 1].first;
    for (int j = nbSafe; j >= salle - 1; j --)
    {
        if (DP[salle - 1][j] + pts == DP[salle][nbSafe])
        {
            Backtrack(salle - 1, j);
            for (int k = j; k < nbSafe; k ++)
            {
                int last = VertexCover[-- tailleCover];
                if (last >= MAX_SALLES)
                    Answer.push_back(MAX_SALLES - last - 1);
                else
                    Answer.push_back(last + 1);
            }
            Answer.push_back(0);
            return;
        }
        pts = max(0LL, pts - Points[salle - 1].second);
    }
    return;
}

void Solve() {
    Backtrack(nbVagues, nbVagues);
    printf("%lld\n", (int)Answer.size());
    for (int x : Answer)
        printf("%lld ", x);
    printf("\n");
    return;
}

signed main() {
    Read();
    FindVertexCover();
    SolveDP();
    Solve();
    return 0;
}