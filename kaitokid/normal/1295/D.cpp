#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,m,t;

int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>a>>m;
        ll u=__gcd(a,m);
        m/=u;
        ll l=(a/u)-1;
        ll i=2;
        ll r=(a+m*u-1)/u;
        ll x=2;
        ll ans1=l,ans2=r;
        while(m>1&&i<1000000)
        {
            if(m%i>0){i++;continue;}
            while(m%i==0)m/=i;
            //cout<<ans2<<" ";
            ans1=(ans1*(i-1.0))/i;
            ans2=(ans2*(i-1.0))/i;
            //cout<<i<<" "<<ans2<<endl;
            i++;

        }
        if(m>1){ans1*=(1.0-(1.0/m));
            ans2*=(1.0-(1.0/m));
            }
            cout<<ans2-ans1<<endl;
    }
    //int q=3*(1.0-1.0/3);
    //cout<<q;
    return 0;
}