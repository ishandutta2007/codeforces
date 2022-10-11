/************************* In the name of Allah *************************/
#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef string          str;
typedef pair<ll,ll>     pll;

#define F               first
#define S               second
#define pb              push_back
#define sep             ' '
#define endl            '\n'
#define fast_io         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = 1e9 + 7,
         INF = 1e18,
         MAXN = 1e5 + 10;

pll a[MAXN], b[MAXN];
ll ans[MAXN];

int main(){
    fast_io
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
      cin >> a[i].F;
      a[i].S = i;
    }
    for (int i = 0; i < m; i ++)
      cin >> b[i].F >> b[i].S;
    sort(a, a + n);
    sort(b, b + m);
    ll ptr = 0, g = 0;
    for (int i = 0; i < n; i ++)
    {
      while (ptr < m && b[ptr].F <= a[i].F)
      {
        g += b[ptr].S;
        ptr ++;
      }
      ans[a[i].S] = g;
    }
    for (int i = 0; i < n; i ++)
      cout << ans[i] << sep;
    return 0;
}

/*
 __  __       _         _ _  _____ _           _                __ _
|  \/  |     | |       | (_)/ ____| |         | |              / _(_)
| \  / | __ _| |__   __| |_| (___ | |__   ___ | | _____  _   _| |_ _
| |\/| |/ _` | '_ \ / _` | |\___ \| '_ \ / _ \| |/ / _ \| | | |  _| |
| |  | | (_| | | | | (_| | |____) | | | | (_) |   < (_) | |_| | | | |
|_|  |_|\__,_|_| |_|\__,_|_|_____/|_| |_|\___/|_|\_\___/ \__,_|_| |_|
*/