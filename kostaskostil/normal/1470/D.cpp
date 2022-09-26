#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
//#define int ll

using namespace std;

const int nmax=3e5+100;
int p[nmax];

int get(int v)
{
    if (p[v]==v)
        return v;
    return p[v]=get(p[v]);
}

void un(int u, int v)
{
    u=get(u);
    v=get(v);
    if (rand()%2)
        swap(u, v);
    p[u]=v;
}

int n, m;
vector<pair<int, int> > ed;
vector<int> g[nmax];
int c[nmax];

void dfs(int v, int pr, int col)
{
    c[v]=col;
    for (int i:g[v])
        if (i!=pr)
            dfs(i, v, 3-col);
}

int try_()
{
    random_shuffle(ed.begin(), ed.end());
    for (int i=1; i<=n; i++)
        p[i]=i, g[i].clear();
    int cnt=0;
    for (auto pa:ed)
    {
        if (get(pa.fi) != get(pa.se))
        {
//            g[pa.fi].pb(pa.se);
//            g[pa.se].pb(pa.fi);
            un(pa.fi, pa.se);
            cnt++;
        }
    }
    if (cnt!=n-1)
        return -1;

    for (auto pa:ed)
        g[pa.fi].pb(pa.se),
        g[pa.se].pb(pa.fi);

    deque<int> q;
    for (int i=1; i<=n; i++)
        c[i]=0;
    vector<int> ans = {};
    q.push_back(1);
    c[1]=1;
    while (!q.empty())
    {
        int v=q.front();
        q.pop_front();
        if (c[v]==1)
            ans.pb(v);

        for (int i : g[v])
            if (c[i]==0)
        {
            if (c[v]==1)
            {
                c[i]=2;
                q.push_back(i);
            }
            else
            {
                c[i]=1;
                q.push_front(i);
                q.push_back(v);
                break;
            }
        }
    }

    cout<<"YES\n";
    cout<<ans.size()<<"\n";
    for (int i:ans)
        cout<<i<<" ";
    cout<<"\n";
    return 1;
//    dfs(1, -1, 1);
//    bool is1 = true;
//    bool is2 = true;
//    for (auto pa:ed)
//        if (c[pa.fi]==1 and c[pa.se]==1)
//            is1=false;
//        else
//        if (c[pa.fi]==2 and c[pa.se]==2)
//            is2=false;
//    if (!is1 and !is2)
//        return 0;
//    if (is1)
//    {
//        vector<int> ok;
//        for (int i=1; i<=n; i++)
//            if (c[i]==1)
//                ok.pb(i);
//        cout<<"YES\n";
//        cout<<ok.size()<<"\n";
//        for (int i:ok)
//            cout<<i<<" ";
//        cout<<"\n";
//    }
//    else
//    if (is2)
//    {
//        vector<int> ok;
//        for (int i=1; i<=n; i++)
//            if (c[i]==2)
//                ok.pb(i);
//        cout<<"YES\n";
//        cout<<ok.size()<<"\n";
//        for (int i:ok)
//            cout<<i<<" ";
//        cout<<"\n";
//    }
//    return 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    int ___;
    cin>>___;
    for (int _ = 0; _<___; _++)
    {
        cin>>n>>m;
        ed.resize(m);
        for (auto& pa : ed)
            cin>>pa.fi>>pa.se;
        bool ok = false;
//        for (int i=1; i<=100; i++)
//        {
            int res=try_();
            if (res==1)
                ok=true;
//            if (res!=0)
//                break;
//        }
        if (!ok)
            cout<<"NO\n";
    }
}