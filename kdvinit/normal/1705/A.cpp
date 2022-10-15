/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n, x;
    cin>>n>>x;

    int m = 2*n;

    int a[m+1];
    for(int i=1; i<=m; i++) cin>>a[i];
    sort(a+1, a+m+1);

    for(int i=1; i<=n; i++)
    {
        int dif=a[i+n]-a[i];
        if(dif<x) return false;
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