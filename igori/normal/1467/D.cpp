#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int> > ways(k + 1, vector<int>(n));
    ways[0] = vector<int>(n, 1);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j - 1 >= 0) ways[i][j] = (ways[i][j] + ways[i - 1][j - 1]) % MOD;
            if (j + 1 < n) ways[i][j] = (ways[i][j] + ways[i - 1][j + 1]) % MOD;
        }
    }
    vector<int> w(n);
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            w[j] = (w[j] + 1ll * ways[i][j] * ways[k - i][j]) % MOD;
        }
    }
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot = (tot + 1ll * a[i] * w[i]) % MOD;
        //cout << w[i] << " ";
    }
    //cout << "\n";
    while (q--)
    {
        int i, x;
        cin >> i >> x;
        i--;
        tot = (tot - 1ll * a[i] * w[i]) % MOD;
        a[i] = x;
        tot = (tot + 1ll * a[i] * w[i]) % MOD;
        tot = (tot + MOD) % MOD;
        cout << tot << "\n";
    }
}