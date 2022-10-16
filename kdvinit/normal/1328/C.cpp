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

    int a[n+1],b[n+1],x[n+1];
    for(int i=1;i<=n;i++)
    {
        char y;
        cin>>y;
        x[i]=y-48;
    }

    a[1]=1;
    b[1]=1;

    if(n==1) { cout<<1<<endl<<1<<endl; return; }

    int j;
    for(j=2;j<=n;j++) if(x[j]==1) break;

    if(j>n)
    {
        for(int i=2;i<=n;i++)
        {
            if(x[i]==0) { a[i]=0; b[i]=0; }
            else { a[i]=1; b[i]=1; }
        }
    }
    else
    {
        for(int i=2;i<j;i++)
        {
            if(x[i]==0) { a[i]=0; b[i]=0; }
            else { a[i]=1; b[i]=1; }
        }
        a[j]=1;
        b[j]=0;
        for(int i=j+1;i<=n;i++)
        {
            if(x[i]==0) { a[i]=0; b[i]=0; }
            if(x[i]==1) { a[i]=0; b[i]=1; }
            if(x[i]==2) { a[i]=0; b[i]=2; }
        }
    }

    for(int i=1;i<=n;i++) cout<<a[i];
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<b[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}