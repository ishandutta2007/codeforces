#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll now = 2050;
        while(now <= n)
        {
            now *= 10;
        }
        now /= 10;
        int ans = 0;
        while(n >= 2050 && now >= 2050)
        {
            ans += n / now;
            n %= now;
            now /= 10;
        }
        if(n == 0)
        {
            cout << ans << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }
}