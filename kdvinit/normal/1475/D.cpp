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

    int a[n+1],sum=0;
    for(int i=1;i<=n;i++) { cin>>a[i]; sum+=a[i]; }

    int b1[n+1],b2[n+1],cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x==1) b1[++cnt1]=a[i];
        else b2[++cnt2]=a[i];
    }

    if(sum<m) { cout<<-1<<endl; return; }

    if(cnt1!=0) sort(b1+1,b1+cnt1+1);
    if(cnt2!=0) sort(b2+1,b2+cnt2+1);

    int ans=2*n;

    int i1=cnt1,val=0,tmp;
    while(val<m && i1>0) val+=b1[i1--];

    int i2=cnt2;
    while(val<m) val+=b2[i2--];

    tmp=(cnt1-i1)+(2*(cnt2-i2));
    ans=min(ans,tmp);

    for(int i=i1+1;i<=cnt1;i++)
    {
        val-=b1[i];
        while(val<m && i2>0) val+=b2[i2--];
        if(val<m) break;
        tmp=(cnt1-i)+(2*(cnt2-i2));
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