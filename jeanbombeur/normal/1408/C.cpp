#include <iostream>
#include <cstdio>
#include <vector>
#define double long double
using namespace std;

const int MAX_NOEUDS = (1000 * 100);

int Valeurs[MAX_NOEUDS];

int nbTests, nbNoeuds, longueur;

double Tmps(double vitesse, double pos, double next) {
    return (max(next - pos, pos - next) / vitesse);
}

void Read() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        scanf("%d%d", &nbNoeuds, &longueur);
        for (int j = 0; j < nbNoeuds; j ++)
        {
            scanf("%d", &Valeurs[j]);
        }
        int gauche = -1, droite = nbNoeuds;
        double posGauche = 0.0, posDroite = (double)longueur;
        double vitGauche = 1.0, vitDroite = 1.0;
        double tmpsTot = 0.0;
        while (gauche < droite - 1)
        {
            double nxtGauche = Tmps(vitGauche, posGauche, (double)Valeurs[gauche + 1]);
            double nxtDroite = Tmps(vitDroite, posDroite, (double)Valeurs[droite - 1]);
            if (nxtGauche < nxtDroite)
            {
                tmpsTot += nxtGauche;
                posGauche = (double)Valeurs[++ gauche];
                vitGauche += 1.0;
                posDroite -= nxtGauche * vitDroite;
                //printf("G\n");
                //printf("%f\n", nxtGauche);
            }
            else
            {
                tmpsTot += nxtDroite;
                posDroite = (double)Valeurs[-- droite];
                vitDroite += 1.0;
                posGauche += nxtDroite * vitGauche;
                //printf("D\n");
                //printf("%f\n", nxtDroite);
            }
        }
        vitGauche += vitDroite;
        tmpsTot += Tmps(vitGauche, posGauche, posDroite);
        printf("%Lf\n", tmpsTot);
    }
    return;
}

int main() {
    Read();
    return 0;
}