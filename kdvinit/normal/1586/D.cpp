/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int nxt[n+1]={0}, used[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        cout<<"? ";
        for(int j=1; j<=n; j++)
        {
            if(i==j) cout<<2<<" ";
            else cout<<1<<" ";
        }
        cout<<endl;
        int k; cin>>k;
        if(k==0 || k==i) continue;
        nxt[i]=k;
        used[k]=1;
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"? ";
        for(int j=1; j<=n; j++)
        {
            if(i==j) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
        int k; cin>>k;
        if(k==0 || k==i) continue;
        nxt[k]=i;
        used[i]=1;
    }

    int cur;
    for(int i=1; i<=n; i++) if(used[i]==0) cur=i;

    int ans[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        //cout<<i<<" "<<cur<<endl;
        ans[cur]=i;
        cur=nxt[cur];
    }

    cout<<"! ";
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}