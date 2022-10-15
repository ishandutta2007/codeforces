/*
K.D. Vinit  |,,|
Hello
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int val[n+1]={0},ans=0;
    for(int i=2;i<n;i++)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1]) { val[i]=1; ans++; }
        if(a[i]<a[i-1] && a[i]<a[i+1]) { val[i]=1; ans++; }
    }

    int cnt=0;
    for(int i=2;i<n;i++)
    {
        int cur=val[i-1]+val[i]+val[i+1];

        int nw1=0,nw2=0,nw;
        int x=a[i+1],y=a[i-1];

        if(i!=2 && a[i-1]>x && a[i-1]>a[i-2]) nw1++;
        if(i!=2 && a[i-1]<x && a[i-1]<a[i-2]) nw1++;

        if(i!=n-1 && a[i+1]>y && a[i+1]>a[i+2]) nw2++;
        if(i!=n-1 && a[i+1]<y && a[i+1]<a[i+2]) nw2++;

        nw=min(nw1,nw2);
        int tmp=cur-nw;
        cnt=max(tmp,cnt);
    }

    ans-=cnt;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}