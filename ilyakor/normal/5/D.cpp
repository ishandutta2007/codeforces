#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

const double eps = 1E-8;

double get(double v0, double a, double l)
{
    double D = v0 * v0 + 2. * a * l;
    D = sqrt(D);
    double res = D - v0;
    res /= a;
    return res;
}

bool check(double vm, double a, double l, double w)
{
    double left = l;
    left -= a * sqr(vm / a) * 0.5;
    double cv = min(vm, w);
    double tmp = (vm - cv) / a;
    left -= vm * tmp - a * sqr(tmp) * 0.5;
    return left >= 0.0;
}

int main()
{
    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    w = min(w, v);
    double res = 0.0;
    double cv = 0.0;
    {
        double down = 0.0, up = v;
        for (int it = 0; it < 1000; it++)
        {
            double t = (up + down) * 0.5;
            if (check(t, a, d, w))
                down = t;
            else
                up = t;
        }
        double vm = (up + down) * 0.5;
        double left = d;
        res += vm / a;
        left -= a * sqr(vm / a) * 0.5;
        cv = min(vm, w);
        double tmp = (vm - cv) / a;
        res += tmp;
        left -= vm * tmp - a * sqr(tmp) * 0.5;
        res += left / vm;
    }
    {
        double left = l - d;
        double t_raz = (v - cv) / a;
        double t_f = get(cv, a, left);
        t_raz = min(t_raz, t_f);
        res += t_raz;
        left -= cv * t_raz + a * sqr(t_raz) * 0.5;
        res += left / v;
    }
    printf("%.10lf\n", res);
    return 0;
}