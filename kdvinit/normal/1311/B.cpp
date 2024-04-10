/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int a[n+1],p[m+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>p[i];
    sort(p+1,p+m+1);
    for(int i=1;i<=m;i++)
    {
        int j=p[i];
        i++;
        while(i<=m && p[i]==p[i-1]+1) i++;
        i--;
        sort(a+j,a+p[i]+2);
    }

    for(int i=2;i<=n;i++)
    {
        if(a[i-1]>a[i]) { cout<<"NO"<<endl; return; }
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