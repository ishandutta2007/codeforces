/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int mx=0;
    int tot=0;

    pair<int,int> val[n];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        tot+=a[i];
        if(tot>mx)
        {
            mx=tot;
            val[cnt]={mx, i};
            cnt++;
        }
    }

    int out[m];
    int c2=0;
    for(int i=1;i<=m;i++)
    {
        //if(i!=1) cout<<out[i-2]<<endl;
        int x; cin>>x;
        //cout<<"Hello "<<x<<endl;

        int ans=0;

        //cout<<"Hi 1"<<endl;

        if(x>mx)
        {
            if(tot<=0) { out[c2]=-1; c2++; continue; }

            int y=x-mx;
            int z=( (y-1)/tot ) + 1;
            x-=(z*tot);
            ans+=z*n;
        }

        //cout<<"Hi 2"<<endl;
        // 1 3 6 -5 4 -3 -1 6 10 -8

        if(val[0].first>=x)
        {
            ans+=val[0].second;
            out[c2]=ans-1;
            c2++;
            continue;
        }

        //cout<<"Hi 3"<<endl;

        int l=0;
        int r=cnt-1;

        while(l+1<r)
        {
            int mid=(l+r)/2;

            if(val[mid].first>=x) r=mid;
            else l=mid;
        }

        //cout<<"HI 4"<<endl;

        ans+=val[r].second;
        out[c2]=ans-1;
        c2++;
    }
    //cout<<out[m-1]<<endl<<endl;

    for(int i=0;i<m;i++) cout<<out[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}