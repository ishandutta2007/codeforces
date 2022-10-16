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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

vector<int> X;
const int MAXN = 200;
const int inf = 1e6;
vector<int> G[MAXN + 100];
int ans = inf;
int n;

void bfs(int a)
{
    vector<int> dist(n, -2);
    queue<int> Q;
    dist[a] = 0;
    Q.push(a);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (int y : G[x])
        {
            if (dist[y] == -2)
            {
                dist[y] = dist[x] + 1;
                Q.push(y);
                continue;
            }
            if (dist[y] != dist[x] - 1)
            {
                ans = min(ans, dist[y] + dist[x] + 1);
                if (ans == 3)
                {
                    cout << 3 << endl;
                    exit(0);
                }
            }
        }
    }
}

main()
{
    cin >> n;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a != 0)
            X.pb(a);
    }

    if (X.size() > MAXN)
    {
        cout << 3 << endl;
        return 0;
    }
    n = X.size();
    rep(i, n)
        rep(j, n)
    {
        if (i == j || (X[i] & X[j]) == 0)
        {
        }
        else
        {
            G[i].pb(j);
        }
    }
    rep(i, n)
        bfs(i);
    if (ans == inf)
        cout << -1 << endl;
    else
    {
        cout << ans << endl;
    }

    _upgrade;
}