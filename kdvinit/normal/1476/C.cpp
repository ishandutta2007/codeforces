/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ya cout<<"YES"<<endl;
#define nah cout<<"NO"<<endl;

void solve()
{
    int n;
    cin>>n;

    int c[n+1],a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int lst=c[n]-1+2,ans=0;
    for(int i=n-1;i>0;i--)
    {
        int x=a[i+1];
        int y=b[i+1];
        int diff=abs(x-y);
        int lft=c[i]-1-diff;
        ans=max(ans,diff+lst);
        lst=max(lst,diff);
        if(x==y) lst=0;
        lst+=lft;
        lst+=2;
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}