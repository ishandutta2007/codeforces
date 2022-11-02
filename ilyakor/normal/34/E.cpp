#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const double eps = 1E-9;

double x[1000], m[1000], v[1000];
int n, t;

bool flag;

double getNext()
{
    double res = 1E100;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) continue;
            if (x[i] < x[j] - eps) continue;
            if (abs(x[i] - x[j]) < eps) continue;
            double dist = x[i] - x[j];
            double V = v[j] - v[i];
            if (V < eps) continue;
            res = min(res, dist / V);
        }
    }
    return res;
}

void add(double t)
{
    for (int i = 0; i < n; ++i)
        x[i] += v[i] * t;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (i == j) continue;
            if (abs(x[i] - x[j]) > eps) continue;
            double VI = ((m[i] - m[j]) * v[i] + 2 * m[j] * v[j]) / (m[i] + m[j]);
            double VJ = ((m[j] - m[i]) * v[j] + 2 * m[i] * v[i]) / (m[i] + m[j]);
            v[i] = VI, v[j] = VJ;
        }
    }
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> v[i] >> m[i];
    double cur = 0.0;
    flag = true;
    int cnt = 0;
    while (1)
    {
        double tmp = getNext();
        if (cur + tmp > t - eps)
        {
            add(t - cur);
            break;
        }
        add(tmp);
        if (abs(tmp) < eps)
            cnt++;
        else
            cnt = 0;
        if (cnt >= 2)
        {
            add(eps);
            cnt = 0;
        }
        cur += tmp;
    }
    for (int i = 0; i < n; ++i)
        printf("%.12lf\n", x[i]);
    return 0;
}