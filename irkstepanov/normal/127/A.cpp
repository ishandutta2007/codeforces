#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;
ll mod = 1000000007;

matrix operator * (const matrix &a, const matrix &b)
{
    int n = a.size();
    matrix ans (n, vector <ll> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            for (int g = 0; g < n; g++)
        {
            ans[i][j] = ans[i][j] + a[i][g] * b[g][j];
            if (ans[i][j] >= mod) ans[i][j] %= mod;
        }
    }
    return ans;
}

matrix pw (const matrix & a, ll n)
{
    if (n == 0)
    {
        int s = a.size();
        matrix m(s, vector <ll> (s));
        for (int i = 0; i < s; i++)
            m[i][i] = 1;
        return m;
    }
    if (n == 1) return a;
    if (n % 2) return (a * pw(a, n - 1));
    matrix t = pw(a, n / 2);
    return t * t;
}

struct pt
{
    double x, y;
};

double dist (pt a, pt b)
{
    return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{

    int n;
    double k;
    cin >> n >> k;

    pt a[120];
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;

    double s = 0;
    for (int i = 1; i < n; i++)
        s += dist(a[i], a[i + 1]);

    s *= k;
    cout << fixed;
    cout.precision(6);

    cout << s / 50.0;

}