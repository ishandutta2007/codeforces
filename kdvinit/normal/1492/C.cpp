/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    char a[n+1], b[m+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int k=m;
    int mx[m+1];
    for(int i=n;i>=1;i--)
    {
        if(a[i]==b[k])
        {
            mx[k]=i;
            k--;
        }
        if(k==0) break;
    }

    //cout<<k<<endl;

    int ans=0;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[j])
        {
            int tmp=mx[j+1]-i;
            ans=max(ans,tmp);
            j++;
            if(j==m) break;
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