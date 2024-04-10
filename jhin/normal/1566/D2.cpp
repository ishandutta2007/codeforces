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

int pfact(int x)
{ int cnt=0; if(x%2==0){while(x%2==0)x/=2,cnt++;}
for(int i=3;i*i<=x;i+=2)
if(x%i==0){while(x%i==0)x/=i,cnt++;}
if(x>1)cnt++;
return cnt;

}
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],sum;



bool yes;



int main()
{

 ios_base::sync_with_stdio(false);


    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<int>nums;
        map<int,int>mp;
        for(int i=0;i<n*m;i++)
            cin>>a[i],nums.push_back(a[i]);
            sort(nums.begin(),nums.end());
            ans=0;
            vector<int>tmp[n];
        for(int i=0;i<n*m;i++)
        {
            auto it=lower_bound(nums.begin(),nums.end(),a[i]);

            int ind=int(it-nums.begin())+mp[a[i]];
            mp[a[i]]++;
            int im=ind/m;
            tmp[im].push_back(a[i]);
            sort(tmp[im].begin(),tmp[im].end());
            auto it2=lower_bound(tmp[im].begin(),tmp[im].end(),a[i]);
            int ind2=int(it2-tmp[im].begin());
            ans+=ind2;
            //cout<<ans<<" ";
        }

        cout<<ans<<endl;


    }








    return 0;
}