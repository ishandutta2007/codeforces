#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())

const int MAXN = (int)1e6;

vector<int> G[MAXN];
bool visited[MAXN];
int pos[MAXN];
int n;
vector<int> Q1;
vector<int> Q2;

int op(int x)
{

    if (x > n)
        return x - n;
    else
        return x + n;
}

void dfs(int x)
{
    visited[x] = true;
    visited[op(x)] = true;
    Q1.push_back(x);
    Q2.push_back(op(x));
    for (int y : G[pos[op(x)]])
        if (!visited[y])
            dfs(y);
}

void wypisz(vector<int> X)
{
    for (int a : X)
        cout << a << " ";
    cout << endl;
}

int32_t main()
{

    cin >> n;
    if (n % 2)
    {
        cout << "Second" << endl;

        // vector<vector<int>> G(n + 2);
        // vector<bool> visited(2 * n + 2, false);
        // vector<int> pos(2 * n + 2);

        rep(i, 2 * n)
        {
            int a;
            cin >> a;
            G[a].push_back(i + 1);
            pos[i + 1] = a;
        }
        rep(i, n) if (!visited[i + 1]) dfs(i + 1);
        if (accumulate(all(Q1), 0ll) % (2 * n) == 0)
            wypisz(Q1);
        else if (accumulate(all(Q2), 0ll) % (2 * n) == 0)
            wypisz(Q2);
        else
        {
            exit(-1);
        }
    }
    else
    {
        cout << "First" << endl;
        rep(i, 2 * n) cout << (i % n) + 1 << " ";
        cout << endl;
    }
    int a;
    cin >> a;
    cerr << a << endl;
    return 0;
}