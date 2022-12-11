#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;
const int N = 100500;

int main()
{

    //ifstream cin ("input.txt");
    //ofstream cout("output.txt");

    vector <ll> dp(N, 1);
    int t, k;

    cin >> t >> k;

    for (int x = k; x < N; x++)
        dp[x] = (dp[x - 1] + dp[x - k]) % mod;

    vector <ll> sum(N);
    sum[0] = dp[0];

    for (int x = 1; x < N; x++)
        sum[x] = (sum[x - 1] + dp[x]) % mod;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        ll ans = sum[b] - sum[a - 1];
        if (ans < 0) ans += mod;
        cout << ans << "\n";
    }

}