/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int Infy = 1e15;

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[k+1], t[k+1];
    for(int i=1; i<=k; i++) cin>>a[i];
    for(int i=1; i<=k; i++) cin>>t[i];

    int ans[n+1], temp[n+1];

    for(int i=1; i<=n; i++) ans[i] = Infy;
    for(int i=1; i<=n; i++) temp[i] = Infy;

    for(int i=1; i<=k; i++) temp[a[i]]=t[i];

    int cur=Infy;
    for(int i=1; i<=n; i++)
    {
        cur++;
        cur = min(cur, temp[i]);
        ans[i]=min(ans[i], cur);
    }

    cur=Infy;
    for(int i=n; i>=1; i--)
    {
        cur++;
        cur = min(cur, temp[i]);
        ans[i]=min(ans[i], cur);
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}