#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main()
{

    int n, m;
    ll astart[100500];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> astart[i];

    vector <vector <ll> > a(n + 1, vector <ll> (105));
    vector <vector <ll> > bin(100500, vector <ll> (105));

    for (int i = 0; i < 100500; i++)
        for (int j = 0; j < 105; j++)
    {
        if (j == 0 || j == i) bin[i][j] = 1;
        else bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1]) % mod;
    }

    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        a[l][k + 1] = (a[l][k + 1] + 1) % mod;
        ll A = r - l, B = 0;
        for (int j = k + 1; j; j--)
        {
            a[r + 1][j] = (a[r + 1][j] - bin[A][B] + mod) % mod;
            ++A, ++B;
        }
    }

    for (int k = 103; k >= 0; k--)
    {
        ll sum[100500];
        sum[0] = a[0][k + 1];
        for (int i = 1; i <= n; i++)
            sum[i] = (sum[i - 1] + a[i][k + 1]) % mod;
        for (int i = 0; i <= n; i++)
            a[i][k] = (a[i][k] + sum[i]) % mod;
    }

    for (int i = 0; i < n; i++)
        cout << (a[i][0] + astart[i]) % mod << " ";

}