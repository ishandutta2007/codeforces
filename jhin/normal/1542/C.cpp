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
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003];



string s;
char ch;
bool yes;






int main()
{

    cin>>t;
    sieve();vector<int>tmp;
    for(int i=2;i<10000;i++)
    {
        if(prime[i])
        {
            int j=10;
            int pr=i;
            while(j--)
            {
                tmp.push_back(pr);
                pr*=i;
                if(pr>1000000)break;
            }
        }
    }
    sort(tmp.begin(),tmp.end());
    while(t--)
    {
        cin>>n;ans=0;
        for(int i=0;i<tmp.size();i++)
        {
            ll num=tmp[i];
            for(int j=0;j<tmp.size();j++)
            {
                if(num%tmp[j]==0)
                {
                    while(num>tmp[j])num/=tmp[j];
                    break;
                }
            }
            ll ad=((n+1)*(num-1))/num;
            if(ad==0)break;
            ans+=((ad%mod)*tmp[i])%mod;
            ans%=mod;
            n-=ad;
        }
        cout<<ans<<endl;

    }













    return 0;
}