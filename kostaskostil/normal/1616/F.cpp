#include <bits/stdc++.h>
#define y1 y_1
#define fi first
#define se second
#define pb push_back
typedef long long ll;
#define int ll
using namespace std;

const int nmax = 1000500;

int n, m;
vector<pair<int, int> > ed;
int g[100][100];
vector<array<int, 3> > tr;
vector<int> ids[100100];
int col[100100];

int p[100100];
int get(int v)
{
    if (p[v]==v)
        return v;
    return p[v] = get(p[v]);
}
void upd(int u, int v)
{
    u=get(u);
    v=get(v);
    p[u]=v;
}
int rib(int i, int j)
{
    return n*i+j;
}
void solve(double time_to_kek)
{
    cin>>n>>m;
    for (int i=0; i<n*n; i++)
        p[i] = i;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            upd(rib(i, j), rib(j, i));
    ed.clear();
    tr.clear();
    for (int i=0; i<n*n; i++)
    {
        ids[i].clear();
    }
    memset(g, 0, sizeof(g));
    for (int i=0; i<m; i++)
    {
        int x, y, c;
        cin>>x>>y>>c;
        x--;y--;
        ed.pb({x, y});
        g[x][y] = g[y][x] = c;
    }
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
        if (g[i][j])
        for (int k=j+1; k<n; k++)
        if (g[i][k])
        if (g[j][k])
        for (int t=k+1; t<n; t++)
        if (g[i][t])
        if (g[j][t])
        if (g[k][t])
    {
        upd(rib(i, j), rib(k, t));
        upd(rib(i, k), rib(j, t));
        upd(rib(i, t), rib(j, k));
    }
    for (int i=0; i<n*n; i++)
        col[i] = -1;

    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            for (int k=j+1; k<n; k++)
                if (g[i][j])
                if (g[j][k])
                if (g[i][k])
                {
                    tr.pb({get(rib(i, j)), get(rib(j, k)), get(rib(i, k))});
                }
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (g[i][j] > 0)
            {
                int r = get(rib(i, j));
                if ((col[r] > 0) && (col[r] != g[i][j]))
                {
                    cout<<"-1\n";
                    return;
                }
                col[r] = g[i][j];
            }
    int qq=0;
    for (auto [a, b, c] : tr)
    {
        ids[a].pb(qq);
        ids[b].pb(qq);
        ids[c].pb(qq);
        qq++;
//        cout<<col[a]<<" "<<col[b]<<" "<<col[c]<<"\n";
        if ((col[a] > 0) && (col[b] > 0) && (col[c] > 0))
            if ((set<int>{col[a], col[b], col[c]}).size() == 2)
        {
            cout<<"-1\n";
            return;
        }
    }
    int k = tr.size();
    vector<pair<int, int> > ef;
    vector<int> szs(n*n, 0);
    for (auto [a, b, c] : tr)
    {
        szs[a]++;
        szs[b]++;
        szs[c]++;
    }
    for (int i=0; i<n*n; i++)
        if (szs[i] > 0)
            ef.pb({szs[i], i});
    sort(ef.begin(), ef.end());
    reverse(ef.begin(), ef.end());
    vector<int> m1;
    for (auto [_s, v] : ef)
    {
        if (col[v] == -1)
            m1.pb(v);
    }
    while (clock()*1.0/CLOCKS_PER_SEC < time_to_kek)
    {
        bool bad = false;
        for (auto[_s, v] : ef)
        {
            if (col[v] != -1)
                continue;

            int ok = -1;
            for (int i : ids[v])
            {
                int r = (col[tr[i][0]] > 0) + (col[tr[i][1]] > 0) + (col[tr[i][2]] > 0);
                if (r != 2)
                    continue;
                vector<int> u;
                if (col[tr[i][0]] > 0) u.pb(col[tr[i][0]]);
                if (col[tr[i][1]] > 0) u.pb(col[tr[i][1]]);
                if (col[tr[i][2]] > 0) u.pb(col[tr[i][2]]);
                int h = -2;
                if (u[0] == u[1])
                    h = u[0];
                else
                    h = 6 - u[0] - u[1];
                if ((ok == -1) || (h == ok))
                {
                    ok = h;
                }
                else
                    ok = -2;
            }
            if (ok == -2)
            {
                bad = true;
                break;
            }
            if (ok == -1)
                ok = rand()%3 + 1;
            col[v] = ok;
        }
        if (!bad)
        {
            for (auto[x, y] : ed)
            {
                int r = col[get(rib(x, y))];
                if (r == -1) r = 1;
                cout<<r<<" ";
            }
            cout<<"\n";
            return;
        }

        for (int i : m1)
            col[i] = -1;
    }

    cout<<-1<<"\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    int ___;
    cin>>___;
    for (int _=1; _<=___; _++)
    {
        solve(_*0.8/___);
    }
}