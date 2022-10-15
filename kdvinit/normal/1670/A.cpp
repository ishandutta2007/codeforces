/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n;
    cin>>n;

    int a[n+1], cn=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]<0) cn++;
        a[i]=abs(a[i]);
    }

    for(int i=1; i<=cn; i++) a[i] = -a[i];
    for(int i=2; i<=n; i++)
    {
        if(a[i]<a[i-1]) return false;
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}