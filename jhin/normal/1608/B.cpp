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



ll my_pow(ll x,ll y)
{  ll num=1;
    for(ll i=x;y>0;i=(i*i),y>>=1)
        if(y&1){num=(num*i);}
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
            cin>>n>>x>>y;
            set<int>nums;
            for(int i=1;i<n+1;i++)nums.insert(i);
            if(x==0&&y==0){for(int i=1;i<n+1;i++)cout<<i<<" ";cout<<endl;continue;}
            if(x>y+1||x<y-1||x+y>n-2){cout<<-1<<endl;continue;}
            if(x>y)
            {
                cout<<1<<" ";nums.erase(1);
                while(1)
                {
                    if(nums.empty())break;
                    if(x==1)
                    {
                        auto it=--nums.end();
                        cout<<*it<<" ";
                        nums.erase(it);
                        continue;
                    }
                    auto it=nums.begin();
                    it++;
                    cout<<*it<<" ";
                    cout<<*nums.begin()<<" ";
                    nums.erase(it);nums.erase(nums.begin());
                    x--;
                }
                
            }
            else if(x<y)
            {
               cout<<2<<" "<<1<<" ";
               nums.erase(1);nums.erase(2);
                while(1)
                {
                    if(nums.empty())break;
                    if(y==1)
                    {
                        auto it=nums.begin();
                        cout<<*it<<" ";
                        nums.erase(it);
                        continue;
                    }
                    auto it=nums.begin();
                    it++;

                    cout<<*it<<" ";
                    cout<<*nums.begin()<<" ";
                    nums.erase(it);nums.erase(nums.begin());
                    y--;
                }
            }
            else
            {
              cout<<1<<" ";nums.erase(1);
                while(1)
                {
                    if(nums.empty())break;
                    if(x==1)
                    {
                        auto it=--nums.end();
                        cout<<*it<<" ";
                        for(int i=*nums.begin();i<n;i++)cout<<i<<" ";
                        break;
                    }
                    auto it=nums.begin();
                    it++;
                    cout<<*it<<" ";
                    cout<<*nums.begin()<<" ";
                    nums.erase(it);nums.erase(nums.begin());
                    x--;
                }
            }
        cout<<endl;


        }




    return 0;
}