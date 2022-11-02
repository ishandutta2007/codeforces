#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_LONGUEUR = (100 * 1000 + 1);

struct node {
    int taille;
    char last, cur;
    char Derniers[10];
    char Premiers[5];
};

node DP[MAX_LONGUEUR];

char Entree[MAX_LONGUEUR];

int longueur;

void Read() {
    scanf("%s", Entree);
    longueur = 0;
    while (Entree[longueur] >= 'a' && Entree[longueur] <= 'z')
    {
        longueur ++;
    }
    return;
}

void Copy(int noeud, int alt, int d) {
    for (int i = 0; i < min(DP[noeud].taille, 10); i ++)
    {
        DP[noeud].Derniers[i] = DP[alt].Derniers[i];
    }
    for (int i = d; i < 5; i ++)
    {
        DP[noeud].Premiers[i] = DP[alt].Premiers[i - d];
    }
    return;
}

void Treat(int noeud) {
    if (Entree[noeud] != Entree[noeud + 1] || (DP[noeud + 1].last > Entree[noeud]))
    {
        DP[noeud].taille = DP[noeud + 1].taille + 1;
        Copy(noeud, noeud + 1, 1);
        if (DP[noeud].taille <= 10)
        {
            DP[noeud].Derniers[DP[noeud].taille - 1] = Entree[noeud];
            for (int i = 0; i < min(DP[noeud].taille, 5); i ++)
            {
                DP[noeud].Premiers[i] = DP[noeud].Derniers[DP[noeud].taille - i - 1];
            }
        }
        else
        {
            DP[noeud].Premiers[0] = Entree[noeud];
        }
        DP[noeud].cur = Entree[noeud];
        DP[noeud].last = DP[noeud + 1].last;
        if (Entree[noeud] != DP[noeud + 1].cur)
        {
            DP[noeud].last = DP[noeud + 1].cur;
        }
        return;
    }
    DP[noeud].taille = DP[noeud + 2].taille;
    Copy(noeud, noeud + 2, 0);
    DP[noeud].cur = DP[noeud + 2].cur;
    DP[noeud].last = DP[noeud + 2].last;
    return;
}

void Solve() {
    DP[longueur].taille = 0;
    DP[longueur].cur = 'A';
    DP[longueur].last = 'A';
    DP[longueur - 1].taille = 1;
    DP[longueur - 1].cur = Entree[longueur - 1];
    DP[longueur - 1].last = Entree[longueur - 1];
    DP[longueur - 1].Derniers[0] = Entree[longueur - 1];
    for (int i = longueur - 2; i >= 0; i --)
    {
        Treat(i);
    }
    for (int i = 0; i < longueur; i ++)
    {
        printf("%d ", DP[i].taille);
        //printf("%c %c ", DP[i].cur, DP[i].last);
        if (DP[i].taille <= 10)
        {
            for (int j = 0; j < DP[i].taille; j ++)
            {
                printf("%c", DP[i].Derniers[DP[i].taille - j - 1]);
            }
            printf("\n");
        }
        else
        {
            for (int j = 0; j < 5; j ++)
            {
                printf("%c", DP[i].Premiers[j]);
            }
            printf("...");
            printf("%c%c\n", DP[i].Derniers[1], DP[i].Derniers[0]);
        }
    }
    return;
}

int main() {
    Read();
    Solve();
    return 0;
}