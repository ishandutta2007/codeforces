#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 300500;
int p[nmax];
int a[nmax];
vector<int> g[nmax];
map<pair<int, int>, int> mp;
int n, m, x;

void cry()
{
    cout<<"NO\n";
    exit(0);
}

int get(int v)
{
    if (v==p[v])
        return v;
    return p[v]=get(p[v]);
}

int cnt=0;
void unite(int u, int v)
{
    u=get(u);
    v=get(v);
    p[u] = v;
}

int pw[nmax];
vector<int> ans;
vector<int> bans;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>x;
    int s=0;
    vector<pair<int, int> > pr;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        p[i]=i;
        pr.pb({a[i], i});
        s+=a[i];
    }
    if (s < (n-1)*x)
        cry();

    for (int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        mp[{u, v}]=mp[{v, u}]=i;
        if (get(u) != get(v))
            g[v].pb(u),
            g[u].pb(v),
            pw[v]++,
            pw[u]++,
            unite(u, v);
    }

    unordered_set<int> done;
    set<pair<int, int> > pows;
    for (int i=1; i<=n; i++)
        pows.insert({pw[i], i});

    for (int i=1; i<n; i++)
    {
        auto pa = *pows.begin();
        pows.erase(pa);
        int v=pa.se;

        int u;
        for (int i : g[v])
            if(!done.count(i))
                u=i;

        pows.erase({pw[u], u});
        pw[u]--;
        pows.insert({pw[u], u});

        if (a[v] < x)
            bans.pb(mp[{u, v}]);
        else
            a[u] += a[v]-x, ans.pb(mp[{u, v}]);

        done.insert(v);
    }
    cout<<"YES\n";
    for (int i :ans)
        cout<<i<<"\n";
    reverse(bans.begin(), bans.end());
    for (int i: bans)
        cout<<i<<"\n";
}