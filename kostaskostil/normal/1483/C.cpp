#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 3e5 + 100;

bool DEBUG = true;
int p[4*nmax];
int t[4*nmax];
int a[nmax];
int b[nmax];
int l[nmax];
int r[nmax];

void push(int v, int l, int r)
{
    t[v]=max(t[v], p[v]);
    if (l!=r)
        p[2*v]=max(p[2*v], p[v]),
        p[2*v+1]=max(p[2*v+1], p[v]);
    p[v]=-1e18;
}

void upd(int v, int l, int r, int l0, int r0, int val)
{
//    if (DEBUG)
//        cout<<v<<" "<<l<<" "<<r<<" "<<l0<<" "<<r0<<" "<<val<<"\n";
    if (l0>r0)
        return;
    if ((l==l0) and (r==r0))
    {
        p[v]=max(p[v], val);
        push(v, l, r);
    }
    else
    {
        push(v, l, r);

        int m = (l+r)/2;
        if (l0<=m) upd(2*v, l, m, l0, min(r0, m), val);
        else push(2*v, l, m);
        if (r0>m) upd(2*v+1, m+1, r, max(l0, m+1), r0, val);
        else push(2*v+1, m+1, r);
        t[v]=max(t[2*v], t[2*v+1]);
    }
}

int get(int v, int l, int r, int l0, int r0)
{
    push(v, l, r);
    if (l0>r0)
        return -1e18;
    if ((l==l0) and (r==r0))
        return t[v];
    else
    {
        int ans = -1e18;
        int m = (l+r)/2;
        if (l0<=m) ans = max(ans, get(2*v, l, m, l0, min(r0, m)));
        if (r0>m) ans = max(ans, get(2*v+1, m+1, r, max(l0, m+1), r0));
//    if (DEBUG)
//        cout<<v<<" "<<l<<" "<<r<<" "<<l0<<" "<<r0<<"\n";
//    if (DEBUG)
//        cout<<"RETURN "<<ans<<"\n";
        return ans;
    }
}

main()
{
    if (!DEBUG)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    for (int i=0; i<4*nmax; i++)
        p[i]=-1e18, t[i]=-1e18;

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    vector<pair<int, int> > stpars;
    set<int> used;
    for (int i=1; i<=n; i++)
        cin>>b[i], stpars.pb({a[i], i});
    sort(stpars.begin(), stpars.end());
//    reverse(stpars.begin(), stpars.end());
    for (auto pa : stpars)
    {
        int i = pa.se;

        l[i] = 0;
        r[i] = n+1;

        if (used.lower_bound(i) != used.begin())
            l[i] = *prev(used.lower_bound(i));
        if (used.lower_bound(i) != used.end())
            r[i] = *used.lower_bound(i);

        used.insert(i);
    }

    upd(1, 0, n, 0, 0, 0);
    for (int i=1; i<=n; i++)
    {
        int L = l[i]+1;
        int R = r[i]-1;

        int val = get(1, 0, n, L-1, i-1);
//        cout<<"GET "<<L<<" "<<i<<" "<<R<<" "<<val<<"\n";

        upd(1, 0, n, i, R, val + b[i]);
//        cout<<"UPD "<<i<<" "<<R<<" "<<val+b[i]<<"\n";
    }

    cout<<get(1, 0, n, n, n)<<"\n";
}