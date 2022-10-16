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
    int n,x;
    cin>>n>>x;

    int sum=0,flag=1,flag2=0;
    for(int i=1;i<=n;i++)
    {
        int y;
        cin>>y;
        sum+=y;
        if(y!=x) flag=0;
        if(y==x) flag2=1;
    }
    n*=x;

    if(flag==1) { cout<<0<<endl; return; }
    if(sum==n) { cout<<1<<endl; return; }
    if(flag2==1) { cout<<1<<endl; return; }
    cout<<2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}