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
#define cerr   \
    if (false) \
    cerr
#define what(x) cerr << #x << " is " << x << endl;

const int MAXN = 1002;

bitset<MAXN> visited;
vector<int> cur;
vector<int> G[MAXN];
int n;
bool znalazlem = false;
int a = 0;

void dzialaj()
{
    cout << "? " << cur[0] + 1 << " " << cur.back() + 1 << endl;
    int r;
    cin >> r;
    --r;
    //  cerr << r << endl;
    for (int b : cur)
        if (b != r)
            visited[b] = true;
    a = r;
}

void dfs(int x, int p = -1)
{
    cur.push_back(x);

    if (cur.size() == 3)
    {
        znalazlem = true;
        dzialaj();
    }
    for (int y : G[x])
        if (y != p && !visited[y] && !znalazlem)
            dfs(y, x);
    cur.pop_back();
}

void odpowiedz(int x)
{
    cout << "! " << x + 1 << endl;
    exit(0);
}

vector<int> znajdz()
{
    vector<int> V;
    for (int b : G[a])
        if (!visited[b])
            V.push_back(b);
    return V;
}

int ile(int x)
{
    int cnt = 0;
    for (int b : G[x])
        if (!visited[b])
            cnt++;
    return cnt;
}

void solve()
{
    while (true)
    {
        cerr << visited << endl;
        what(a);
        if (ile(a) == 0)
            odpowiedz(a);

        znalazlem = false;
        dfs(a);
        if (!znalazlem)
        {
            cerr << "nieznalazlem\n";
            for (int x : G[a])
                if (!visited[x])
                {
                    dfs(x);
                    break;
                }
            if (!znalazlem)
            {
                cerr << "wciaz\n";
                cur = znajdz();
                cerr << cur.size() << endl;
                cur.push_back(a);
                dzialaj();
                continue;
            }
        }
    }
}

main()
{
    cin >> n;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
    solve();
}