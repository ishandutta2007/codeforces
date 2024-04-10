/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

bool ccp(int x, int y)
{
    int g = GCD(x, y);
    return (g==1);
}

void solve()
{
    int n;
    cin>>n;

    int mx[1001]={0};
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        mx[x]=i;
    }

    int ans = -1;

    for(int i=1; i<=1000; i++)
    {
        for(int j=i; j<=1000; j++)
        {
            if(!ccp(i, j)) continue;
            if(mx[i]==0 || mx[j]==0) continue;
            int tmp = mx[i]+mx[j];
            ans = max(ans, tmp);
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