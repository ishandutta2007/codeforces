#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//   The hardest choices require the strongest wills

const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (400 * 1000 + 2);

pair <int, int> Aretes[MAX_VALEURS];
int nbAretes = 0;

bool Vu[MAX_VALEURS];

vector <int> Composantes[2];

int nbNoeuds;

void Query(int noeud) {
    printf("? %lld\n", noeud + 1);
    cout << endl;
    for (int i = 0; i < nbNoeuds; i ++)
    {
        int a;
        scanf("%lld", &a);
        if (a == 1)
            Aretes[nbAretes ++] = {noeud + 1, i + 1};
    }
    return;
}

void Read() {
    scanf("%lld", &nbNoeuds);
    printf("? 1\n");
    cout << endl;
    for (int i = 0; i < nbNoeuds; i ++)
    {
        int a;
        scanf("%lld", &a);
        if (a != 0)
            Composantes[a & 1].push_back(i);
        if (a == 1)
            Aretes[nbAretes ++] = {1, i + 1};
    }
    if (Composantes[0].size() > Composantes[1].size())
    {
        swap(Composantes[0], Composantes[1]);
        nbAretes = 0;
    }
    for (int a : Composantes[0])
    {
        Query(a);
    }
    printf("!\n");
    for (int i = 0; i < nbAretes; i ++)
    {
        printf("%lld %lld\n", Aretes[i].first, Aretes[i].second);
    }
    cout << endl;
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}