// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,y,cnt1,cnt2,k,n,m,t,d,sum,op;int ans=1e7;ll z,cnt3;
int ho,mi,se;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
}
bool prime[2000001];
void sieve(){
    for(int i=2;i<=1500000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i*i<=1500000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1500000;j+=2*i)
                prime[j]=false;
}
vector<int> thenumber;
void pfact(int x)
{   if(x%2==0){
    if(prime[2])thenumber.push_back(2);prime[2]=false;
    while(x%2==0)x/=2;
              }
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){if(prime[i])thenumber.push_back(i);prime[i]=false;while(x%i==0)x/=i;}
    if(x>1){if(prime[x])thenumber.push_back(x);prime[x]=false;}
}
int a[100001];
int main()
{
ios_base::sync_with_stdio(false);

   cin>>n>>m;
   for(int i=0;i<m;i++)cin>>x,a[x]++;
   ans=a[1];
   for(int i=2;i<=n;i++)ans=min(ans,a[i]);
   cout<<ans;



    return 0;
}