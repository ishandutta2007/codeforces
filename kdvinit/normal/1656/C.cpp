/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

bool solve()
{
    int n;
    cin>>n;

    int a[n+1];
    int p1=0, p0=0;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]==1) p1=1;
        if(a[i]==0) p0=1;
    }

    sort(a+1, a+n+1);

    if(p1==0) return true;
    if(p0==1) return false;

    for(int i=2; i<=n; i++)
    {
        if(a[i]==a[i-1]+1) return false;
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