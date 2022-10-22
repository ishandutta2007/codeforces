#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,x,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>a>>b;
        int ans=abs(b-a);
        ans=min(ans+x,n-1);
        cout<<ans<<endl;
    }
    return 0;
}