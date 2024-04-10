#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int>mp;
ll a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        mp.clear();
        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
        if((2*sum)%n){cout<<0<<endl;continue;}
        ll s=(2*sum)/n;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=mp[s-a[i]];
            mp[a[i]]++;

        }
        cout<<ans<<endl;

    }
    return 0;
}