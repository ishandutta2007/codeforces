#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    double a, v, l, d, w;

    cin >> a >> v >> l >> d >> w;

    double t, u;
    double vel = sqrt(2 * a * d);

    if (vel <= w || v <= w)
    {
        if (vel <= v)
        {
            u = vel;
            t = sqrt (2 * d / a);
        }
        else
        {
            t = v / a + (2 * a * d - v * v) / (2 * a * v);
            u = v;
        }
    }
    else
    {
        vel = sqrt ((2 * a * d + w * w) / 2);
        if (vel <= v)
        {
            u = w;
            t = (2 * vel - w) / a;
        }
        else
        {
            t = (2 * v - w) / a + (2 * a * d - 2 * v * v + w * w) / (2 * a * v);
            u = w;
        }
    }

    vel = sqrt (2 * a * (l - d) + u * u);
    if (vel <= v)
    {
        t += (vel - u) / a;
    }
    else
    {
        t += (v - u) / a + (2 * a *l - 2 * a * d - v * v + u * u) / (2 * a * v);
    }

    cout << fixed;
    cout.precision(10);
    cout << t;

}