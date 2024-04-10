#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n;
ll s1,s2,f,w,p,c1,c2;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>p>>f>>c1>>c2>>s1>>s2;
        if(s1>s2){swap(s1,s2);swap(c1,c2);}
        ll ans=0;
        for(int i=0;i<=c1;i++)
        {
            if(i*s1>p)break;
            ll u=(p-i*s1);
            ll res=min(u/s2,c2);
            ll v=min(c1-i,f/s1);
            ll d=f-v*s1;
            ll q=min(c2-res,d/s2);
            ans=max(ans,i+res+v+q);
        }
        cout<<ans<<endl;
    }
    return 0;
}