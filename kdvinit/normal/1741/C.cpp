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

    int a[n+1], pre[n+1]={0};
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
    int tot = pre[n];

    int ans=n;
    for(int i=1; i<=n; i++)
    {
        int cur = i;
        int st = pre[i];
        if(tot%st!=0) continue;

        int lst=i;
        int lft=0;

        for(int j=i+1; j<=n; j++)
        {
            lft+=a[j];
            if(lft<st) continue;

            if(lft>st) break;

            int tmp = j-lst;
            cur = max(cur, tmp);
            lst=j;
            lft=0;
        }

        if(lft==0) ans = min(ans, cur);
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