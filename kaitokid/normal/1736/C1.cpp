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
        int n;
        cin>>n;
        ll ans=0;
        int mx=1;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            mx=max(mx,i-x+1);
            ans+=i-mx+1;
        }
        cout<<ans<<endl;

    }

    return 0;

}