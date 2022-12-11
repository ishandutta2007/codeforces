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
typedef long double ld;
typedef vector <vector <ll> > matrix;
ll mod;

matrix operator * (const matrix &a, const matrix &b)
{
    int s1 = a.size(), s2 = b[0].size(), s3 = b.size();
    matrix ans(s1, vector <ll> (s2));
    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        for (int g = 0; g < s3; g++)
    {
        ans[i][j] += a[i][g] * b[g][j];
        if (ans[i][j] >= mod) ans[i][j] %= mod;
    }
    return ans;
}

matrix pw (const matrix &a, ll n)
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
    if (n % 2) return a * pw(a, n - 1);
    matrix t = pw(a, n / 2);
    return t * t;
}

int main()
{

    cin >> mod;
    ll l, r, k;
    cin >> l >> r >> k;

    ld sq = sqrt (r * 1.0) + 1;
    ll fi = (ll) sq;

    ll dmax = 0;

    for (ll d = 1; d <= fi + 100; d++)
    {
        if (r / d - (l - 1) / d >= k) dmax = max(dmax, d);
        ll dn = r / d;
        if (dn) if (r / dn - (l - 1) / dn >= k) dmax = max(dmax, dn);
    }

    matrix a(2, vector <ll> (2));
    a[0][0] = a[0][1] = a[1][0] = (1 % mod);
    a[1][1] = 0;
    a = pw(a, dmax - 1);

    cout << a[0][0] % mod;

}