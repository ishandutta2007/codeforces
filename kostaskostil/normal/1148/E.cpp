#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=500500;
int n;
int pos[nmax];
int to[nmax];
set<pair<int, int> > up, down;
vector<pair<pair<int, int>, int> > ans;

void mov(int i, int j, int d)
{
    if (2*d>pos[j]-pos[i])
        cout<<"WARN "<<pos[i]<<"->"<<to[i]<<" "<<to[j]<<"<-"<<pos[j]<<", d="<<d<<"\n";
    up.erase({pos[i], i});
    pos[i]+=d;
    if (pos[i]<to[i])
        up.insert({pos[i], i});
    down.erase({pos[j], j});
    pos[j]-=d;
    if (pos[j]>to[j])
        down.insert({pos[j], j});
    ans.pb({{i, j}, d});
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin>>n;
    set<pair<int, int> > s, t;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        pos[i]=x;
        s.insert({x, i});
    }
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        t.insert({x, i});
    }
    for (int i=1; i<=n; i++)
    {
        auto pa1=*s.begin();
        auto pa2=*t.begin();
        to[pa1.se]=pa2.fi;
        if (pa2.fi>pa1.fi)
            up.insert(pa1);
        if (pa2.fi<pa1.fi)
            down.insert(pa1);
        s.erase(s.begin());
        t.erase(t.begin());
    }
    vector<pair<int, int> > v;
    for (int i=1; i<=n; i++)
        v.pb({pos[i], i});
    sort(v.begin(), v.end());
    for (int i=1; i<n; i++)
        if (to[v[i].se]<to[v[i-1].se])
            cout<<"ERROR: "<<v[i].fi<<"->"<<to[v[i].se]<<", but "<<v[i-1].fi<<"->"<<to[v[i-1].se]<<"\n";

    while ((up.size()>0) and (down.size()>0))
    {
        auto pa=*prev(up.end());
        auto it=down.lower_bound({pa.fi+1, 0});
        if (it==down.end())
            cout<<"NO\n", exit(0);
        auto pa2=*it;
        mov(pa.se, pa2.se, min(to[pa.se]-pa.fi, pa2.fi-to[pa2.se]));
    }
    if ((up.size()>0) or (down.size()>0))
        cout<<"NO\n", exit(0);
    cout<<"YES\n";
    cout<<ans.size()<<"\n";
    for (auto pa:ans)
        cout<<pa.fi.fi<<" "<<pa.fi.se<<" "<<pa.se<<"\n";
}