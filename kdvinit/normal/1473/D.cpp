/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int a[n+1];
    char x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x=='-') a[i]=-1;
        else a[i]=1;
    }

    int mxl[n+2]={0},mnl[n+2]={0},mxr[n+2]={0},mnr[n+2]={0},tot,sum[n+1]={0};
    int mx=0,mn=0,cnt=0;

    for(int i=1;i<=n;i++)
    {
        cnt+=a[i];
        sum[i]=cnt;
        mx=max(mx,cnt);
        mn=min(mn,cnt);
        mxl[i]=mx;
        mnl[i]=mn;
    }

    tot=cnt;
    cnt=0; mx=0; mn=0;
    for(int i=n;i>0;i--)
    {
        cnt+=a[i];
        mx=max(mx,cnt);
        mn=min(mn,cnt);
        mxr[i]=mx;
        mnr[i]=mn;
    }

    while(m--)
    {
        int l,r;
        cin>>l>>r;

        if(r==n)
        {
            int ans=mxl[l-1]+1-mnl[l-1];
            cout<<ans<<endl;
            continue;
        }

        if(l==1)
        {
            int cur=tot-sum[r];
            int x=cur-mxr[r+1];
            int y=cur-mnr[r+1];
            int ans=y+1-x;
            cout<<ans<<endl;
            continue;
        }

        int cur=tot-(sum[r]-sum[l-1]);

        int x=min(mnl[l-1], cur-mxr[r+1]);
        int y=max(mxl[l-1], cur-mnr[r+1]);

        int ans=y+1-x;
        cout<<ans<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}