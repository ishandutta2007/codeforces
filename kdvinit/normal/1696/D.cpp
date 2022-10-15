/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int pos[n+1];
    for(int i=1; i<=n; i++) pos[a[i]]=i;

    int pmx[n+1], pmn[n+1];
    pmx[1]=a[1]; pmn[1]=a[1];

    for(int i=2; i<=n; i++)
    {
        pmx[i]=max(pmx[i-1], a[i]);
        pmn[i]=min(pmn[i-1], a[i]);
    }

    int smx[n+1], smn[n+1];
    smx[n]=a[n]; smn[n]=a[n];

    for(int i=n-1; i>=1; i--)
    {
        smx[i]=max(smx[i+1], a[i]);
        smn[i]=min(smn[i+1], a[i]);
    }

    int ans=0;

    int i=pos[1];
    int lst=0;

    while(i!=1)
    {
        ans++;
        if(lst==0)
        {
            int x = pmx[i-1];
            i=pos[x];
            lst=1;
        }
        else
        {
            int x = pmn[i-1];
            i=pos[x];
            lst=0;
        }
    }

    i=pos[1];
    lst=0;

    while(i!=n)
    {
        ans++;
        if(lst==0)
        {
            int x = smx[i+1];
            i=pos[x];
            lst=1;
        }
        else
        {
            int x = smn[i+1];
            i=pos[x];
            lst=0;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}