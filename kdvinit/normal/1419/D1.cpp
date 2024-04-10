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
    sort(a+1,a+n+1);
    int m=(n-1)/2;

    cout<<m<<endl;
    int l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1) cout<<a[r--]<<" ";
        if(i%2==0) cout<<a[l++]<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}