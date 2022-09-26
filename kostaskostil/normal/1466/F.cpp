#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 5e5 + 100;

typedef long long ll;
#define int ll

const int MOD = 1e9+7;

int p[nmax];
int sz[nmax];

int get(int v)
{
    if (v==p[v])
        return v;
    return p[v]=get(p[v]);
}

void un(int u, int v)
{
    u=get(u);
    v=get(v);
    if (u==v)
        return;
    if (sz[u]>sz[v])
        swap(u, v);
    p[u]=v;
    sz[v]+=sz[u];
}

vector<pair<int, int> > ed;
vector<int> ans;
vector<pair<int, int> > univ;
int pw[nmax];
map<int, int> ok;

set<int> done;
//vector<pair<int, int> > g[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pw[0]=1;
    for (int i=1; i<nmax; i++)
        pw[i]=(pw[i-1]*2)%MOD;

    int n, m;
    cin>>n>>m;

    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        if (k==1)
        {
            int x;
            cin>>x;
            ed.pb({x, x});
            univ.pb({i, x});
        }
        else
        {
            int x, y;
            cin>>x>>y;
            ed.pb({x, y});
//            g[x].pb(y);
//            g[y].pb(x);
        }
    }

    for (int i=1; i<=m; i++)
        p[i]=i, sz[i]=1;

    for (int i=0; i<n; i++)
    {
        auto pa = ed[i];
        if (pa.fi!=pa.se)
        {
            pa.fi = get(pa.fi);
            pa.se = get(pa.se);
            if (pa.fi != pa.se)
            {
                if (done.count(pa.fi) and done.count(pa.se))
                    continue;
                ans.pb(i+1);
                if (done.count(pa.fi) or done.count(pa.se))
                {
                    done.insert(pa.fi);
                    done.insert(pa.se);
                }
                un(pa.fi, pa.se);
            }
        }
        else
        {
            int x=pa.fi;
            if (!done.count(get(x)))
            {
                ans.pb(i+1);
                done.insert(get(x));
            }
        }
    }

    for (auto pa:univ)
    {
        int i=pa.se;
        if (ok.count(get(i)))
            continue;
        ok[get(i)]=sz[get(i)];
    }

    for (int i=1; i<=m; i++)
        if (!ok.count(get(i)))
            ok[get(i)]=sz[get(i)]-1;

    int sum=1;
    for (auto pa: ok)
    {
        sum*=pw[pa.se];
        sum%=MOD;
    }

    cout<<sum<<" "<<ans.size()<<"\n";
    sort(ans.begin(), ans.end());
    for (int i:ans)
        cout<<i<<" ";
    cout<<"\n";
}