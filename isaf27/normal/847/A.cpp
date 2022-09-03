#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 1;

int c[MAXN];

int pr[MAXN], nxt[MAXN];

vector <int> g;

int main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        pr[i] = l, nxt[i] = r;
    }

    for (int i = 0; i < n; i++)
        if (pr[i] == -1) {
            int u = i;
            while (u != -1) {
                g.push_back(u);
                u = nxt[u];
            }
        }

    for (int i = 0; i < (int)g.size(); i++) {
        if (i == 0)
            pr[g[i]] = -1;
        else
            pr[g[i]] = g[i - 1];
        if (i == (int)g.size() - 1)
            nxt[g[i]] = -1;
        else
            nxt[g[i]] = g[i + 1];
    }

    for (int i = 0; i < n; i++)
        cout << pr[i] + 1 << " " << nxt[i] + 1 << endl;

    return 0;
}