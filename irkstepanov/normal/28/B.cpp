#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<int> comp;
int cnt = -1;

void dfs(int v)
{
    comp[v] = cnt;
    for (int to : g[v]) {
        if (comp[to] == -1) {
            dfs(to);
        }
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        if (i + d < n) {
            g[i].pb(i + d);
            g[i + d].pb(i);
        }
        if (i - d >= 0) {
            g[i].pb(i - d);
            g[i - d].pb(i);
        }
    }

    comp.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (comp[i] == -1) {
            ++cnt;
            dfs(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (comp[p[i]] != comp[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

}