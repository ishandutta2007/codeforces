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
            cin>>n>>s;ans=1e9;
            vector<int>mp[27];
            int chars[n];
            memset(chars,0,sizeof chars);

            for(int i=0;i<n;i++)
            {
                int ind=int(s[i]-'a');
                mp[ind].push_back(i);
            }
            for(int i=0;i<26;i++)
            {
               x=0;

               char ch='a'+i;
               int nn=n;yes=true;
               for(int j=0,z=n-1;j<z;)
               {
                   if(s[j]!=s[z])
                   {
                       if(s[j]==ch)
                       {
                           while(s[j]==ch)x++,j++;
                       }
                      else if(s[z]==ch)
                       {
                           while(s[z]==ch)x++,z--;
                       }
                       else {yes=false;break;}
                   }
                   else j++,z--;

               }
               if(yes)ans=min(ans,x);

            }

            if(ans==1e9)ans=-1;
            cout<<ans<<endl;




        }













    return 0;
}