#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009];
vector<ll>v;
ll go()
{
    ll sum=0,res=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        res=max(res,sum);
        if(sum<0)sum=0;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    ll t,n;
    cin>>t;
    while(t--)
    {
        ll res=0,ans=0;
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];if(i%2==0){ans+=a[i]; a[i]=-1*a[i];}}
        v.clear();
       // cout<<ans<<endl;
        for(int i=1;i<n-1;i+=2)v.push_back(a[i]+a[i+1]);
        res=max(res,go());
        v.clear();
        for(int i=0;i<n-1;i+=2)v.push_back(a[i]+a[i+1]);
        res=max(res,go());
        ans+=res;
        cout<<ans<<endl;
    }
    return 0;
}