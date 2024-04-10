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

    sort(a+1, a+n+1);

    int vis[n+1]={0};
    for(int i=n; i>=1; i--)
    {
        int x = a[i];
        while(x>n) x/=2;
        while(x!=0)
        {
            if(vis[x]==0) {vis[x]=1; break; }
            x/=2;
        }
    }

    for(int i=1; i<=n; i++) if(vis[i]==0) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}