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

vector<vector<int> > g;
vector<int> par;

void dfs(int v, int p)
{
    par[v] = p;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, r1, r2;
    cin >> n >> r1 >> r2;
    --r1, --r2;
    g.resize(n);
    par.resize(n);

    for (int i = 0; i < n; ++i) {
        if (i == r1) {
            continue;
        }
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
        g[i].pb(p);
    }

    dfs(r2, r2);
    for (int i = 0; i < n; ++i) {
        if (i == r2) {
            continue;
        }
        cout << par[i] + 1 << " ";
    }
    cout << "\n";

}