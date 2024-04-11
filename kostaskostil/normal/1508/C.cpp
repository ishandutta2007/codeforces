#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 2e5+100;

int p[nmax];
int sz[nmax];
int q[nmax];

int get(int v)
{
    if (p[v]==v)
        return v;
    return p[v]=get(p[v]);
}

int un(int u, int v)
{
    u=get(u);
    v=get(v);
    if (u==v)
        return u;
    if (rand()%2)
        swap(u, v);
    p[u]=v;
    sz[v]+=sz[u];
    return v;
}

int getq(int v)
{
    if (q[v]==v)
        return v;
    return q[v]=getq(q[v]);
}

int unq(int u, int v)
{
    u=getq(u);
    v=getq(v);
    if (u==v)
        return u ;
    if (rand()%2)
        swap(u, v);
    q[u]=v;
    return v;
}
int r[nmax];
int getr(int v)
{
    if (r[v]==v)
        return v;
    return r[v]=getr(r[v]);
}

int unr(int u, int v)
{
    u=getr(u);
    v=getr(v);
    if (u==v)
        return u;
    if (rand()%2)
        swap(u, v);
    r[u]=v;
    return v;
}

vector<pair<int, int> > g[nmax];
int mp[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i=0; i<nmax; i++)
        sz[i]=1, p[i]=i, q[i]=i;

    int n, m;
    cin>>n>>m;
    int xorik = 0;

    vector<pair<int, pair<int, int> > > ed;
    for (int i=1; i<=m; i++)
    {
        int x, y, s;
        cin>>x>>y>>s;
        g[x].pb({y, s});
        g[y].pb({x, s});
        xorik ^= s;
        ed.pb({s, {x, y}});
    }

    unordered_set<int> st = {1};
    for (int i=2; i<=n; i++)
    {
        for (int j : st)
            mp[j] = sz[j];

        for (auto pa : g[i])
            mp[get(pa.fi)]--;
        st.insert(i);

        int j = i;
        auto stx = st;
//    cout<<"HEREIN"<<endl;
        for (auto pa : stx)
            if (pa!=i)
        {
//            cout<<pa<<endl;
            if (mp[pa] > 0)
            {
                st.erase(pa);
                st.erase(j);
                j = un(pa, j);
                st.insert(j);
            }
        }
//    cout<<"HEREOUT"<<endl;
    }

    sort(ed.begin(), ed.end());
    int lowest = xorik;

    int ans=0;
    for (int i=0; i<nmax; i++)
        q[i]=p[i], r[i]=i;

    for (auto pa : ed)
    {
        int u = getq(pa.se.fi);
        int v = getq(pa.se.se);

        if (q[u]!=q[v])
        {
            unq(u, v);
            unr(pa.se.fi, pa.se.se);
            ans+=pa.fi;
        }
    }

//    for (int i=1; i<=n; i++)
//        cout<<r[i]<<" ";
//    cout<<"\n";
    for (auto pa : ed)
    {
        if (getr(pa.se.fi) != getr(pa.se.se))
            lowest = min(lowest, pa.fi);
    }

    unordered_map<int, int> mpx;
    for (int i=1; i<=n; i++)
        mpx[get(i)]++;
    for (auto& pa : mpx)
        pa.se = (pa.se*(pa.se-1))/2 - (pa.se-1);
    for (auto pa : ed)
    {
        int u = get(pa.se.fi);
        int v = get(pa.se.se);
        if (u==v)
            mpx[v]--;
    }
//    cout<<"ost "<<ans<<", xorik "<<xorik<<", lowest "<<lowest<<"\n";
    for (auto pa : mpx)
    {
//        cerr<<pa.se<<"\n";
        if (pa.se > 0)
        {
            cout<<ans<<"\n";
            exit(0);
        }
    }

    cout<<ans+lowest<<"\n";
}