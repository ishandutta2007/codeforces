/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int l[n+1],r[n+1];
    vector< vector<int> > time(2*n+1);
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];

    for(int i=1;i<=n;i++)
    {
        time[i].push_back(l[i]);
        time[i].push_back(0);
        time[i].push_back(i);
    }

    for(int i=1;i<=n;i++)
    {
        time[i+n].push_back(r[i]);
        time[i+n].push_back(1);
        time[i+n].push_back(i);
    }

    sort(time.begin()+1,time.end());

    int seg[n+1]={0},cmn=0;
    multiset<int> ms;
    for(int i=1;i<=2*n;i++)
    {
        int type,ind;
        type=time[i][1];
        ind=time[i][2];

        if(type==0)
        {
            int strt=0;
            if(ms.size()!=0) strt=( *ms.begin() );

            if(ms.size()==0) { cmn++; seg[ind]--; }
            if(ms.size()==1) seg[strt]++;

            ms.insert(ind);
        }
        else
        {
            ms.erase( ms.find(ind) );
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++) seg[i]+=cmn;
    for(int i=1;i<=n;i++) ans=max(ans,seg[i]);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}