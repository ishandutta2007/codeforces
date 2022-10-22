#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int l,r,a;
    cin>>l>>r>>a;
    int ans=(r/a)+(r%a);
    r-=(r%a);
    r--;
    if(r>=l)ans=max(ans,(r/a)+(r%a));
    cout<<ans<<endl;
    }
    return 0;
}