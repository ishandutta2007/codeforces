#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;

ll mod = 1000000007;

matrix umnm (const matrix & a, const matrix & b)
{
    matrix res(a.size(), vector <ll> (b[0].size()));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int g = 0; g < a.size(); g++)
                res[i][j] += (a[i][g] * b[g][j]) % mod, res[i][j] %= mod;
    return res;
}

matrix pw (matrix a, ll n)
{
    matrix res(a.size(), vector <ll> (a.size()));
    int i;
    for (i = 0; i < a.size(); i++)
        res[i][i] = 1;
    while (n)
    {
        if (n & 1ll)
            res = umnm (res, a);
        a = umnm (a, a);
        n >>= 1;
    }
    return res;
}

ll pw (ll x, int st)
{
    if (st < 0) return 0;
    ll res = 1;
    while (st--)
    {
        res = (res * x) % mod;
    }
    return res;
}

int main()
{

    ll C[100][100];
    int i, j;

    C[0][0] = 1;
    for (j = 1; j < 100; j++)
        C[0][j] = 0;

    for (i = 1; i < 100; i++)
    {
        C[i][0] = 1;
        for (j = 1; j < 100; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }

    ll n;
    int k;
    cin >> n >> k;

    matrix base(2 * k + 3, vector <ll> (2 * k + 3));
    //1

    for (i = 0; i <= k; i++)
        base[i][i + k + 1] = 1;

    for (i = k + 1; i <= 2 * k + 1; i++) // - k - 1
    {
        for (j = 0; j <= k; j++)
            base[i][j] = (C[i - k - 1][j] * pw (2, i - k - 1 - j)) % mod;
        for (j = k + 1; j <= 2 * k + 1; j++)
            base[i][j] = C[i - k - 1][j - k - 1];
    }

    base[2 * k + 2][2 * k + 1] = 1;
    base[2 * k + 2][2 * k + 2] = 1;

    base = pw (base, n - 1);

    matrix A (2 * k + 3, vector <ll> (1));
    for (i = 0; i <= k; i++)
        A[i][0] = 1;
    for (i = k + 1; i <= 2 * k + 1; i++)
        A[i][0] = pw(2, i - k);
    A[2 * k + 2][0] = 1;

    A = umnm (base, A);

    cout << A[2 * k + 2][0];

}