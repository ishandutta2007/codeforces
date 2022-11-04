#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;


int bin_pow(int a, int b)
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
    if(b % 2 == 1)
    {
        res = ((ll)res * a) % mod;
    }
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
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int up = 1;
    for(int i = 2; i <= 2 * n; i++)
    {
        up = ((ll)up * i) % mod;
    }
    int down = 1;
    for(int i = 2; i <= n; i++)
    {
        down = ((ll)down * i) % mod;
    }
    down = ((ll)down * down) % mod;
    int ans1 = ((ll)up * bin_pow(down, mod - 2)) % mod;
    int ans = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        if(i >= n)
        {
            ans = ((ll)ans1 * a[i] + ans) % mod;
        }
        else
        {
            int ans2 = ((ll)ans1 * a[i]) % mod;
            ans = ((ll)ans - ans2 + mod) % mod;
        }
    }
    cout << ans;
}