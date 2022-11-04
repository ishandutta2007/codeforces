#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, pos;
    cin >> n >> x >> pos;
    vector<int> fact(10000);
    fact[0] = 1;
    for(int i = 1; i < 10000; i++)
    {
        fact[i] = ((long long)fact[i - 1] * i) % mod;
    }
    int l = 0;
    int r = n;
    int ans = 0;
    int any = n - 2;
    int coef = 1;
    int nowbigger = n - x;
    int nowsmaller = x - 1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(pos > mid)
        {
            ans = ((((long long)(nowbigger) * fact[any]) % mod) * coef + ans) % mod;
            any--;
            coef = ((long long)coef * nowsmaller--) % mod;
            l = mid + 1;
        }
        else if(pos < mid)
        {
            ans = ((((long long)(nowsmaller) * fact[any]) % mod) * coef + ans) % mod;
            any--;
            coef = ((long long)coef * nowbigger--) % mod;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ((long long)fact[n - 1] + mod - ans) % mod;
}