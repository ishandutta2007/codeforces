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

    int t[n+1],diff=0,cons=0;
    for(int i=1;i<=n;i++) cin>>t[i];

    for(int i=2;i<=n;i++)
    {
        if(t[i]!=t[i-1]) { diff=1; break; }
    }

    for(int i=2;i<=n;i++)
    {
        if(t[i]==t[i-1]) { cons=i; break; }
    }

    if(diff==0)
    {
        cout<<1<<endl;
        for(int i=1;i<=n;i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    if(n%2==0)
    {
        cout<<2<<endl;
        for(int i=1;i<=n;i++) cout<<2-(i%2)<<" ";
        cout<<endl;
        return;
    }
    if(cons==0)
    {
        if(t[n]!=t[1])
        {
            cout<<3<<endl;
            for(int i=1;i<n;i++) cout<<2-(i%2)<<" ";
            cout<<3<<endl;
            return;
        }
        else
        {
            cout<<2<<endl;
            for(int i=1;i<=n;i++) cout<<2-(i%2)<<" ";
            cout<<endl;
            return;
        }
    }
    cout<<2<<endl;
    for(int i=1;i<cons;i++)  cout<<2-(i%2)<<" ";
    for(int i=cons;i<=n;i++)  cout<<(i%2)+1<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}