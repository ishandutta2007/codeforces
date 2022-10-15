/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'0';
        if(k%2==1) a[i]=1-a[i];
    }

    int f[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        if(a[i]==1) continue;
        if(k==0) break;
        k--;
        a[i]=1;
        f[i]++;
    }

    if(k%2==1) a[n]=0;
    f[n]+=k;

    for(int i=1; i<=n; i++) cout<<a[i];
    cout<<endl;

    for(int i=1; i<=n; i++) cout<<f[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}