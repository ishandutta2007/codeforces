/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

void solve()
{
    int n,k,q;
    cin>>n>>k>>q;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int cntnd[n+1][k+1];
    for(int i=1;i<=n;i++) cntnd[i][0]=1;

    for(int j=1;j<=k;j++)
    {
        cntnd[1][j]=cntnd[2][j-1];
        cntnd[n][j]=cntnd[n-1][j-1];
        for(int i=2;i<n;i++)
        {
            cntnd[i][j]=cntnd[i+1][j-1]+cntnd[i-1][j-1];
            cntnd[i][j]%=mod;
        }
    }

    int cntf[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            cntf[i]+= ( (cntnd[i][j]*cntnd[i][k-j])%mod ) ;
            cntf[i]%=mod;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=( (a[i]*cntf[i])%mod );
        ans%=mod;
    }

    while(q--)
    {
        int i,x;
        cin>>i>>x;

        int tmp=( ( (x-a[i])*cntf[i] )%mod );
        tmp=(tmp+mod)%mod;
        a[i]=x;

        ans+=tmp;
        ans%=mod;
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}