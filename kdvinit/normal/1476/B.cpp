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
    int n,k;
    cin>>n>>k;

    int p[n+1];
    for(int i=1;i<=n;i++) cin>>p[i];

    int ans=0,sum=p[1];
    for(int i=2;i<=n;i++)
    {
        if( (p[i]*100) > (k*sum))
        {
            int x=p[i]*100;
            int y=x/k;
            if(x%k!=0) y++;
            ans+=(y-sum);
            sum=y;
        }
        sum+=p[i];
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