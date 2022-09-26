#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define int long long
using namespace std;

int n;
vector<int> g[200500];
vector<int> v;
int d1[200500];
int d2[200500];
vector<pair<int, int> > s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, k;
    cin>>n>>m>>k;
    int x;
    for (int i=1; i<=k; i++)
        cin>>x, v.pb(x);
    for (int x, y, i=1; i<=m; i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    memset(d1, 255, sizeof(d1));
    memset(d2, 255, sizeof(d2));
    queue<int> q;
    q.push(1);
    d1[1]=0;
    while (!q.empty())
    {
        int c=q.front();
        for (int to:g[c])
            if (d1[to]==-1)
                d1[to]=d1[c]+1, q.push(to);
        q.pop();
    }
    q.push(n);
    d2[n]=0;
    while (!q.empty())
    {
        int c=q.front();
        for (int to:g[c])
            if (d2[to]==-1)
                d2[to]=d2[c]+1, q.push(to);
        q.pop();
    }

    for (int i=0; i<k; i++)
        s.pb({d1[v[i]], d2[v[i]]});
    sort(s.begin(), s.end());
    int ans=0;
    for (int i=0; i<k; i++)
        for (int j=i+1; j<min(k, i+400); j++)
            ans=max(ans, min(s[i].fi+s[j].se+1, s[i].se+s[j].fi+1));
    for (int i=0; i<k; i++)
        swap(s[i].fi, s[i].se);
    for (int i=0; i<k; i++)
        for (int j=i+1; j<min(k, i+400); j++)
            ans=max(ans, min(s[i].fi+s[j].se+1, s[i].se+s[j].fi+1));
    srand(time(0));
    for (int x=0; x<10000000; x++)
    {
        int i=((rand()<<15)+rand())%k;
        int j=((rand()<<15)+rand())%k;
        if (i!=j)
            ans=max(ans, min(s[i].fi+s[j].se+1, s[i].se+s[j].fi+1));
    }
    ans=min(ans, d1[n]);
    cout<<ans<<"\n";

    return 0;
}