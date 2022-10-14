#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi =pair<int,int>;

#define f first

#define s second

# define be(v) (v).begin(),(v).end()

#define eb(v)  (v).begin(),(v).end(),greater<int>()



const int mod=998244353;
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
set<int>numm;
int pfact(int x)
{ int cnt=0; if(x%2==0){while(x%2==0)x/=2,cnt++;numm.insert(2);}
for(int i=3;i*i<=x;i+=2)
if(x%i==0){while(x%i==0)x/=i,cnt++;numm.insert(i);}
if(x>1)cnt++,numm.insert(x);
return cnt;

}
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],sum;



string s;

bool yes;



int main()
{

 ios_base::sync_with_stdio(false);




    cin>>t;
    while(t--)
    {
        cin>>n;bool iseq=true;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]!=a[0])iseq=false;
        }
        if(iseq){cout<<"-1\n";continue;}
        sort(a,a+n);
        for(int i=1;i<n;i++)
        {
            x=a[i]-a[0];
            for(int j=2;j*j<=x;j++)
                if(x%j==0)
                numm.insert(j),numm.insert(x/j);
            if(x)numm.insert(x);
        }
         ans=1;
        for(auto it=numm.begin();it!=numm.end();it++)
         {

          yes=true;
          int tst=*it;
            for(int i=1;i<n;i++)
            {
                if((a[i]-a[0])%tst!=0)yes=false;
            }
            if(yes)ans=max(ans,ll(tst));

        }
        cout<<ans<<endl;



    }







    return 0;
}