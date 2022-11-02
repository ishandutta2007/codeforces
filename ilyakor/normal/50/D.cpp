#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

#define x0 x289374928
#define y0 y39801

int n;

int x[1000], y[1000];

int k;

double d[200];
double dd[200];

int x0, y0;


double calc(double r)
{
    double r2 = r * r;
    memset(d, 0, sizeof(d));
    d[0] = 1.0;
    for (int i = 0; i < n; ++i)
    {
        double t2 = sqr(x[i] - x0) + sqr(y[i] - y0);
        if (t2 <= r2) continue;
        double p = exp(1. - t2 / r2);
        if (p > 1.) p = 1.;
        memset(dd, 0, sizeof(dd));
        for (int j = 0; j <= n; ++j)
        {
            dd[j] += d[j] * p;
            dd[j + 1] += d[j] * (1. - p);
        }
        memcpy(d, dd, sizeof(dd));
    }
    double res = 0.0;
    for (int i = n - k + 1; i <= n; ++i)
        res += d[i];
    return res;
}

int main()
{
    int E;
    cin >> n >> k >> E >> x0 >> y0;
    double e = E;
    e *= 0.001;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    double down = 0.0, up = 100000.0;
    for (int it = 0; it < 100; ++it)
    {
        double r = (up + down) * 0.5;
        double p = calc(r);
        if (p < e)
            up = r;
        else
            down = r;
    }
//  cerr << calc(1000.0) << "\n";
    printf("%.10lf\n", (up + down) * 0.5);

    return 0;
}