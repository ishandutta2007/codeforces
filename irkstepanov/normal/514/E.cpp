#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;
ll mod = 1000000007;

const int N = 101;

matrix operator * (const matrix &a, const matrix &b)
{
    int n = sz(a);
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
    if (n == 1) return a;
    if (n % 2) return (a * pw(a, n - 1));
    matrix t = pw(a, n / 2);
    return t * t;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, x;
    cin >> n >> x;

    vector <int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    matrix base(N, vector <ll> (N));

    base[0][0] = 1;
    for (int i = 0; i < n; i++)
        ++base[0][d[i]], ++base[1][d[i]];
    for (int i = 2; i < N; i++)
        base[i][i - 1] = 1;

    vector <ll> f(N);
    f[0] = 1;

    for (int j = 1; j <= 99; j++)
        for (int i = 1; i <= j; i++)
            f[j] = (f[j] + base[1][i] * f[j - i]) % mod;

    ll sum = 0;
    for (int j = 0; j <= 99; j++)
        sum = (sum + f[j]) % mod;

    if (x <= 99)
    {
        ll ans = 0;
        for (int j = 0; j <= x; j++)
            ans = (ans + f[j]) % mod;
        cout << ans << "\n";
        return 0;
    }

    matrix m = pw(base, x - 99);

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (!i) ans = (m[0][0] * sum) % mod;
        else ans = (ans + m[0][i] * f[N - i - 1]) % mod;
    }

    cout << ans << "\n";

}