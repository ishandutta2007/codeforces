    #pragma GCC optimize("O3")
    #include <bits/stdc++.h>

    //    #define int long long
    //#define double long double

    #define y0 y___0
    #define y1 y___1

    #define fi first
    #define se second
    #define pb push_back

    #define timer (clock()*1.0/CLOCKS_PER_SEC)
    #define e 0.000000000000000001

    using namespace std;

int n;
int t;
int lx[51];
int rx[51];
int ly[51];
int ry[51];
int pos[51];
int answer=2e9;
int ans=0;

int ch()
{
    set<pair<int, int> > s;
    int ans=0;

    for (int i=1; i<=n; i++)
        if (pos[i]==0)
            s.insert({lx[i], rx[i]});
    int r=-1;
    int l=0;
    for (auto pa:s)
    {
        if (r>=pa.fi)
            r=max(r, pa.se);
        else
        {
            ans+=r-l+1;
            l=pa.fi;
            r=pa.se;
        }
    }
    ans+=r-l+1;
    s.clear();
    for (int i=1; i<=n; i++)
        if (pos[i]==1)
            s.insert({ly[i], ry[i]});
    r=-1;
    l=0;
    for (auto pa:s)
    {
        if (r>=pa.fi)
            r=max(r, pa.se);
        else
        {
            ans+=r-l+1;
            l=pa.fi;
            r=pa.se;
        }
    }
    ans+=r-l+1;

    answer=min(answer, ans);
    return ans;
}

void good_solution()
{
    for (int i=1; i<=n; i++)
        pos[i]=rand()%2;
    int cur=ch();
    while (true)
    {
        bool f=false;
        for (int i=1; i<=n; i++)
        {
            pos[i]=1-pos[i];
            int cur2=ch();
            if (cur2<cur)
            {
                cur=cur2;
                f=true;
                break;
            }
            else
                pos[i]=1-pos[i];
        }
        if (f==false)
            break;
    }
}

main()
{
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);
    srand(time(0));
    cin>>t>>n;
    for (int i=1; i<=n; i++)
        cin>>lx[i]>>ly[i]>>rx[i]>>ry[i];

    while (timer<0.8)
        good_solution();
    cout<<answer<<"\n";

    return 0;
}