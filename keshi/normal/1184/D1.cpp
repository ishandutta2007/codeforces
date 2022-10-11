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

int main(){
    fast_io
    ll n, pos, m, q;
    cin >> n >> pos >> m >> q;
    while (q --)
    {
      ll t, x;
      cin >> t >> x;
      if (t)
      {
        if (x <= pos)
          pos++;
        n ++;
      }
      else
      {
        if (x < pos)
          pos -= x, n -= x;
        else
          n = x;
      }
      cout << n << sep << pos << endl;
    }
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