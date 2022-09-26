#include "bits/stdc++.h"

#define fi first
#define se second
#define pb push_back

using namespace std;

#define nmax 100500
typedef long long ll;
#define int ll

int p[2*nmax];
int a[nmax];
int b[nmax];
vector<int> s[nmax];

int get(int i)
{
    if (i==p[i])
        return i;
    return p[i]=get(p[i]);
}

void un(int i, int j)
{
    i=get(i);
    j=get(j);
    if (i==j)
        return;
    p[i]=j;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    vector<pair<int, int> > v;
    cin>>m>>n;
    for (int i=0; i<m; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
        cin>>b[i];


    for (int i=0; i<n+m; i++)
        p[i]=i;

    vector<pair<int, pair<int, int> > > ed;
    for (int i=0; i<m; i++)
    {
        int k, l;
        cin>>k;
        for (int j=0; j<k; j++)
            cin>>l, l--, ed.pb({a[i]+b[l], {i, m+l}});
    }
    sort(ed.begin(), ed.end());
    reverse(ed.begin(), ed.end());
    int ans=0;
    for (auto pa:ed)
    {
        if (get(pa.se.fi)==get(pa.se.se))
            ans+=pa.fi;
        un(pa.se.fi, pa.se.se);
    }
    cout<<ans<<"\n";
}