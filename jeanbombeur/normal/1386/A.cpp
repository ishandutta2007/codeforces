#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int nbTests, nbCouleurs;

//int diff;
//int last = 0;

pair <int, int> Deb[100];

int Ask(int q) {
    cout << "? " << q << endl;
    int r = 1;
    //if (max(last - q, q - last) < diff)
    //{
    //    r = 0;
    //}
    //last = q;
    //cout << r << endl;
    cin >> r;
    return r;
}

void Ans(int q) {
    cout << "= " << q << endl;
    return;
}

void SolveSmall(int nb) {
    int rep = 0;
    if (nb == 1)
    {
        Ans(1);
        return;
    }
    if (nb == 2)
    {
        rep = Ask(1);
        rep = Ask(2);
        if (rep == 1)
        {
            Ans(1);
            return;
        }
        Ans(2);
        return;
    }
    if (nb == 3)
    {
        rep = Ask(2);
        rep = Ask(3);
        if (rep == 1)
        {
            Ans(1);
            return;
        }
        rep = Ask(1);
        if (rep == 1)
        {
            Ans(2);
            return;
        }
        Ans(3);
        return;
    }
    if (nb == 4)
    {
        rep = Ask(2);
        rep = Ask(4);
        if (rep == 1)
        {
            rep = Ask(3);
            if (rep == 1)
            {
                Ans(1);
                return;
            }
            Ans(2);
            return;
        }
        rep = Ask(1);
        if (rep == 1)
        {
            Ans(3);
            return;
        }
        Ans(4);
        return;
    }
    return;
}

void SetUp(int nb, int rang) {
    int d = nb / 2;
    if (nb == 3)
    {
        Deb[rang] = make_pair(2, 1);
        return;
    }
    if (nb == 4)
    {
        Deb[rang] = make_pair(2, 1);
        return;
    }
    SetUp((nb + 1) / 2, rang + 1);
    int dir = Deb[rang + 1].second;
    if (dir == 1)
    {
        Deb[rang] = make_pair(Deb[rang + 1].first + d, -1);
    }
    if (dir == -1)
    {
        Deb[rang] = make_pair(Deb[rang + 1].first, 1);
    }
    return;
}

void SubSolve(int nb, int rang, int deb, int dec) {
    int dir = Deb[rang].second;
    int rep;
    if (nb == 3)
    {
        rep = Ask(deb + dec + 1);
        if (rep == 1)
        {
            Ans(dec + 1);
            return;
        }
        rep = Ask(deb - 1);
        if (rep == 1)
        {
            Ans(dec + 2);
            return;
        }
        Ans(dec + 3);
        return;
    }
    if (nb == 4)
    {
        rep = Ask(deb + dec + 2);
        if (rep == 1)
        {
            rep = Ask(deb + 1);
            if (rep == 1)
            {
                Ans(dec + 1);
                return;
            }
            Ans(dec + 2);
            return;
        }
        rep = Ask(deb - 1);
        if (rep == 1)
        {
            Ans(dec + 3);
            return;
        }
        Ans(dec + 4);
        return;
    }
    int d = nb / 2;
    int ndeb = deb + (d + dec) * dir;
    rep = Ask(ndeb);
    if (rep == 1)
    {
        SubSolve((nb + 1) / 2, rang + 1, ndeb, dec);
        return;
    }
    SubSolve((nb + 1) / 2, rang + 1, ndeb, dec + d);
    return;
}

void Solve(int nb) {
    SetUp(nb, 0);
    int deb = Deb[0].first;
    int rep = Ask(deb);
    rep ++;
    SubSolve(nb, 0, deb, 0);
    return;
}

void Print() {
    for (int i = 0; i < 10; i ++)
    {
        cout << Deb[i].first << " " << Deb[i].second << endl;
    }
    return;
}

void Read() {
    cin >> nbTests;
    for (int i = 0; i < nbTests; i ++)
    {
        cin >> nbCouleurs;// >> diff;
        if (nbCouleurs <= 4)
        {
            SolveSmall(nbCouleurs);
        }
        else
        {
            Solve(nbCouleurs);
        }
        //Print();
    }
    return;
}

signed main() {
    Read();
    return 0;
}