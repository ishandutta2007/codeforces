#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

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

int main()
{

    long long n;
    cin >> n;

    int m, k;
    cin >> m >> k;

    matrix a(m, vector <ll> (m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        a[i][j] = 1;

    for (int i = 0; i < k; i++)
    {
        char x, y;
        cin >> x >> y;
        int x1, y1;
        if (x >= 'a' && x <= 'z') x1 = x - 'a';
        else x1 = x - 'A' + 26;
        if (y >= 'a' && y <= 'z') y1 = y - 'a';
        else y1 = y - 'A' + 26;
        a[x1][y1] = 0;
    }

    matrix c = pw(a, n - 1);
    ll otv = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
    {
        otv = otv + c[i][j];
        if (otv >= mod) otv %= mod;
    }

    cout << otv;

}