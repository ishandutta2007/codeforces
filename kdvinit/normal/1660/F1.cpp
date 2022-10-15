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

    int pre[n+1]={0}, cdn[n+1]={0}, a[n+1]={0};

    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='+') a[i]=1;
        else a[i]=-1;
    }

    for(int i=1; i<=n; i++)
    {
        pre[i]=pre[i-1]+a[i];

        cdn[i]=cdn[i-1];
        if(a[i]==-1 && a[i-1]==-1) cdn[i]=max(cdn[i], cdn[i-2]+1);
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int dif = pre[j]-pre[i-1];
            if(dif%3!=0) continue;
            int cd = cdn[j]-cdn[i];
            dif/=3; dif*=-1;
            if(dif>=0 && cd>=dif)
            {
                //cout<<i<<" "<<j<<" -> "<<cd<<" "<<dif<<endl;
                ans++;
            }
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