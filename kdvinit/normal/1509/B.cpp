/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin>>n;

    int a[n+1];
    int cntT=0;

    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;

        if(x=='T') a[i]=1;
        else a[i]=0;

        cntT+=a[i];
    }

    if(2*n!=3*cntT) { cout<<"NO"<<endl; return; }

    int cT=0, cM=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==1) cT++;
        else cM++;

        cT=min(cT, cntT/2);
        if(cM>cT) { cout<<"NO"<<endl; return; }
    }

    cT=0, cM=0;
    for(int i=n; i>0; i--)
    {
        if(a[i]==1) cT++;
        else cM++;

        cT=min(cT, cntT/2);
        if(cM>cT) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}