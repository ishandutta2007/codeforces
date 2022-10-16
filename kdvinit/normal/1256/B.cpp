/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void doit(int a[],int strt,int nd)
{
    if(strt==nd) return;

    int mni=strt;
    for(int i=strt+1;i<=nd;i++)
    {
        if(a[i]<a[mni]) mni=i;
    }

    int mn=a[mni];
    for(int i=mni;i>strt;i--)
    {
        a[i]=a[i-1];
    }
    a[strt]=mn;

    if(mni==strt) doit(a,mni+1,nd);
    else doit(a,mni,nd);
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    doit(a,1,n);

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}