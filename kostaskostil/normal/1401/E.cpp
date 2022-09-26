#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define left not_left
#define right not_right

using namespace std;

typedef long long ll;
#define int long long

const int nmax=1e6+100;
int a[nmax];
int t[nmax];
int low[nmax];
int high[nmax];
set<int> left[nmax];
set<int> right[nmax];

int get(int r)
{
    int s=0;
    for (int i=r; i>=0; i&=(i+1), i--)
        s+=t[i];
//    cout<<"get "<<r<<" -> "<<s<<"\n";
    return s;
}

void upd(int r, int val)
{
//    cout<<"upd "<<r<<" += "<<val<<"\n";
    a[r]+=val;
    for (int i=r; i<nmax; i|=(i+1))
        t[i]+=val;
}


main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<pair<int, pair<int, int> > > vx(n);
    vector<pair<int, pair<int, int> > > vy(m);
    for (auto& pa:vx)
        cin>>pa.fi>>pa.se.fi>>pa.se.se;
    for (auto& pa:vy)
        cin>>pa.fi>>pa.se.fi>>pa.se.se;
//2 3
//1 0 999998
//999999 2 1000000
//999999 0 999998
//1 2 1000000
//3 0 1000000
    int ans=0;

    {
        for(int i=0; i<nmax; i++)
            low[i]=0, high[i]=1000000;
        for (auto pa:vy)
        {
            if (pa.se.fi==0)
                low[pa.fi]=max(low[pa.fi], pa.se.se);
            else
                high[pa.fi]=min(high[pa.fi], pa.se.fi);
        }

        for (auto pa:vx)
        {
            if (pa.se.fi==0)
                left[pa.se.se].insert(pa.fi);
            else
                right[pa.se.fi].insert(pa.fi);
        }

        for (int i=0; i<=1000000; i++)
        {
            for (int j:right[i])
            {
                ans-=get(j);
//                cout<<"rt "<<i<<" "<<j<<" "<<ans<<"\n";
            }

            if (low[i] > 0)
            {
                upd(0, 1);
                upd(low[i]+1, -1);
            }
            if (high[i] < 1000000)
            {
                upd(high[i], 1);
                upd(1000001, -1);
            }

            for (int j:left[i])
            {
                ans+=get(j);
//                cout<<"lt "<<i<<" "<<j<<" "<<ans<<"\n";
            }
        }

        for (int i=0; i<=1000000; i++)
        {
            for (int j:right[i])
            {
                ans+=get(j);
            }
        }
    }

    ans++;
    for (auto pa:vx)
        if (pa.se.fi==0)
            if (pa.se.se==1000000)
                ans++;
    for (auto pa:vy)
        if (pa.se.fi==0)
            if (pa.se.se==1000000)
                ans++;
    cout<<ans<<"\n";

    return 0;
}