#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax=1e6+100;
int n;
int v[nmax];
int vs[nmax];
int pref[nmax];
int cur[nmax];

int sumbelow(int x)
{
    int l=0;
    int r=n+1;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (vs[m]>x) r=m;
        else l=m;
    }
    return (l*x - pref[l]);
}

int sumabove(int x)
{
    int l=0;
    int r=n+1;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (vs[m]>x) r=m;
        else l=m;
    }
    return (pref[n] - pref[r-1] - (n-r+1)*x);
}

int fullfill(int x)
{
    int l=0;
    int r=1e12;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (sumbelow(m)>x) r=m;
        else l=m;
    }
    return l;
}
int fulltake(int x)
{
    int l=0;
    int r=1e12;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (sumabove(m)>x) l=m;
        else r=m;
    }
    return r;
}

bool cbdaa(int x, bool assignment=false)
{
    for (int i=1; i<=n; i++)
        cur[i]=v[i];

    int xd=x;
    int yd=fullfill(x);
    xd-=sumbelow(yd);

    int xu=x;
    int yu=fulltake(x);
    xu-=sumabove(yu);

//    cerr<<xd<<" "<<xu<<" "<<yd<<" "<<yu<<"\n";
//    cout<<"cur\n";
//    for (int i=1; i<=n; i++)
//        cout<<cur[i]<<" ";
//    cout<<"\n";

    if (yd > yu + 1)
        return false;

    if (yd < yu + 1)
    {
        for (int i=1; i<=n; i++)
        {
            cur[i]=max(cur[i], yd);
            cur[i]=min(cur[i], yu);
        }
    }
    else
    {
        for (int i=1; i<=n; i++)
            if (cur[i]<=yu)
                 cur[i]=yd;
            else cur[i]=yu;
    }

//    cout<<"cur\n";
//    for (int i=1; i<=n; i++)
//        cout<<cur[i]<<" ";
//    cout<<"\n";

    for (int i=1; i<=n; i++)
    {
        if (xd>0)
        if (cur[i]==yd)
            xd--, cur[i]++;
    }
    for (int i=n; i>=1; i--)
    {
        if (xu>0)
        if (cur[i]==yu)
            xu--, cur[i]--;
    }

    if (assignment)
        for (int i=1; i<=n; i++)
            v[i]=cur[i];

    for (int i=1; i<n; i++)
        if (cur[i+1] <= cur[i+1]-2)
            return false;

    for (int i=1; i<n; i++)
        if (cur[i] < cur[i+1])
            return true;

    return false;
}

bool can_be_done_another_action(int x, bool assignment=false)
{
    bool res = cbdaa(x, assignment);
//    cout<<x<<" "<<res<<"\n";
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i], v[i]=v[i]+n-i, vs[i]=v[i];

//    for (int i=1; i<=n; i++)
//        cout<<v[i]<<" ";
//    cout<<"\n";

    sort(vs+1, vs+n+1);
    vs[0]=-1e18;
    vs[n+1]=1e18;

    for (int i=1; i<=n; i++)
        pref[i]=pref[i-1]+vs[i];

//    can_be_done_another_action(0);

    int l=0;
    int r=1e18;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (can_be_done_another_action(m))
            l=m;
        else
            r=m;
    }

    if (can_be_done_another_action(0))
        can_be_done_another_action(r, true);


    for (int i=1; i<=n; i++)
        cout<<v[i]+i-n<<" ";
    cout<<"\n";

    return 0;
}