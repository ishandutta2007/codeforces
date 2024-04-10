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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]-=x;
    }

    sort(a+1,a+n+1);

    int j=1,ans=0;
    for(int i=n;i>0;i--)
    {
        while(j<=n && (a[j]+a[i])<=0 ) j++;
        int tmp=(n+1-j);
        if(j<i) tmp--;
        ans+=tmp ;
    }
    ans/=2;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}