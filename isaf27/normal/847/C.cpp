#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 1;

int main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/
    ll n, k;
    cin >> n >> k;
    string s = "";
    ll c = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        //cerr << i << " " << c << " " << k << "\n";
        if (i + c == 2 * n)
        {
            for (int x = i; x < 2 * n; x++)
                s += ')';
            break;
        }
        if (k >= c)
        {
            k -= c;
            s += '(';
            c++;
            continue;
        }
        c--;
        s += ')';
    }
    if (k != 0)
    {
        cout << "Impossible";
        return 0;
    }
    cout << s;
    return 0;
}