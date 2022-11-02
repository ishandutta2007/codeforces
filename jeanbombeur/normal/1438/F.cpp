#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

const int MAX_VALEURS = (1 << 18);
const int MLG = 420;

int Occ[MAX_VALEURS];

int nbValeurs, hauteur;

void Read() {
    srand(MLG);
    scanf("%d", &hauteur);
    nbValeurs = (1 << hauteur) - 1;
    for (int i = 0; i < MLG; i ++)
    {
        int a = rand() % nbValeurs;
        int b = rand() % nbValeurs;
        int c = rand() % nbValeurs;
        if (b == a)
        {
            b ++;
            b %= nbValeurs;
        }
        if (c == a)
        {
            c ++;
            c %= nbValeurs;
        }
        if (c == b)
        {
            c ++;
            c %= nbValeurs;
        }
        if (c == a)
        {
            c ++;
            c %= nbValeurs;
        }
        printf("? %d %d %d\n", a + 1, b + 1, c + 1);
        cout << endl;
        int ans;
        scanf("%d", &ans);
        Occ[ans] ++;
    }
    int a, b;
    int maximum = 0;
    int win = 0;
    for (int i = 1; i <= nbValeurs; i ++)
    {
        if (Occ[i] > maximum)
        {
            maximum = Occ[i];
            win = i;
        }
    }
    a = win;
    Occ[win] = 0;
    maximum = 0;
    for (int i = 1; i <= nbValeurs; i ++)
    {
        if (Occ[i] > maximum)
        {
            maximum = Occ[i];
            win = i;
        }
    }
    b = win;
    for (int i = 1; i <= nbValeurs; i ++)
    {
        if (i != a && i != b)
        {
            printf("? %d %d %d\n", a, b, i);
            cout << endl;
            int ans;
            scanf("%d", &ans);
            if (ans == i)
            {
                printf("! %d\n", i);
                cout << endl;
                return;
            }
        }
    }
    return;
}

int main() {
    Read();
    return 0;
}