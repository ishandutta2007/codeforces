#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
//#define int ll

using namespace std;

map<set<int>, int> mp;
vector<int> pr;

bool do_()
{
    vector<pair<set<int>, int> > vx;
    for (auto pa : mp)
        if (pa.se % 2 == 0)
    {
        if (pa.fi.size()>0)
            vx.pb(pa);
    }
    for (auto& pa:vx)
    {
        mp.erase(pa.fi);
        pa.fi.clear();
        mp[pa.fi]+=pa.se;
    }
    return vx.size()>0;
}

int ans()
{
    int mx=0;
    for (auto pa:mp)
        mx=max(mx, pa.se);
    return mx;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=2; i<=1000; i++)
    {
        bool ok=true;
        for (int j=2; j*j<=i; j++)
            if (i%j==0)
                ok=false;
        if (ok)
            pr.pb(i);
    }

    int ___;
    cin>>___;
    for (int _ = 0; _<___; _++)
    {
        mp.clear();
        int n;
        cin>>n;
        for (int i=1, x; i<=n; i++)
        {
            set<int> mpx;
            cin>>x;
            for (int j : pr)
                if (x%j==0)
            {
                int c=0;
                while (x%j==0)
                    x/=j, c++;
                if (c%2)
                    mpx.insert(j);
            }
            if (x > 1)
                mpx.insert(x);
            mp[mpx]++;
        }
        int q;
        cin>>q;
        vector<pair<ll, int> > qur(q);
        for (int i=0; i<q; i++)
            qur[i].se=i, cin>>qur[i].fi;
        sort(qur.begin(), qur.end());
        vector<int> answ(q);
        ll tim=0;
        int curans=-1;
        bool ok=false;
        for (auto pa:qur)
        {
//            cout<<tim<<" "<<ans()<<"\n";
            while (tim < pa.fi)
            {
                ok=false;
                tim++;
                do_();
                tim=1e18;
            }
            if (ok)
                answ[pa.se]=curans;
            else
                answ[pa.se]=ans();
            curans=answ[pa.se];
            ok=true;
        }
        for (int i:answ)
            cout<<i<<"\n";
    }
}