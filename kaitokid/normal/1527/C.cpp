#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   mp.clear();
        ll n,x,ans=0,suf=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            suf+=mp[x];
            ans+=suf;
            mp[x]+=i;
        }
    cout<<ans<<endl;
    }
}