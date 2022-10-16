/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int a,b,x,y,n,p,q,ans,ans2,ans3,ans4;
    cin>>a>>b>>x>>y>>n;

    p=a-x;
    q=b-y;

    if(p+q<=n)
    {
        ans=x*y;
        cout<<ans<<endl;
        return;
    }
    n=(p+q)-n;

    if(n>p) ans2=(a*(y+n-p));
    else ans2=((x+n)*y);

    if(n>q) ans3=(b*(x+n-q));
    else ans3=((y+n)*x);

    ans=min(ans2,ans3);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}