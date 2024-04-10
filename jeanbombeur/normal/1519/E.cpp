#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define int long long
using namespace std;

//   <|_|>

const int MAX_VALEURS = (400 * 1000 + 1);

vector <int> Voisins[MAX_VALEURS];

int Moves[MAX_VALEURS][2];

map <pair <int, int>, int> Pentes;
int nbPentes = 1;

bool VuPente[MAX_VALEURS];
bool VuPoint[MAX_VALEURS];

pair <int, int> Ans[MAX_VALEURS];
int nbPaires = 0;

int nbPoints;

int Pgcd(int a, int b) {
    if (b == 0)
        return a;
    return Pgcd(b, a % b);
}

pair <int, int> Simp(int a, int b) {
    int d = Pgcd(a, b);
    return {a / d, b / d};
}

int GetId(pair <int, int> a) {
    if (Pentes[a] == 0)
        Pentes[a] = nbPentes ++;
    return Pentes[a];
}

bool Dfs(int a, int pere) {
    VuPente[a] = true;
    int last = -1;
    for (int dest : Voisins[a])
    {
        if (dest != pere && !VuPoint[dest])
        {
            VuPoint[dest] = true;
            int next = Moves[dest][0] ^ Moves[dest][1] ^ a;
            if (VuPente[next] || !Dfs(next, dest))
            {
                if (last < 0)
                {
                    last = dest;
                }
                else
                {
                    Ans[nbPaires ++] = {last, dest};
                    last = -1;
                }
            }
        }
    }
    if (last >= 0 && pere >= 0)
    {
        Ans[nbPaires ++] = {last, pere};
        return true;
    }
    return false;
}

void Read() {
    scanf("%lld", &nbPoints);
    for (int i = 0; i < nbPoints; i ++)
    {
        int a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        pair <int, int> x, y;
        x = Simp((a + b) * d, b * c);
        y = Simp(a * d, b * (c + d));
        int idX = GetId(x), idY = GetId(y);
        Moves[i][0] = idX;
        Moves[i][1] = idY;
        Voisins[idX].push_back(i);
        Voisins[idY].push_back(i);
    }
    for (int i = 1; i < nbPentes; i ++)
    {
        if (!VuPente[i])
        {
            Dfs(i, -1);
        }
    }
    printf("%lld\n", nbPaires);
    for (int i = 0; i < nbPaires; i ++)
    {
        printf("%lld %lld\n", Ans[i].first + 1, Ans[i].second + 1);
    }
    return;
}

signed main() {
    Read();
    return 0;
}