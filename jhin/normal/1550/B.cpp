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
for(int i=2;i<=100000000;i+=2)
prime[i]=false,prime[i-1]=true;
prime[2]=true;
for(int i=3;i*i<=100000000;i+=2)
    if(prime[i])
        for(int j=i*i;j<=100000000;j+=2*i)
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
    while(t--)
    {
        cin>>n>>x>>y>>s;ans=0;
        cnt=1;
        vector<int>tmp;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])cnt++;
            if(s[i]!=s[i-1]) tmp.push_back(cnt),cnt=1;
            if(i==n-1)tmp.push_back(1);
        }

        if(y>=0)
        {
            cout<<n*(x+y)<<endl;
        }
        else
        {
            ans=n*x;
            int si=tmp.size();
            //if(si%2)
            si=si/2+1;
            for(int i=0;i<si;i++)
            {
               ans+=y;
            }
            cout<<ans<<endl;
        }
    }










    return 0;
}