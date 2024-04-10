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

    int a[n+1],x;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n==1)
    {
        cout<<1<<" "<<1<<endl;
        x=a[1]*(-1);
        cout<<x<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        return;
    }

    cout<<1<<" "<<n-1<<endl;
    for(int i=1;i<=n-1;i++)
    {
        x=a[i]*(n-1);
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<2<<" "<<n<<endl;
    for(int i=1;i<=n-2;i++) cout<<0<<" ";
    x=a[n]*(n-1);
    cout<<x<<endl;
    cout<<1<<" "<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        x=a[i]*n;
        x*=(-1);
        cout<<x<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}