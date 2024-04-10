#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi =pair<int,int>;

#define f first

#define s second

# define be(v) (v).begin(),(v).end()

#define eb(v)  (v).begin(),(v).end(),greater<int>()



const int mod=1e9+7;
vector<ll> p;



ll my_pow(int x,int y)
{  ll num=1;
    for(ll i=x;y>0;i=(i*i),y>>=1)
        if(y&1){num=(num%mod*i%mod)%mod;}
            return num;
}

bool prime[100000001];
void sieve(){
for(int i=2;i<=1000000;i+=2)
prime[i]=false,prime[i-1]=true;
prime[2]=true;
for(int i=3;i*i<=1000000;i+=2)
    if(prime[i])
        for(int j=i*i;j<=1000000;j+=2*i)
            prime[j]=false;
            }


ll gcd(ll a , ll b)
{
  if(b==0) return a;
           a%=b;
    return gcd(b,a);
}

int pfact(int x)
{ int cnt=0; if(x%2==0){while(x%2==0)x/=2,cnt++;}
for(int i=3;i*i<=x;i+=2)
if(x%i==0){while(x%i==0)x/=i,cnt++;}
if(x>1)cnt++;
return cnt;

}
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],sum;



string s;

bool yes;



int main()
{

 ios_base::sync_with_stdio(false);





cin>>t;
while(t--)
{
    cin>>n;vector<int>od,ev;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2)od.push_back(i);
        else ev.push_back(i);
    }
    int sio=od.size(),sie=ev.size();
    if(abs(sio-sie)>1)cout<<"-1\n";
    else
    {
        ans=0;
        if(sio>sie)
        {
            for(int i=0;i<sio;i++)
            {
                ans+=abs(od[i]-2*i);
            }
        }
        else if(sio<sie)
        {
            for(int i=0;i<sie;i++)
            {
                ans+=abs(ev[i]-2*i);
            }
        }
        else
        {
            ll evv=0,odd=0;
            for(int i=0;i<sio;i++)
            {
                odd+=abs(od[i]-2*i);
            }
            for(int i=0;i<sie;i++)
            {
                evv+=abs(ev[i]-2*i);
            }
            ans=min(evv,odd);

        }
        cout<<ans<<endl;
    }

}


























    return 0;
}