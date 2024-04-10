/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int gcd(int a, int b)
{
    
    int r = a%b;
    if(r==0) return b;
    else return gcd(b,r);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    
    int a[n+1],b[m+1];

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    
    sort(a+1,a+n+1);

    int ans;

    if(n==1)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<b[i]+a[1]<<" ";
        }
        cout<<endl;
        return;
    }

    ans=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        if(a[i]==a[i-1]) continue;
        ans=gcd(ans,a[i]-a[i-1]);
    }

    int temp;
    for(int i=1;i<=m;i++)
    {
        temp=gcd(ans,a[1]+b[i]);
        cout<<temp<<" ";
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}