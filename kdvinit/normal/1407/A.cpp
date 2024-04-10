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
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int cnt1=0,cnt0=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) cnt1++;
        else cnt0++;
    }

    if(cnt0>=cnt1)
    {
        cout<<cnt0<<endl;
        for(int i=1;i<=cnt0;i++)
        {
            cout<<0<<" ";
        }
        cout<<endl;
    }
    else
    {
        if(cnt1%2==1) cnt1--;
        cout<<cnt1<<endl;
        for(int i=1;i<=cnt1;i++)
        {
            cout<<1<<" ";
        }
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