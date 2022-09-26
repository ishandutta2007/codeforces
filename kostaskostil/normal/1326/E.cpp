#include<bits/stdc++.h>

#define pi 3.14159265359

#define pb push_back
#define fi first
#define se second

#define push push_
#define get get_

using namespace std;

int n, ans;
int p[300500];
int q[300500];

int pos[300500];

int t[1200500]; /// a[i] = ((cnt(x)>=ans) - bombs) on suffix i
int ps[1200500];

void push(int v, int l, int r)
{
    t[v]+=ps[v];
    if (l<r)
    {
        ps[2*v]+=ps[v];
        ps[2*v+1]+=ps[v];
    }
    ps[v]=0;
}

void upd(int v, int l, int r, int l0, int r0, int x)
{
    if ((l==l0) and (r==r0))
    {
        ps[v]+=x;
        return;
    }
    push(v, l, r);
    int m=(l+r)/2;
    if (l0<=m)  upd(2*v,   l, m,   l0, min(r0, m),   x);
    if (r0>m)   upd(2*v+1, m+1, r, max(l0, m+1), r0, x);
    push(2*v, l, m);
    push(2*v+1, m+1, r);
    t[v]=max(t[2*v], t[2*v+1]);
}

int get()
{
    push(1, 1, n);
    return t[1];
}

void add_bomb(int v)
{
    upd(1, 1, n, 1, v, -1);
}

void inc()
{
    upd(1, 1, n, 1, pos[ans], -1);
    ans++;
}

void dec()
{
    ans--;
    upd(1, 1, n, 1, pos[ans], 1);
}

int mx()
{
    return get();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>p[i], pos[p[i]]=i;
    for (int i=1; i<=n; i++)
        cin>>q[i];

    ans=n+1;
    dec();
    for (int i=1; i<n; i++)
    {
        cout<<ans<<" ";
        add_bomb(q[i]);
        inc();
        while (true)
        {
            dec();
            if (mx()>0)
                break;
        }
    }
    cout<<ans<<"\n";
}