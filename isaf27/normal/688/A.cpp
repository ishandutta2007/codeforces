#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    /*#define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);*/
    int n, d;
    cin >> n >> d;
    string s = "";
    for (int i = 0; i < n; i++)
        s += '1';
    int ans = 0;
    int now = 0;
    for (int i = 0; i < d; i++)
    {
        string e;
        cin >> e;
        if (e != s)
        {
            now++;
            continue;
        }
        ans = max(ans, now);
        now = 0;
    }
    ans = max(ans, now);
    cout << ans;
    return 0;
}