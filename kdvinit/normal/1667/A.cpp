/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int cil(int x, int y)
{
    int z = (x+y-1)/y;
    return z;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans=1e18;
    for(int j=1; j<=n; j++)
    {
        int tmp=0;

        int lst=0;
        for(int k=j-1; k>=1; k--)
        {
            int x = a[k];
            int y = lst/x;
            tmp += (y+1);
            lst = (y+1)*x;
        }

        lst=0;
        for(int k=j+1; k<=n; k++)
        {
            int x = a[k];
            int y = lst/x;
            tmp += (y+1);
            lst = (y+1)*x;
        }

        ans = min(ans, tmp);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}