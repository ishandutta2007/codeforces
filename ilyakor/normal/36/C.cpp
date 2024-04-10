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

const int maxn = 4000;
const double eps = 1E-9;

int n;

double h[maxn], r[maxn], R[maxn];
double d[maxn];

double getFirst(double h, double r, double R, double l)
{
    if (l < r - eps)
        return 0.0;
    if (l > R + eps)
        return h;
    return h * (l - r) / (R - r);
}

double get(int i, int j)
{
    double res = 0.0;
    res = max(res, getFirst(h[j], r[j], R[j], r[i]));
    res = max(res, getFirst(h[j], r[j], R[j], R[i]) - h[i]);
    if (R[j] < R[i] + eps)
        res = max(res, h[j] - getFirst(h[i], r[i], R[i], R[j]));
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf%lf", &h[i], &r[i], &R[i]);
    d[0] = 0;
    double res = h[0];
    for (int i = 1; i < n; ++i)
    {
        d[i] = 0.0;
        for (int j = 0; j < i; ++j)
            d[i] = max(d[i], d[j] + get(i, j));
        res = max(res, d[i] + h[i]);
//      cerr << d[i] << "\n";
    }
    printf("%.10lf\n", res);
    return 0;
}