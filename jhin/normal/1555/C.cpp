#include <bits/stdc++.h>

using namespace std;

using ll = long long;



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
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],sum;



string s,s1;

bool yes;





int main()
{


        cin>>t;
        while(t--)
        {
            cin>>n;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            for(int i=1;i<=n;i++)
                cin>>b[i];
                for(int i=1;i<=n;i++)
                {
                    a[i]+=a[i-1];
                }
                for(int i=1;i<=n;i++)
                {
                    b[i]+=b[i-1];
                }
                mn=1e9;
                for(int i=1;i<=n;i++)
                {
                    int ans1=b[i-1];
                    int ans2=a[n]-a[i];
                    mx=max(ans1,ans2);
                    mn=min(mn,mx);
                }
                cout<<mn<<endl;



        }

























    return 0;
}