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

const int MAXN = 1e5 + 5;
const int SQR = 8e2;
vector<int> dzieci[MAXN];
vector<int> G[MAXN];
vector<int> post;
int najglebszy[MAXN];
int odp[MAXN];
int n;

void dfs_ini(int x)
{
    for (int y : G[x])
        if (!dzieci[y].size())
        {
            dzieci[x].pb(y);
            dfs_ini(y);
        }
    post.pb(x);
}

void wcztywanie()
{
    cin >> n;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs_ini(1);
    fill(odp, odp + MAXN, -1);
}

int solve(int k)
{
    if (odp[k] != -1)
        return odp[k];
    int ans = 0;
    for (int x : post)
    {
        najglebszy[x] = 0;
        int sec = 0;

        for (int y : dzieci[x])
        {
            if (najglebszy[x] < najglebszy[y])
            {
                sec = najglebszy[x];
                najglebszy[x] = najglebszy[y];
            }
            else
                sec = max(sec, najglebszy[y]);
        }
        najglebszy[x]++;
        if (sec + najglebszy[x] >= k)
        {
            ans++;
            najglebszy[x] = 0;
        }
    }
    odp[k] = ans;
    return ans;
}

main()
{
    _upgrade;
    wcztywanie();
    for (int i = 1; i <= min(SQR, n); i++)
        odp[i] = solve(i);
    int l = SQR + 1;
    while (l <= n)
    {
        odp[l] = solve(l);
        int p = l;
        int q = n;
        while (p != q)
        {
            int s = (p + q + 1) / 2;
            if (solve(s) < odp[l])
                q = s - 1;
            else
                p = s;
        }
        for (int i = l; i <= p; i++)
            odp[i] = odp[l];
        l = p + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << odp[i] << endl;
}