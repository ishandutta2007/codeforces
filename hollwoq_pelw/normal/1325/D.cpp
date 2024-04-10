///BE NAME KHODA
#include <bits/stdc++.h>

using namespace std;

#define S second
#define F first
#define int long long

typedef long long ll;
typedef long double ld;

const int maxn = 3e5+10;
const int mod = 1e9+7;
const ll inf = 1e18+10;

ll n, m, x, s;
ll cnt[70];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> x >> s;
    if(x % 2 != s % 2) return cout<< -1, 0;
    if(x > s) return cout<< -1, 0;

    if(x == 0 && s == 0)
        return cout<< 0, 0;

    int X = x, S = s;
    if(x == s)
    {
        cout<< 1 <<"\n"<< x;
        return 0;
    }

    /// 2
    for(int i = 0; i < 60; i++)
        if(x&(1ll<<i))
            s -= (1ll<<i);
        else
          cnt[i+1] = 1;

    bool T = 1;
    for(int i = 0; i < 60; i++)
        if((s & (1ll<<i)) && !cnt[i])
            T = 0;

    if(T)
    {
        cout<< 2 <<"\n";
        int a = x, b = 0;
        for(int i = 0; i < 60; i++)
            if(s & (1ll<<i))
            {
                a += (1ll<<(i-1));
                b += (1ll<<(i-1));
            }
        cout<< a <<" "<< b;
        return 0;
    }

    x = X, s = S;
    int a = x, b = 0, c = 0;
    s -= x;
    for(int i = 0; i < 60; i++)
        if(s & (1ll<<i))
        {
            b += (1ll<<(i-1));
            c += (1ll<<(i-1));
        }
    cout<< 3 <<"\n"<< a <<" "<< b <<" "<< c;
}