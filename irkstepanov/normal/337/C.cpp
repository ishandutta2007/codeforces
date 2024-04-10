#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define pb push_back

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;
ll mod = 1000000009;

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

    ll n, m, k;
    cin >> n >> m >> k;

    ll pluss = n - (n / k);

    if (pluss >= m)
    {
        cout << m;
        return 0;
    }

    ll x = m - pluss;
    matrix a(2, vector <ll> (2));
    a[0][0] = 2;
    a[0][1] = (2 * k) % mod;
    a[1][1] = 0;
    a[1][1] = 1;

    a = pw(a, x);
    ll ans = a[0][1] + m - k * x;
    ans %= mod;

    cout << ans;

}