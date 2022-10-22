#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{

    ios::sync_with_stdio(0);
    ll t,n,k,l1,l2,r1,r2;
    cin>>t;
    while(t--)
    {
    cin>>n>>k;
    cin>>l1>>r1>>l2>>r2;
    ll v=min(r1,r2)-max(l1,l2);
    v=max(v,0LL);
    ll d=max(r1,r2)-min(l1,l2);

    if(v>0)

    {

        k-=v*n;
        if(k<0){cout<<0<<endl;continue;}
        ll s=(d-v)*n;
        ll ans=min(k,s);
        if(k>s)ans+=(k-s)*2;
        cout<<ans<<endl;
        continue;



    }
    ll ans=1e18;
    v=max(l1,l2)-min(r1,r2);
    ll s=0;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        res+=v;
        s+=d;
        ll u=min(s,k);
        if(k>s)u+=(k-s)*2;
        ans=min(ans,res+u);
    }
    cout<<ans<<endl;
    }
    return 0;
}