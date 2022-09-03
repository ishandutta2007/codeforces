#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 1;

int c[MAXN];

int main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/

    int n; cin >> n;
    fill(c, c + MAXN, 0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < (int)s.length(); j++)
            c[j] += (s[j] - '0');
    }

    int ans = 0;
    for (int i = 0; i < MAXN; i++)
        ans = max(ans, c[i]);
    cout << ans << endl;
    return 0;
}