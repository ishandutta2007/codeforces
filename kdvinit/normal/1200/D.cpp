/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1][n+1], ans[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char x; cin>>x;
            if(x=='B') a[i][j]=1;
            else a[i][j]=0;
            ans[i][j]=0;
        }
    }

    int alr[n+1]={0}, alc[n+1]={0};
    int fr[n+1], lr[n+1], fc[n+1], lc[n+1];
    int always=0;

    int mnr[n+1], mxr[n+1], mnc[n+1], mxc[n+1];

    for(int i=1; i<=n; i++)
    {
        fr[i]=n+1;
        lr[i]=0;

        for(int j=1; j<=n; j++)
        {
            if(a[i][j]==1)
            {
                fr[i]=min(fr[i], j);
                lr[i]=max(lr[i], j);
            }
        }

        if(lr[i]==0) { alr[i]=1; always++; }
        else
        {
            mnr[i] = lr[i]-k+1;
            mxr[i] = fr[i];
        }
    }

    for(int j=1; j<=n; j++)
    {
        fc[j]=n+1;
        lc[j]=0;

        for(int i=1; i<=n; i++)
        {
            if(a[i][j]==1)
            {
                fc[j]=min(fc[j], i);
                lc[j]=max(lc[j], i);
            }
        }

        if(lc[j]==0) { alc[j]=1; always++; }
        else
        {
            mnc[j] = lc[j]-k+1;
            mxc[j] = fc[j];
        }
    }

    for(int j=1; j+k-1<=n; j++)
    {
        int tmp=0;
        for(int i=1; i<=k; i++)
        {
            if( alr[i]==0 && mnr[i]<=j && j<=mxr[i] ) tmp++;
        }
        ans[1][j]+=tmp;

        for(int i=2; i+k-1<=n; i++)
        {
            if( alr[i-1]==0 && mnr[i-1]<=j && j<=mxr[i-1] ) tmp--;
            int x = i+k-1;
            if( alr[x]==0 && mnr[x]<=j && j<=mxr[x] ) tmp++;
            ans[i][j]+=tmp;
        }
    }

    for(int i=1; i+k-1<=n; i++)
    {
        int tmp=0;
        for(int j=1; j<=k; j++)
        {
            if( alc[j]==0 && mnc[j]<=i && i<=mxc[j] ) tmp++;
        }
        ans[i][1]+=tmp;

        for(int j=2; j+k-1<=n; j++)
        {
            if( alc[j-1]==0 && mnc[j-1]<=i && i<=mxc[j-1] ) tmp--;
            int x = j+k-1;
            if( alc[x]==0 && mnc[x]<=i && i<=mxc[x] ) tmp++;
            ans[i][j]+=tmp;
        }
    }


    int val=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) val=max(val, ans[i][j]);
    }
    val+=always;

    cout<<val<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}