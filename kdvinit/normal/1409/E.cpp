/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,k,mxn=1e9+1;
    cin>>n>>k;

    int x[n+2],y[n+1];
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) cin>>y[i];

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }

    sort(x+1,x+n+1);
    int l[n+1]={0},r[n+1]={0};
    int j=1;
    x[n+1]=2*mxn;
    x[0]=(-1)*mxn;
    for(int i=1;i<=n;i++)
    {
        while(x[j]<=x[i]+k) j++;
        r[i]=j-i;
    }
    j=n;
    for(int i=n;i>0;i--)
    {
        while(x[j]>=x[i]-k) j--;
        l[i]=i-j;
    }
    for(int i=2;i<=n;i++) l[i]=max(l[i],l[i-1]);
    for(int i=n-1;i>0;i--) r[i]=max(r[i],r[i+1]);

    int ans=0,temp;
    for(int i=1;i<n;i++)
    {
        temp=l[i]+r[i+1];
        ans=max(ans,temp);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}