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
    while(t--)
    {
        cin>>n;set<int>tmp,tmp2;
        int b[n+1];
        memset(b,0,sizeof b);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            b[a[i]]++;
            tmp.insert(a[i]);
        }
        for(int i=1;i<n+1;i++)
        {
            auto it=tmp.lower_bound(i);
            if((*it)!=i)tmp2.insert(i);
        }
        //cout<<tmp2.size()<<endl;
        for(int i=0;i<n;i++)
        {
            if(b[a[i]]>1)
            {
                auto it=--tmp2.end();
                 b[a[i]]--;
                 if(i+1==(*it))
                 {
                     if(tmp2.size()==1){b[a[i]]++;continue;}
                     it--;
                 }
                a[i]=*it;
                tmp2.erase(it);

            }
        }
        ans=tmp.size();
 
        cout<<ans<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";cout<<endl;
    }













    return 0;
}