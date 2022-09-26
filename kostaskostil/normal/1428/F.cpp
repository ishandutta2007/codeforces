#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=500500;
typedef long long ll;
#define int ll

int ans=0;
int n;
int b[nmax];

set<int> stleft, stright;
vector<pair<int, int> > seq[nmax];

void add(int l, int r)
{
    for (int i=r-l+1; i>=1; i--)
    {
        seq[i].pb({l, r});
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string s;
    cin>>s;
    for (int i=1; i<=n; i++)
        b[i]=(s[i-1]-'0');

    int l=-1;
    for (int i=1; i<=n; i++)
    {
        if (b[i]==1)
        {
            if (l==-1)
                l=i;
        }
        else
        {
            if (l!=-1)
            {
                add(l, i-1);
                l=-1;
            }
        }
    }
    if (l!=-1)
        add(l, n);

    for (int i=n; i>=1; i--)
    {
        for (auto pa:seq[i])
        {
            int l=pa.fi;
            int r=pa.se;
            int ltmax=1, rtmax=n;
            int dans=0;

            auto ptl = stright.lower_bound(l);
            if (ptl != stright.begin())
                ltmax = (*prev(ptl)) - (i-1) + 1;

            auto ptr = stleft.upper_bound(r);
            if (ptr != stleft.end())
                rtmax = (*ptr) + i - 1;

            if (l+i-1==r)
                dans=i*(l-ltmax+1)*(rtmax-r+1);
            else
                dans=i*((l-ltmax) + (rtmax-r) + (r-l+1-i+1));
            ans+=dans;

            stleft.insert(l);
            stright.insert(r);

//            cout<<"i: "<<i<<", l:"<<l<<", r:"<<r<<", lmax:"<<ltmax<<", rmax:"<<rtmax<<", dans:"<<dans<<", ans:"<<ans<<"\n";
        }
    }
    cout<<ans<<"\n";
}