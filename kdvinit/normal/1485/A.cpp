/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;

    if(a<b) { cout<<1<<endl; return; }

    int ans=1e9;

    if(b>=100)
    {
        ans=0;
        while(a!=0)
        {
            ans++;
            a/=b;
        }
        cout<<ans<<endl;
        return;
    }

    for(int i=b;i<=100;i++)
    {
        if(i==1) continue;
        int tmp=a, val=i-b;
        while(tmp!=0)
        {
            val++;
            tmp/=i;
        }
        ans=min(ans,val);
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