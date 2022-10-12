#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> b;
        while (k)
        {
            b.push_back(k % 2);
            k /= 2;
        }
        int ans = 0;
        int c = 1;
        //reverse(b.begin(), b.end());
        for (int i = 0; i < b.size(); i++)
        {
            ans = (ans + c * b[i]) % MOD;
            c = 1ll * c * n % MOD;
        }
        cout << ans << "\n";
    }
}