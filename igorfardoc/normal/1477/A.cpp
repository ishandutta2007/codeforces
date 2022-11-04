#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _gcd(ll a, ll b)
{
    if(b == 0)
    {
        return a;
    }
    return _gcd(b, a % b);
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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll gcd1 = a[1] - a[0];
        for(int i = 1; i < n - 1; i++)
        {
            gcd1 = _gcd(gcd1, a[i + 1] - a[i]);
        }
        if(a[0] < 0)
        {
            a[0] += gcd1 * ((abs(a[0]) - 1) / gcd1 + 1);
        }
        if(k < 0)
        {
            k += gcd1 * ((abs(k) - 1) / gcd1 + 1);
        }
        if(a[0] % gcd1 == k % gcd1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}