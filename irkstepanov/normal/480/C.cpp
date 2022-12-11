#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    if (a < b) {n = b; --a, --b;}
    else {n = n - b + 1; a = n - (a - b); b = n; --a, --b;}

    vector <vector <ll> > dp(n, vector <ll> (k + 1, 0));
    dp[a][0] = 1;

    vector <ll> sum(n);
    sum[0] = dp[0][0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + dp[i][0];

    for (int step = 1; step <= k; step++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int s = n - 1 + i;
            if (s % 2 == 0) s = (s / 2) - 1;
            else s /= 2;
            dp[i][step] = sum[s] - dp[i][step - 1];
            if (dp[i][step] < 0) dp[i][step] += mod;
        }
        sum[0] = dp[0][step] % mod;
        for (int i = 1; i < n; i++)
            sum[i] = (sum[i - 1] + dp[i][step]) % mod;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans = (ans + dp[i][k]) % mod;

    cout << ans << "\n";

}

//pitri doooooooooor