#include <bits/stdc++.h>

using namespace std;

const int N = 110 * 111;

bitset<N> dp[N];

void solve()
{
    int x;
    cin >> x;
    if (x >= N) cout << "YES\n";
    else cout << (dp[x] == 1 ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        if (dp[i] == 1)
        {
            if (i + 11 < N) dp[i + 11] = 1;
            if (i + 111 < N) dp[i + 111] = 1;
            if (i + 1111 < N) dp[i + 1111] = 1;
            if (i + 11111 < N) dp[i + 11111] = 1;
        }
    }
    
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}