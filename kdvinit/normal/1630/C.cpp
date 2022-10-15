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

    int mxi[n+1]={0};
    for(int i=1; i<=n; i++) mxi[a[i]]=i;

    int ans=0;
    int mx1=-1;
    int mx2=-1;

    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        int y = mxi[x];

        if(i==mx1)
        {
            if(mx2==mx1)
            {
                mx1=-1;
                mx2=-1;
                continue;
            }
            else
            {
                ans+=(mx2-mx1-1);
                mx1 = mx2;
                continue;
            }
        }


        if(y==i) continue;

        if(mx1==-1)
        {
            mx1 = y;
            ans += (y-i-1);
            mx2 = y;
        }
        else
        {
            mx2 = max(mx2, y);
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}