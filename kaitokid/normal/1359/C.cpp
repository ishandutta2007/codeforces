#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll q;
int main()
{
    ios::sync_with_stdio(0);
    cin>>q;
    while(q--)
    {

        long double h,c,t,u=0;

        cin>>h>>c>>t;
        long double df=abs((h+c)/2-t);
        ll ans=2;
        ll l=1,r=1e12+5;
        while(r>=l)
        {
            ll mid=(l+r)/2;

           long double res=(u+mid*h+(mid-1)*c+0.0)/(2*mid-1.0);
         if(res>t)l=mid+1;
        else r=mid-1;

            res=abs(res-t);
            if(res<df){df=res;ans=2*mid-1;}
        if(res==df)ans=min(ans,2*mid-1);
        //cout<<mid<<" "<<res<<endl;
        }

        cout<<ans<<endl;
        }

    return 0;
}