#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//   The hardest choices require the strongest wills

const int INFINI = (1000 * 1000 * 1000);
const int MAX_VALEURS = (501);

bool Pris[MAX_VALEURS];

bool Atteint[MAX_VALEURS];

int Pere[MAX_VALEURS];

pair <int, int> File[MAX_VALEURS];
int deb = 0, fin = 0;

int nbValeurs, longueur;

int Query(int nbNouv) {
    printf("? ");
    int a = 0, b = 0;
    int nbPris = longueur - nbNouv;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (a < nbPris && Pris[i])
        {
            Pris[i] ^= 1;
            printf("%lld ", i + 1);
            a ++;
        }
        else if (b < nbNouv && !Pris[i])
        {
            Pris[i] ^= 1;
            printf("%lld ", i + 1);
            b ++;
        }
    }
    cout << endl;
    scanf("%lld", &a);
    return a;
}

void Add(int val, int id) {
    for (int k = 0; k <= longueur; k ++)
    {
        if (k <= min(val, longueur) && longueur - k <= nbValeurs - val)
        {
            if (!Atteint[val + longueur - 2 * k])
            {
                Atteint[val + longueur - 2 * k] ^= 1;
                File[fin ++] = {val + longueur - 2 * k, id};
            }
        }
    }
    return;
}

int Bfs() {
    int ans = 0;
    File[fin ++] = {nbValeurs, nbValeurs};
    Atteint[nbValeurs] = 1;
    while (deb < fin)
    {
        Add(File[deb].first, deb);
        deb ++;
    }
    int cur = 0;
    for (int i = 0; i < fin; i ++)
    {
        // printf("%lld %lld\n", File[i].first, File[i].second);
        if (File[i].first == 0)
            cur = i;
    }
    // return ans;
    while (File[cur].first != nbValeurs)
    {
        int pere = File[cur].second;
        int k = (File[pere].first + longueur - File[cur].first) / 2;
        ans ^= Query(k);
        cur = pere;
    }
    return ans;
}

void Read() {
    scanf("%lld %lld", &nbValeurs, &longueur);
    if ((nbValeurs & 1) && !(longueur & 1))
    {
        printf("-1");
        cout << endl;
        return;
    }
    printf("! %lld", Bfs());
    cout << endl;
    return;
}

signed main() {
    Read();
    return 0;
}