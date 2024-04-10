#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int fact[1000000];
int rfact[1000000];
int p[1000000];

int bin_pow(int a, ll b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }
    int res = bin_pow(a, b / 2);
    res = ((ll)res * res) % mod;
    if(b & 1)
    {
        res = ((ll)res * a) % mod;
    }
    return res;
}

int c(int n, int k)
{
    if(k > n)
    {
        return 0;
    }
    if(k < 0 || n < 0)
    {
        return 0;
    }
    int res = ((ll)fact[n] * rfact[k]) % mod;
    res = ((ll)res * rfact[n - k]) % mod;
    return res;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fact[0] = 1;
    p[0] = 1;
    for(int i = 1; i < 1000000; i++)
    {
        fact[i] = ((ll)fact[i - 1] * i) % mod;
        rfact[i] = bin_pow(fact[i], mod - 2);
        p[i] = p[i - 1] * 2 % mod;
    }
    rfact[0] = rfact[1];
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        if(k == 0)
        {
            cout << "1\n";
            continue;
        }
        int sum = 0;
        for(int i = 0; i <= n; i += 2)
        {
            sum = (sum + c(n, i)) % mod;
        }
        if(n % 2 == 0)
        {
            sum = ((ll)sum - 1 + mod) % mod;
        }
        else
        {
            sum = (sum + 1) % mod;
        }
        //cout << sum << endl;
        vector<int> dp(k);
        for(int i = 0; i < k; i++)
        {
            if(i == 0)
            {
                dp[i] = sum;
                if(n % 2 == 0)
                {
                    dp[i] = (dp[i] + 1) % mod;
                }
                continue;
            }
            int res = ((ll)sum * dp[i - 1]) % mod;
            if(n % 2 == 0)
            {
                res = (bin_pow(2, (ll)i * n) + res) % mod;
            }
            dp[i] = res;
        }
        cout << dp[k - 1] << '\n';
    }
}