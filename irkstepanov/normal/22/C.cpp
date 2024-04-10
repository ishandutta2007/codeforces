 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    if (m < n - 1) {
        cout << "-1\n";
        return 0;
    }

    vector<vector<int> > g(n);
    --v;
    int bad;
    if (v == 0) {
        g[v].pb(1);
        g[1].pb(v);
        bad = 1;
    } else{
        g[v].pb(0);
        g[0].pb(v);
        bad = 0;
    }

    vector<int> x;
    for (int i = 0; i < n; ++i) {
        if (i != v && i != bad) {
            g[i].pb(v);
            g[v].pb(i);
            x.pb(i);
        }
    }

    m -= (n - 1);
    int i = 0, j = 1;
    while (m) {
        if (i == sz(x) - 1) {
            cout << "-1\n";
            return 0;
        }
        g[x[i]].pb(x[j]);
        g[x[j]].pb(x[i]);
        ++j;
        --m;
        if (j == sz(x)) {
            ++i, j = i + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int to : g[i]) {
            if (to > i) {
                cout << i + 1 << " " << to + 1 << '\n';
            }
        }
    }

}