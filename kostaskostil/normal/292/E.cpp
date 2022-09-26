#include <bits/stdc++.h>

using namespace std;

const int nmax=1e5+100;
int a[nmax];
int b[nmax];
set<pair<int, int> > p[nmax];

int t[4*nmax];

void upd(int v, int l, int r, int l0, int r0, int x)
{
    if ((l==l0) and (r==r0))
    {
        t[v]=x;
        return;
    }
    int m=(l+r)/2;
    if (t[v]!=-1)
        t[2*v]=t[2*v+1]=t[v];
    t[v]=-1;
    if (l0<=m) upd(2*v, l, m, l0, min(r0, m), x);
    if (r0>m) upd(2*v+1, m+1, r, max(l0, m+1), r0, x);
}

int get(int v, int l, int r, int p)
{
    if ((t[v]!=-1) or (l==r))
        return t[v];
    int m=(l+r)/2;
    if (p<=m) return get(2*v, l, m, p);
    return get(2*v+1, m+1, r, p);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(t, 255, sizeof(t));
    int n, q;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    memset(p, 255, sizeof(5));
    for (int i=1; i<=q; i++)
    {
        int typ;
        cin>>typ;
        if (typ==1){
            int x, y, l;
            cin>>x>>y>>l;
            while ((!p[y].empty()) and ((*p[y].begin()).first <= y+l-1))
                p[y].erase(p[y].begin());
            p[y].insert({y+l-1, x});
            upd(1, 1, n, y, y+l-1, y);
        }
        else
        {
            int v, x;
            cin>>v;
            x=get(1, 1, n, v);
            if (x==-1) cout<<b[v]<<"\n";
            else
            {
                auto it=p[x].lower_bound({v, 0});
                cout<<a[(*it).second +v-x]<<"\n";
            }
        }
    }

    return 0;
}