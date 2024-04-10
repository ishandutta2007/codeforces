#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
ll s1,q1,n1,s2,q2,n2,r1,r2;
ll ch(int x)
{
    ll g=q2/x;
    return (g*g)%mod;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>q1>>n1>>s2>>q2>>n2;

         r2=s2+q2*(n2-1);
         r1=s1+q1*(n1-1);
        if(((q2%q1)!=0)||(s2<s1)||(r2>r1)||(((s2-s1)%q1)!=0)){cout<<0<<endl;continue;}
        if(((s2-q2)<s1)||((r2+q2)>r1)){cout<<-1<<endl;continue;}
        int z=sqrt(q2);
        ll ans=0;
        for(int i=1;i<=z;i++)
        {
            if(q2%i)continue;
            ll h=__gcd(i*1LL,q1);
            if((q1*i)/h==q2)ans=(ans+ch(i))%mod;
            if((q2/i)==i)continue;
            ll u=q2/i;
            h=__gcd(u,q1);
            if((q1*u)/h==q2)ans=(ans+ch(u))%mod;

        }
        cout<<ans<<endl;
    }
    return 0;
}