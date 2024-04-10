#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,k,x;
map<int,ll>mp;
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)

{
mp.clear();
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        x=k-(x%k);
        if(x==k)continue;
        ans=max(ans,1+x+mp[x]*k);
        mp[x]++;
    }
    cout<<ans<<endl;
}    return 0;
}