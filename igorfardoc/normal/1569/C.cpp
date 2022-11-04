#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int fact[500000];
int rfact[500000];

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
    if(b & 1)
    {
        res = ((ll)res * a) % mod;
    }
    return res;
}

int c(int n, int k)
{
    if(k > n || k < 0 || n < 0)
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
    for(int i = 1; i < 500000; i++)
    {
        fact[i] = ((ll)fact[i - 1] * i) % mod;
        rfact[i] = bin_pow(fact[i], mod - 2);
    }
    rfact[0] = rfact[1];
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int max1 = -1;
        int amountmax = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] > max1)
            {
                max1 = a[i];
                amountmax = 1;
            }
            else if(a[i] == max1)
            {
                ++amountmax;
            }
        }
        if(amountmax > 1)
        {
            cout << fact[n] << '\n';
            continue;
        }
        int max2 = -1;
        amountmax = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == max1)
            {
                continue;
            }
            if(a[i] > max2)
            {
                max2 = a[i];
                amountmax = 1;
            }
            else if(a[i] == max2)
            {
                ++amountmax;
            }
        }
        if(max2 != max1 - 1)
        {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int res = fact[n - 1];
            if(i >= amountmax)
            {
                int minus = ((ll)c(i, amountmax) * fact[amountmax]) % mod;
                minus = ((ll)minus * fact[n - 1 - amountmax]) % mod;
                res = ((ll)res - minus + mod) % mod;
            }
            ans = (ans + res) % mod;
        }
        cout << ans << '\n';
    }
}