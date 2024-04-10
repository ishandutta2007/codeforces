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
        cin>>n>>k;set<int>v[n+1];
        bool erased[n+1];
        memset(erased,0,sizeof erased);
        for(int i=1;i<n;i++)
        {
            cin>>x>>y;
            v[x].insert(y);v[y].insert(x);
        }
            vector<int>toerase;


            for(int i=1;i<n+1;i++)
            {
                if(v[i].size()==1)toerase.push_back(i),erased[i]=true;
                else if(v[i].empty())erased[i]=true;
            }

        while(k--)
        {
            vector<int>toerase2;

            for(int i=0;i<toerase.size();i++)
            {
                int j=toerase[i];
                erased[j]=true;
                if(!v[j].empty()){
                int par=*(v[j].begin());
                v[par].erase(j);
                v[j].erase(par);
                if(v[par].size()==1)toerase2.push_back(par);
                }
            }
            if(toerase.empty())
            {
                for(int i=1;i<n+1;i++)erased[i]=true;
break;
            }
            toerase.clear();
            toerase=toerase2;

        }
        cnt=0;
        for(int i=1;i<n+1;i++)
        {
            if(!erased[i])cnt++;
        }
        cout<<cnt<<endl;


    }







    return 0;
}