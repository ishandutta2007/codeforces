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

    int ls[n+1]={0}, gr[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++) if(a[j]<a[i]) ls[i]++;

        gr[i][i]=0;
        for(int j=i-1; j>0; j--)
        {
            gr[i][j]=gr[i][j+1];
            if(a[j]>a[i]) gr[i][j]++;
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int tmp=0;
        for(int j=i+1; j<=n; j++)
        {
            tmp -= (gr[j][i+1]);

            //cout<<i<<" "<<j<<" "<<tmp<<endl;

            if(a[j]>a[i])
            {
                ans+=tmp;
            }
            tmp+=ls[j];
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