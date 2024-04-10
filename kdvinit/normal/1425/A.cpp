/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;

    int ans=0;
    while(n!=0)
    {
        int m=n/2;
        if(n%2==0)
        {
            if(n==4) { ans+=3; break; }
            if(m%2==1) { ans+=m; n=m-1; }
            else { ans++; n=n-2 ; }
        }
        else
        {
            if(n==5) { ans+=2; break; }
            ans++;
            if(n==1) break;
            if(m%2==1) n=m;
            else n=n-2;

        }
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