/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x,y;
    cin>>x>>y;

    int b=sqrt(x+1);

    if(y<=b)
    {
        int ans=((y)*(y-1))/2;
        cout<<ans<<endl;
        return;
    }

    int ans=((b)*(b-1))/2;

    for(int i=1;i<=b;i++)
    {
        int strt=x/i;
        strt--;
        int nd=x/(i+1);

        strt=min(strt,y);
        nd=max(nd,b+1);

        int tmp=strt-nd+1;

        if(tmp<=0) continue;
        tmp*=i;
        ans+=tmp;
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