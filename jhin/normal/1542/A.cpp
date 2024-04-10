#include <bits/stdc++.h>

using namespace std;

using ll = long long;



const int mod=998244353;
vector<ll> p;



ll my_pow(int x,int y)
{  ll num=1;
    for(ll i=x;y>0;i=(i*i),y>>=1)
        if(y&1){num=(num%mod*i%mod)%mod;}
            return num;
}

bool prime[10000001],prime2[1000001];
void sieve(){
for(int i=2;i<=10000000;i+=2)
prime[i]=false,prime[i-1]=true;
prime[2]=true;
for(int i=3;i*i<=10000000;i+=2)
    if(prime[i])
        for(int j=i*i;j<=10000000;j+=2*i)
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
ll m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],c[500003],d[500003];char ch;



string s;



int t;
bool yes;



int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;int cnt1=0,cnt2=0;
        for(int i=0;i<2*n;i++)
        {
            cin>>x;
            if(x%2)cnt1++;
            else cnt2++;
        }
        if(cnt1==cnt2)cout<<"Yes\n";
        else cout<<"No\n";

    }





    return 0;
}