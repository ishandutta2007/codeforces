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
ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],sum;



string s;

bool yes;





int main()
{


        cin>>n>>m;


        set<int>mp[n+1];
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;

            mp[x].insert(y);
            mp[y].insert(x);

        }
        cnt=0;

               for(int i=1;i<=n;i++)
               {
                   if(mp[i].empty()){cnt++;continue;}


                   int cm=*(--mp[i].end());
                   if(i>cm)cnt++;

               }
        cin>>t;
        while(t--)
        {
            cin>>x;
            if(x==1)
            {
                cin>>x>>y;
                bool yesx=false,yesy=false;
               if(!mp[x].empty())
               {
                   int cm=*(--mp[x].end());
                   if(x>cm)yesx=true;

               }
               else yesx=true;
               if(!mp[y].empty())
               {
                   int cm=*(--mp[y].end());
                   if(y>cm)yesy=true;

               }
               else yesy=true;


                mp[x].insert(y);
                mp[y].insert(x);
                if((x<y&&yesx)||(y<x&&yesy))cnt--;
            }
            else if(x==2)
            {
                cin>>x>>y;
                 bool yesx=false,yesy=false;
               if(!mp[x].empty())
               {
                   int cm=*(--mp[x].end());
                   if(x>cm)yesx=true;

               }

               if(!mp[y].empty())
               {
                   int cm=*(--mp[y].end());
                   if(y>cm)yesy=true;

               }

                mp[x].erase(y);
                mp[y].erase(x);
                if(!yesx)
                {
                    if(mp[x].empty())cnt++;
                    else
                    {
                        int cm=*(--mp[x].end());
                   if(x>cm)cnt++;
                    }
                }
                if(!yesy)
                {
                    if(mp[y].empty())cnt++;
                    else
                    {
                        int cm=*(--mp[y].end());
                   if(y>cm)cnt++;
                    }
                }




            }
            else
            {

               cout<<cnt<<endl;
            }
        }

























    return 0;
}