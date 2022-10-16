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

const int MAXN = 5e5 + 55;

vector<int> G[MAXN];
int chosen[MAXN];
int n, m;

int getMex(int x)
{
    set<int> S;
    for (int y : G[x])
        S.insert(chosen[y]);
    for (int i = 1;; i++)
        if (S.find(i) == S.end())
            return i;
}

int32_t main()
{
    _upgrade;
    cin >> n >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<pii> X;
    rep(i, n)
    {
        int a;
        cin >> a;
        X.emplace_back(a, i + 1);
    }
    sort(all(X));
    for (auto p : X)
    {
        if (p.st != getMex(p.nd))
        {
            cout << -1 << endl;
            exit(0);
        }
        //what(getMex(p.nd));
        chosen[p.nd] = p.st;
    }
    for (auto p : X)
        cout << p.nd << " ";
    cout << endl;
}