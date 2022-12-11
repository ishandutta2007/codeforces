#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

struct pole
{
    int a[9];
};

bool operator < (pole a, pole b)
{
    for (int i = 0; i < 9; i++)
        if (a.a[i] < b.a[i]) return true;
        else if (a.a[i] > b.a[i]) return false;
    return false;
}

map <pole, int> mapa;

inline int eq (int x, int y, int z)
{
    if (x == 1 && y == 1 && z == 1) return 1;
    if (x == 2 && y == 2 && z == 2) return 2;
    return 0;
}

int win (pole p)
{
    for (int i = 0; i < 3; i++)
    {
        int e = eq(p.a[i * 3], p.a[i * 3 + 1], p.a[i * 3 + 2]);
        if (e) return  e;
    }
    for (int i = 0; i < 3; i++)
    {
        int e = eq(p.a[i], p.a[i + 3], p.a[i + 6]);
        if (e) return e;
    }
    for (int i = 0; i < 3; i += 2)
    {
        int e = eq(p.a[i], p.a[4], p.a[8 - i]);
        if (e) return e;
    }
    return 0;
}

bool draw (pole p)
{
    for (int i = 0; i < 9; i++)
        if (!p.a[i]) return false;
    return true;
}

void f (pole p, int step)
{
    for (int i = 0; i < 9; i++)
        if (!p.a[i])
    {
        pole newp;
        for (int j = 0; j < 9; j++)
            newp.a[j] = p.a[j];
        newp.a[i] = step;
        int w = win(newp);
        if (w == 1)
        {
            mapa[newp] = 3;
            continue;
        }
        if (w == 2)
        {
            mapa[newp] = 4;
            continue;
        }
        if (draw(newp))
        {
            mapa[newp] = 5;
            continue;
        }
        mapa[newp] = 3 - step;
        f (newp, 3 - step);
    }
}

int main()
{

    pole p;
    for (int i = 0; i < 9; i++)
        p.a[i] = 0;
    mapa[p] = 1;
    f (p, 1);

    for (int i = 0; i < 9; i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == 'X') p.a[i] = 1;
        else if (tmp == '0') p.a[i] = 2;
        else p.a[i] = 0;
    }

    if (mapa.count(p))
    {
        int x = mapa[p];
        if (x == 1) cout << "first";
        if (x == 2) cout << "second";
        if (x == 3) cout << "the first player won";
        if (x == 4) cout << "the second player won";
        if (x == 5) cout << "draw";
    }
    else cout << "illegal";

}