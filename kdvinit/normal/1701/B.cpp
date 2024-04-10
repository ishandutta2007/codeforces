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


    cout<<2<<endl;
    int vis[n+1]={0};

    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        int cur=i;
        while(cur<=n)
        {
            cout<<cur<<" ";
            vis[cur]=1;
            cur*=2;
        }
    }

    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}