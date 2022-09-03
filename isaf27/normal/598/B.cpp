#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ld eps = 1e-8;
const ld pi = acos(-1.0);
const int M = 3 * 1e4;
const int two = 2;
const ll prime = 239;
const int BIG = 1e9 + 239;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int th = 3;
const int MS = (1 << 20);

int main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/
    cin.sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    for (int z = 0; z < q; z++)
    {
        //cerr << s << "\n";
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        k %= (r - l);
        string u;
        for (int i = l; i < r; i++)
            u += s[i];
        for (int i = l; i < r; i++)
            s[i] = u[(i - l - k + u.size()) % u.size()];
    }
    cout << s;
    return 0;
}