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
    int n,k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        if(x=='0') a[i]=0;
        if(x=='1') a[i]=1;
        if(x=='?') a[i]=2;
    }

    for(int i=k+1;i<=n;i++)
    {
        if(a[i]==a[i-k]) continue;
        if(a[i]==1 && a[i-k]==0) { cout<<"NO"<<endl; return; }
        if(a[i]==0 && a[i-k]==1) { cout<<"NO"<<endl; return; }
        if(a[i]==2) a[i]=a[i-k];
        if(a[i-k]==2)
        {
            int j=i-k;
            while(j>0)
            {
                a[j]=a[i];
                j-=k;
            }
        }
    }
    int cnt1=0,cnt0=0;
    for(int i=1;i<=k;i++)
    {
        if(a[i]==1) cnt1++;
        if(a[i]==0) cnt0++;
    }

    cnt1=max(cnt1,cnt0);
    cnt1*=2;

    if(cnt1>k) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}