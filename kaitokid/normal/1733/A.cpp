#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx[109],n,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<=k;i++)mx[i]=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            mx[(i%k)]=max(mx[i%k],x);
        }
        ll ans=0;
        for(int i=0;i<k;i++)ans+=mx[i];
        cout<<ans<<endl;
    }
    return 0;
}