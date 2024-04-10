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

    int a[n+1], f[n+1]={0}, p[n+1];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        f[a[i]]++;
        p[a[i]]=i;
    }

    if(f[1]!=1) return false;
    int ind = p[1];

    for(int i=1; i<n; i++)
    {
        int i1=(ind+i-1)%n;
        int i2 = (ind+i)%n;
        if(a[i1]>=a[i2]) continue;
        if(a[i2]!=a[i1]+1) return false;
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