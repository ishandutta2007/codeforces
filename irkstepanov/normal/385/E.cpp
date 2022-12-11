#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define pb push_back

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;
ll mod;

matrix operator * (const matrix &a, const matrix &b)
{
    matrix ans (a.size());
    for (int i = 0; i < a.size(); i++)
    {
        ans[i].resize(b[i].size());
        for (int j = 0; j < b[i].size(); j++)
            for (int g = 0; g < b.size(); g++)
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

int main()
{

    cin >> mod;
    ll x, y, dx, dy, t;
    cin >> x >> y >> dx >> dy >> t;
    --x, --y;

    while (dx < 0) dx += mod;
    while (dy < 0) dy += mod;

    matrix a(6, vector <ll> (6));
    a[0][0] = 2; a[1][0] = 1; a[2][0] = 1; a[3][0] = 1; a[4][0] = 0; a[5][0] = 0;
    a[0][1] = 1; a[1][1] = 2; a[2][1] = 1; a[3][1] = 1; a[4][1] = 0; a[5][1] = 0;
    a[0][2] = 1; a[1][2] = 0; a[2][2] = 1; a[3][2] = 0; a[4][2] = 0; a[5][2] = 0;
    a[0][3] = 0; a[1][3] = 1; a[2][3] = 0; a[3][3] = 1; a[4][3] = 0; a[5][3] = 0;
    a[0][4] = 1; a[1][4] = 1; a[2][4] = 1; a[3][4] = 1; a[4][4] = 1; a[5][4] = 0;
    a[0][5] = 2; a[1][5] = 2; a[2][5] = 2; a[3][5] = 2; a[4][5] = 1; a[5][5] = 1;

    if (t == 0) {cout << x + 1 << " " << y + 1; return 0;}
    a = pw (a, t);

    matrix b (6, vector <ll> (1));
    b[0][0] = x;
    b[1][0] = y;
    b[2][0] = dx;
    b[3][0] = dy;
    b[4][0] = 0;
    b[5][0] = 1;

    a = a * b;
    cout << a[0][0] % mod + 1 << " " << a[1][0] % mod + 1;

}