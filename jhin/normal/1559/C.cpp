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
int t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],sum;



string s;

bool yes;
ll cnt2;




int main()
{

 ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
            cin>>n;
            for(int i=0;i<n;i++)cin>>a[i];

            yes=false;
            vector<int>tmp;
            for(int i=0;i<n-1;i++)
            {
                if(a[i]!=a[i+1])yes=true;
                if(a[i]==0&&a[i+1])
                {
                    for(int j=0;j<n;j++)
                    {
                        if(i+1==j)tmp.push_back(n+1);
                       tmp.push_back(j+1);
                    }
                break;
                }
            }
            if(tmp.empty())
            {
                if(a[0]==1)
                {
                    tmp.push_back(n+1);
                    for(int i=1;i<=n;i++)tmp.push_back(i);
                }
                else if(a[n-1]==0)
                {
                    for(int i=1;i<=n+1;i++)tmp.push_back(i);
                }

            }
            for(int i=0;i<n+1;i++)cout<<tmp[i]<<" ";cout<<endl;






        }




















    return 0;
}