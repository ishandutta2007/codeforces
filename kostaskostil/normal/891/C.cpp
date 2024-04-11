#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

int n, m;
vector<pair<pair<int, int>, pair<int, int> > > g;

map<int, pair<int, int> > vec[500500];

int p[500500];
int ed[500500];
int nt=0;

int get(int i)
{
    if (i==p[i])
        return i;
    return p[i]=get(p[i]);
}

void un(int x, int y)
{
    x=get(x);
    y=get(y);

    p[x]=y;
}

bool check(vector<int> qur, int c)
{
    set<int> ver;
    for (int i:qur)
        ver.insert(vec[c][i].fi), ver.insert(vec[c][i].se);
    map<int, int> press;
    int ct=0;
    for (int i:ver)
        ct++, press[i]=ct;
    for (int i=1; i<=ct; i++)
        p[i]=i;
    for (int i:qur)
    {
        int v=get(press[vec[c][i].fi]);
        int u=get(press[vec[c][i].se]);
        if (v==u)
            return false;
        un(v, u);
    }
    return true;
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for (int i=1; i<=n; i++)
        p[i]=i;

    int x, y, v;
    for (int i=1; i<=m; i++)
    {
        cin>>x>>y>>v;
        g.pb({{v, i}, {x, y}});
    }

    sort(g.begin(), g.end());
    vector<pair<pair<int, int>, pair<int, int> > > cur;

    for (int i=0; i<m; i++)
    {
        if (i!=m-1)
            if (g[i].fi.fi==g[i+1].fi.fi)
            {
                cur.pb(g[i]);
                continue;
            }
        cur.pb(g[i]);

        nt++;

        for (auto pa:cur)
        {
            if (get(pa.se.fi)==get(pa.se.se))
            {
                ed[pa.fi.se]=-1;
                continue;
            }
            ed[pa.fi.se]=nt;
            int v=get(pa.se.fi);
            int u=get(pa.se.se);
            vec[nt][pa.fi.se]={v, u};
        }
        for (auto pa:cur)
            un(pa.se.fi, pa.se.se);
        cur.clear();
    }

//    for (int i=1; i<=nt; i++, cout<<"\n")
//        for (auto pa:vec[i])
//            cout<<pa.fi<<" "<<pa.se.fi<<" "<<pa.se.se<<"; ";


    int k;
    cin>>k;
    for (int iii=0; iii<k; iii++)
    {
        int t;
        cin>>t;

        vector<pair<int, int> > qur;
        for (int i=0; i<t; i++)
        {
            int r;
            cin>>r;
            qur.pb({ed[r], r});
        }

        sort(qur.begin(), qur.end());

        if (qur[0].fi==-1)
        {
            cout<<"NO\n";
            continue;
        }

        vector<int> edg;
        bool flag=true;

        for (int i=0; i<t; i++)
        {
            if (i!=t-1)
                if (qur[i].fi==qur[i+1].fi)
                {
                    edg.pb(qur[i].se);
                    continue;
                }
            edg.pb(qur[i].se);
            if (!check(edg, qur[i].fi))
            {
                flag=false;
                break;
            }
            edg.clear();
        }

        if (flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}