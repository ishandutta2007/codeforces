/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int mx_neg(int a[],int n)
{
    int sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum<0) ans=i;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1],l[n+1],b[n+1],c[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>l[i];

    int unlock[n+1],m=0;
    for(int i=1;i<=n;i++)
    {
        if(l[i]==1) continue;
        unlock[m++]=a[i];
    }

    int cnt=0;
    sort(unlock,unlock+m);

    for(int i=1;i<=n;i++)
    {
        if(l[i]==1)
        {
            b[i]=a[i];
            continue;
        }
        b[i]=unlock[cnt++];
    }

    for(int i=1;i<=n;i++)
    {
        if(l[i]==1)
        {
            c[i]=a[i];
            continue;
        }
        c[i]=unlock[--cnt];
    }

    int k1=mx_neg(b,n);
    int k2=mx_neg(c,n);

    if(k1<k2)
    {
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++) cout<<c[i]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}