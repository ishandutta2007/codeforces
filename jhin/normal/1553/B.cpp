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



string s,s1;
char ch;
bool yes;







int main()
{

    cin>>t;
    while(t--)
    {

        cin>>s>>s1;yes=false;n=s.size();m=s1.size();
        for(int i=0;i<n;i++)
        {
            if(s1[0]==s[i]){
                    int ii=0;
                    if(ii==m)yes=true;
            for(int j=i;j<n;j++,ii++)
            {
               if(s1[ii]==s[j]){
                    int jj=ii;
                    if(jj==m-1)yes=true;
                   for(int z=j;z>=0;z--,jj++)
                   {
                      // cout<<s1[jj]<<" "<<s[z]<<endl;
                       if(s1[jj]!=s[z])break;
                       if(jj==m-1)yes=true;
                   }
            }
            else break;

            }
        }
        }
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }






















    return 0;
}