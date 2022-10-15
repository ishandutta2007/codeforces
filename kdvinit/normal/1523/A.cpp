#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+2]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'0';
    }

    while(m--)
    {
        int nc=1;

        int b[n+1];
        for(int i=1; i<=n; i++)
        {
            if(a[i]==1) b[i]=1;
            else
            {
                b[i]=0;
                int x = a[i-1]+a[i+1];
                if(x==1)
                {
                    nc=0;
                    b[i]=1;
                }
            }
        }

        for(int i=1; i<=n; i++) a[i]=b[i];

        if(nc==1) break;
    }

    for(int i=1; i<=n; i++) cout<<a[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}