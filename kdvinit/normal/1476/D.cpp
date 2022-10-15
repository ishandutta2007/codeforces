/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ya cout<<"YES"<<endl;
#define nah cout<<"NO"<<endl;

void solve()
{
    int n;
    cin>>n;

    int dir[n+1];
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        if(x=='L') dir[i]=-1;
        else dir[i]=1;
    }

    int ans[n+1];
    for(int i=0;i<=n;i++) ans[i]=1;

    for(int i=1;i<=n;i++)
    {
        int j=i;
        int need=dir[i];
        while(j<=n && dir[j]==need)
        {
            j++;
            need*=-1;
        }

        int par=0;
        if(dir[i]==-1) par=1;

        int len=j-i;
        for(int k=i-1;k<j;k++)
        {
            int diff=k-i+1;
            if(diff%2==par) ans[k]+=len;
        }
        i=j-1;
    }

    for(int i=0;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}