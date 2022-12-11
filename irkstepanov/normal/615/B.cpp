#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> deg(n);
    vector<vector<int> > g(n);

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        ++deg[a], ++deg[b];
        g[max(a, b)].pb(min(a, b));
    }

    vector<int> len(n, 1);
    len[0] = 1;

    for (int i = 1; i < n; ++i) {
        for (int p : g[i]) {
            len[i] = max(len[i], 1 + len[p]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, (ll)len[i] * (ll)deg[i]);
    }

    cout << ans << "\n";

}