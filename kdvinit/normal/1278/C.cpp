/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[2*n+1];
    for(int i=1;i<=2*n;i++) cin>>a[i];

    int cnt1=0,cnt2=0;
    for(int i=1;i<=2*n;i++)
    {
        if(a[i]==1) cnt1++;
        else cnt2++;
    }

    if(cnt1==cnt2) { cout<<0<<endl; return; }

    int diff=abs(cnt1-cnt2);

    int mx=1;
    if(cnt2>cnt1) mx=2;

    int cnt=0;
    int cntr[2*n];

    for(int i=1;i<=2*n;i++) cntr[i]=2*n;
    cntr[0]=0;

    for(int i=n+1;i<=2*n;i++)
    {
        if(a[i]==mx) cnt++;
        else cnt--;

        if(cnt>0)
        {
            cntr[cnt]=min(cntr[cnt],i-n);
        }
    }

    int ans=cntr[diff];
    cnt=0;
    for(int i=n;i>0;i--)
    {
        if(a[i]==mx) cnt++;
        else cnt--;

        if(cnt>diff) continue;
        int tmp=n+1-i+cntr[diff-cnt];
        ans=min(ans,tmp);
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