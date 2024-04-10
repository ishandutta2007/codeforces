#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

struct pt
{
    int x, y;
};

pt start[4], house[4];
pt p[4];

void turn (int i, int k)
{
    p[i] = start[i];
    while (k--)
    {
        int xnew = house[i].y + house[i].x - p[i].y;
        int ynew = house[i].y - house[i].x + p[i].x;
        p[i] = {xnew, ynew};
    }
}

int dist2 (pt a, pt b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool right (pt c, pt a, pt b)
{
    pt v1 = {b.x - c.x, b.y - c.y};
    pt v2 = {a.x - c.x, a.y - c.y};
    return (v1.x * v2.x + v1.y * v2.y == 0);
}

bool ok (pt a, pt b, pt c, pt d)
{
    int d1 = dist2(a, b), d2 = dist2(b, c), d3 = dist2(c, d), d4 = dist2(d, a);
    if (d1 == d2 && d1 == d3 && d1 == d4 && d1)
        return right(a, b, d) && right(b, a, c);
    else return false;
}

bool ok_square()
{
    return ok(p[0], p[2], p[1], p[3]) || ok(p[0], p[1], p[2], p[3]) || ok(p[0], p[1], p[3], p[2]);
}

int main()
{

    int n;
    cin >> n;

    while (n--)
    {
        for (int i = 0; i < 4; i++)
            cin >> start[i].x >> start[i].y >> house[i].x >> house[i].y;
        int kol = 100500;
        for (int i0 = 0; i0 < 4; i0++)
            for (int i1 = 0; i1 < 4; i1++)
            for (int i2 = 0; i2 < 4; i2++)
            for (int i3 = 0; i3 < 4; i3++)
        {
            turn(0, i0);
            turn(1, i1);
            turn(2, i2);
            turn(3, i3);
            if (ok_square()) kol = min(kol, i0 + i1 + i2 + i3);
        }
        if (kol == 100500) cout << "-1\n";
        else cout << kol << "\n";
    }

}