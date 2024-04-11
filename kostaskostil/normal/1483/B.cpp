#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
//#define int ll
bool DEBUG = false;

const int nmax = 1e5+100;
int l[nmax];
int r[nmax];
int l_r[nmax];
int r_r[nmax];
int p[nmax];
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

    int x = (rand()%2) ? u : v;
    l_r[l[u]]=x;
    r_r[r[v]]=x;
    l[x] = l[u];
    r[x] = r[v];
    p[u] = x;
    p[v] = x;
}

void solve(int _)
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int& i : a)
        cin>>i;

    set<int> breks;
    for (int i=0; i<n; i++)
    {
        int j=(i+1)%n;

        p[i]=i;
        l[i]=i;
        r[i]=j;
        l_r[i]=i;
        r_r[j]=i;

        if (__gcd(a[i], a[j]) == 1)
            breks.insert(i);
    }

    vector<int> ans;
    int pos = 0;
    int lt = n;

    while (!breks.empty())
    {
        if (lt==1)
            break;

        int nt;
        auto it = breks.lower_bound(pos);
        if (it == breks.end())
            it = breks.begin();
        nt = *it;

        breks.erase(it);

        int u = l_r[nt];
        int x = nt;

        int v = l_r[r[u]];
        int y = r[v];

        if (DEBUG)
            cout<<pos<<" -> "<<nt<<" "<<x<<" - "<<y<<"\n";
        ans.pb(r[u]);
        pos = y;

        breks.erase(r[u]);
        if (__gcd(a[x], a[y]) == 1)
            breks.insert(x);

        un(u, v);

        lt--;
    }

    if (lt==1)
    {
        int x = r[get(0)];
        if (a[x]==1)
            ans.pb(x);
    }

    cout<<ans.size();
    for (int i: ans)
        cout<<" "<<i+1;
    cout<<"\n";
}

main()
{
    if (!DEBUG)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int ___;
    cin>>___;
    for (int _ = 1; _ <= ___; _++)
    {
        solve(_);
    }
}