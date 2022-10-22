#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],b[200009];
map<ll,ll>mp;
int main()
{
    ll t,n,m;

        ll ans=0,fr=0;
        cin>>n;

mp[0]=1;
        for(int i=2;i<=n+1;i++){cin>>a[i];
a[i]+=a[i-1];
fr=max(fr,mp[a[i]]);
ans+=i-fr-1;

mp[a[i]]=i;
        }
        cout<<ans<<endl;

    return 0;
}