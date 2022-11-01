#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll a,b;scanf("%lld%lld",&a,&b);
        a=min(a,b);
        ll k=b/a,s=b%a;
        ll ans=0;
        ans+=k*k*(a-s);
        ans+=(k+1)*(k+1)*s;
        printf("%lld\n",ans);
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int a,b;scanf("%d%d",&a,&b);
        a*=2;
        bool flag=true;
        if((a-b)%3) flag=false;
        else
        {
            int y=(a-b)/3;
            if((b-y)%2) flag=false;
        }
        a/=2;
        if(a==b*2||b==a*2) flag=true;
        printf(flag?"YES\n":"NO\n");
    }
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r,b,k;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&r,&b,&k);
        ll s=r/__gcd(r,b)*b;
        bool flag=true;
        if(2*r<s&&2*r<=k) flag=false;
        if(2*b<s&&2*b<=k) flag=false;
        if(2*r==s&&2*r<=k)
        {
            if(2*b<=k) flag=false;
        }
        if(2*b==s&&2*b<=k)
        {
            if(2*r<=k) flag=false;
        }
        printf(flag?"OBEY\n":"REBEL\n");
    }
}
*/