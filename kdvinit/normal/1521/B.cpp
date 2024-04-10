/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int GCD(int x, int y)
{
    if(x%y==0) return y;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int mni=1;

    for(int i=2; i<=n; i++)
    {
        if(a[i]<a[mni]) mni=i;
    }

    cout<<n-1<<endl;

    int lst=a[mni];
    for(int i=1; i<=n; i++)
    {
        if(i==mni) continue;

        cout<<i<<" "<<mni<<" "<<a[mni]+abs(i-mni)<<" "<<a[mni]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}