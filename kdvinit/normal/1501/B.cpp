/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int b[n+1]={0};
    int cream = 0;
    for(int i=n;i>0;i--)
    {
        cream = max(cream, a[i]);
        if(cream!=0)
        {
            cream--;
            b[i]=1;
        }
    }

    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}