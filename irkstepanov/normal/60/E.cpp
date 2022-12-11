#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;

ll mod;

matrix umn_m (const matrix & a, const matrix & b)
{
    matrix ans;
    ans.resize(a.size());
    int i, j, g;
    for (i = 0; i < a.size(); i++)
    {
        ans[i].resize(b[i].size());
        for (j = 0; j < b[i].size(); j++)
        ans[i][j] = (ll) 0;
    }
    for (i = 0; i < a.size(); i++)
        for (j = 0; j < b[i].size(); j++)
            for (g = 0; g < b.size(); g++)
            ans[i][j] += (a[i][g] * b[g][j]) % mod, ans[i][j] %= mod;
    return ans;
}

matrix POW (const matrix & a, ll n)
{
    if (n == (ll) 1) return a;
    if (n % (ll) 2 == (ll) 0) {matrix t = POW (a, n / (ll) 2); return umn_m (t, t);}
    return (umn_m (a, POW (a, n - (ll) 1)));
}

int main()
{

    int n, i;
    ll x, y, an, a0, an1, c;
    cin >> n >> x >> y >> mod;
    ll sigma = (ll) 0, s = (ll) 0;

    if (n == 1) {int q; cin >> q; cout << q % mod; return 0;}

    for (i = 0; i < n; i++)
    {
        cin >> c;
        sigma += c;
        sigma %= mod;
        if (i == 0) a0 = c;
        if (i == n - 2) an1 = c;
        if (i == n - 1) an = c;
        if (i == 0 || i == n - 1) {s += c; s %= mod;}
    }

    matrix A, B;
    A.resize(2);
    B.resize(2);
    A[0].resize(2);
    A[1].resize(2);
    B[0].resize(1);
    B[1].resize(1);

    A[0][0] = 3;
    A[0][1] = -s;
    A[1][0] = 0;
    A[1][1] = 1;
    B[0][0] = sigma;
    B[1][0] = 1;

    if (x == 0) ;
    else {
    matrix C = umn_m (POW(A, x), B);
    sigma = C[0][0] % mod;}

    A[0][0] = 1;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 0;
    B[0][0] = 1;
    B[1][0] = 1;

    if (x == 0) ;
    else if (x == 1) {s += an1; s %= mod;}
    else {
    matrix D = umn_m (POW(A, x-1), B);
    s = (D[0][0] * an) % mod + (D[1][0] * an1) % mod + a0;
    s %= mod;}

    A[0][0] = 3;
    A[0][1] = -s;
    A[1][0] = 0;
    A[1][1] = 1;
    B[0][0] = sigma;
    B[1][0] = 1;

if (y == 0);
else {
    matrix C = umn_m (POW(A, y), B);
    sigma = C[0][0] % mod;}
    if (sigma < 0) sigma += mod;
    cout << sigma;

}