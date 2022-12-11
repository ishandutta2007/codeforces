#include <bits/stdc++.h>

#define mp std::make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

int max(int a, int b)
{
    return (a > b ? a : b);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

typedef long long ll;
typedef long double ld;
typedef std::vector <int> vi;

const ll mod = 1000000007ll;
int nmax = 4010;

int main()
{

    int n;
    std::cin >> n;

    std::vector <std::vector <int> > bin(nmax, std::vector <int> (nmax));
    bin[0][0] = 1;

    for (int i = 1; i < nmax; i++)
    {
        bin[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            ll x = (ll) bin[i - 1][j - 1] + (ll) bin[i - 1][j];
            if (x >= mod) x -= mod;
            bin[i][j] = (int) x;
        }
    }

    std::vector <ll> ans(n + 1), total(n + 1);
    ans[0] = 0;
    ans[1] = 1;
    total[0] = 1;
    total[1] = 2;

    for (int i = 2; i <= n; i++)
    {
        total[i] = total[i - 1] + total[i - 1];
        if (total[i] >= mod) total[i] -= mod;
        for (int k = 2; k <= i; k++)
            total[i] = (total[i] + (ll) bin[i - 1][k - 1] * total[i - k]) % mod;
        ans[i] = total[i - 1] + ans[i - 1];
        if (ans[i] >= mod) ans[i] -= mod;
        for (int k = 2; k < i; k++)
            ans[i] = (ans[i] + (ll) bin[i - 1][k - 1] * ans[i - k]) % mod;
    }

    std::cout << ans[n] << "\n";

}