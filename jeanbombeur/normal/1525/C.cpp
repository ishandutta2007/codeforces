#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//   <|_|>

const int MAX_VALEURS = (300 * 1000);

struct robot {
    int deb, dir, id;
};

robot Robots[MAX_VALEURS];

int Pile[MAX_VALEURS][2];
int Fin[2];

int Explosion[MAX_VALEURS];

int nbRobots, murDroit;

bool operator<(robot a, robot b) {
    return a.deb < b.deb;
}

void Read() {
    scanf("%d%d", &nbRobots, &murDroit);
    for (int i = 0; i < nbRobots; i ++)
    {
        scanf("%d", &Robots[i].deb);
        Robots[i].id = i;
        Explosion[i] = -1;
    }
    scanf("\n");
    for (int i = 0; i < nbRobots; i ++)
    {
        char c;
        scanf("%c ", &c);
        if (c == 'R')
            Robots[i].dir = 1;
        else
            Robots[i].dir = -1;
    }
    sort(Robots, Robots + nbRobots);
    Fin[0] = 0;
    Fin[1] = 0;
    for (int i = 0; i < nbRobots; i ++)
    {
        int side = 0;
        if (Robots[i].deb & 1)
        {
            side = 1;
        }
        if (Robots[i].dir == 1)
        {
            Pile[Fin[side] ++][side] = i;
        }
        else
        {
            if (Fin[side] > 0)
            {
                int last = Pile[-- Fin[side]][side];
                int d = (Robots[i].deb - Robots[last].deb) / 2;
                Explosion[Robots[i].id] = d;
                Explosion[Robots[last].id] = d;
            }
            else
            {
                Robots[i].deb *= -1;
                Robots[i].dir = 1;
                Pile[Fin[side] ++][side] = i;
            }
        }
    }
    for (int side = 0; side < 2; side ++)
    {
        while (Fin[side] > 1)
        {
            int cur = Pile[-- Fin[side]][side];
            int last = Pile[-- Fin[side]][side];
            Robots[cur].deb *= -1;
            Robots[cur].deb += 2 * murDroit;
            int d = (Robots[cur].deb - Robots[last].deb) / 2;
            Explosion[Robots[cur].id] = d;
            Explosion[Robots[last].id] = d;
        }
    }
    for (int i = 0; i < nbRobots; i ++)
    {
        printf("%d ", Explosion[i]);
    }
    printf("\n");
    return;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}