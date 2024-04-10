#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;

const int MAXN = (int)1e6;

vector<int> G[MAXN];
int dist[MAXN];
int n, a, b, da, db;

void clear_dist()
{
    rep(i, n + 2) dist[i] = -1;
}
void clear()
{
    rep(i, n + 2) dist[i] = -1, G[i].clear();
}

void dfs(int x)
{
    for (int y : G[x])
        if (dist[y] < 0)
        {
            dist[y] = dist[x] + 1;
            dfs(y);
        }
}

void get_dist(int x)
{
    clear_dist();
    dist[x] = 0;
    dfs(x);
}

bool first_move()
{
    get_dist(a);
    return dist[b] <= da;
}

bool no_chance()
{
    return db <= 2 * da;
}

bool get_di()
{
    get_dist(0);
    pii ans = make_pair(0, 0);

    rep(i, n) ans = max(ans, make_pair(dist[i], i));

    get_dist(ans.nd);
    rep(i, n) if (dist[i] > 2 * da) return true;
    return false;
}

int32_t main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {
        cin >> n >> a >> b >> da >> db;
        --a, --b;
        clear();
        rep(i, n - 1)
        {
            int x, y;
            cin >> x >> y;
            G[--x].pb(--y);
            G[y].pb(x);
        }
        if (no_chance())
        {
            cout << "Alice\n";
            what(1) continue;
        }
        if (first_move())
        {
            cout << "Alice\n";
            what(1.5) continue;
        }
        if (get_di())
        {
            cout << "Bob\n";
            what(2) continue;
        }
        what(3);
        cout
            << "Alice\n";
    }
}