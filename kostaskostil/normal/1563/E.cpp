#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

#define int long long

const int nmax = 1010;

int n;
vector<int> g[nmax];
int a[nmax];
int b[nmax];
int used[nmax];
int pred[nmax];
int cur;
int en;
int pen;
int sz;
bool infinite_power;
bool dfs(int v, int p)
{
    if (pred[v] != -1)
    {
        en = v;
        pen = p;
        return true;
    }

    pred[v] = p;
    cur += b[v];
//    cout<<v<<" "<<cur<<" "<<p<<"\n";
    for (int i : g[v])
        if (i!=p)
            if ((cur > a[i]) or (pred[i] != -1))
                if (dfs(i, v))
                {
                    cur -= b[v];
                    return true;
                }
    cur -= b[v];
//    pred[v] = -1;
    return false;
}

bool explore()
{
    for (int i=1; i<=n; i++)
        pred[i] = -1;
    for (int i=1; i<=n; i++)
        if (used[i])
            pred[i] = i;
    en = -1;
    pen = -1;
    vector<int> rassmotr;
    for (int i=1; i<=n; i++)
        if (used[i])
            rassmotr.pb(i);
    random_shuffle(rassmotr.begin(), rassmotr.end());
    bool br = false;
    for (int i : rassmotr)
    {
        for (int j : g[i])
            if (!used[j])
                if (cur > a[j])
                    if (dfs(j, i))
                    {
                        br = true;
                        break;
                    }
        if (br)
            break;
    }
    if (en==-1)
        return false;
    set<int> nw;
    while (pred[en] != en)
        nw.insert(en), en = pred[en];
    en = pen;
    while (pred[en] != en)
        nw.insert(en), en = pred[en];
    for (int i : nw)
        if (!used[i])
            used[i] = 1, sz++, cur+=b[i];
    return true;
}

bool check(int x)
{
    for (int i=1; i<=n; i++)
        used[i] = 0;
    used[1] = 1;
    cur = x;
    sz = 1;
//    infinite_power = false;
    for (int i=1; i<=n; i++)
        random_shuffle(g[i].begin(), g[i].end());
    while (sz < n)
    {
        if (!explore())
            break;
    }
//    cout<<x<<" "<<infinite_power<<" "<<sz<<"\n";
    if (infinite_power)
        return true;
    return (sz == n);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    int _;
    cin>>_;
    while (_--)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            g[i].clear();
        int m;
        cin>>m;
        for (int i=2; i<=n; i++)
            cin>>a[i];
        for (int i=2; i<=n; i++)
            cin>>b[i];
        for (int i=1; i<=m; i++)
        {
            int x, y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
//        cout<<"YYY\n";
//        cout<<check(50)<<"\n";

        int l = 0;
        int r = 1e9 + 1;
        while (r - l > 1)
        {
            m = (l+r)/2;
            if (check(m))
                r = m;
            else
                l = m;
        }
        cout<<r<<"\n";
    }
}

/**
2
6 7
100 10 15 17 19
100 6 1 1 5
1 2
2 3
1 3
3 4
4 5
4 6
5 6
5 8
10 18 2 15
5 3 10 4
1 2
1 3
1 4
1 5
2 3
3 4
4 5
5 2

1
3 3
10 14
2 100
1 2
2 3
3 1
*/