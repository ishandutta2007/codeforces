// Hydro submission #62cd0715e4874952a0849901@1657603861828
#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 0x3f3f3f3f3f3f3f3f
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define fo(i, n) for (int i = 0; i < n; i++)
#define fod(i, n1, n2) for (int i = n1; i < n2; i++)
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;

void print(vi &array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void print_2d(vvi &array, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<double>> prob(n, vector<double>(n));

    fo(i, n)
        fo(j, n)
            cin >> prob[i][j];

    int mx = (1 << n) - 1;

    vector<double> dp(mx + 1, 0);

    dp[mx] = 1;

    for (int mask = mx - 1; mask >= 0; mask--)
    {
        int k = __builtin_popcount(mask);
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                for (int j = 0; j < n; j++)
                {
                    if(!(mask & (1<<j)))
                    dp[mask] += (2 * prob[i][j] * dp[mask + (1 << j)]) / ((k + 1) * (k)*1.0);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.12f ", dp[(1<<i)]);

    }
    cout << endl;
}