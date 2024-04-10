// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,y,cnt1,cnt2,cnt3,cnt4,k,n,m,t,d,sum,op;int ans=0;ll z;
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
int a[100001],b[100001];int cnt[4],ctn[4];
int main()
{
ios_base::sync_with_stdio(false);

   cin>>n;
   string ch1[n],ch2[n],ch3[n],ch4[n],case1[n],case2[n];
   for(int i=0;i<n;i++)cin>>ch1[i],case1[i]=ch1[i],case2[i]=ch1[i];
   for(int i=0;i<n;i++)cin>>ch2[i];
   for(int i=0;i<n;i++)cin>>ch3[i];
   for(int i=0;i<n;i++)cin>>ch4[i];
   int comp=1;
   for(int i=0;i<n;i++)for(int j=0;j<n;j++)case1[i][j]=char(comp+48),comp^=1;
   comp=0;
   for(int i=0;i<n;i++)for(int j=0;j<n;j++)case2[i][j]=char(comp+48),comp^=1;
   for(int i=0;i<n;i++)for(int j=0;j<n;j++)
   {
       if(ch1[i][j]!=case1[i][j])cnt[0]++;
       if(ch2[i][j]!=case1[i][j])cnt[1]++;
       if(ch3[i][j]!=case1[i][j])cnt[2]++;
       if(ch4[i][j]!=case1[i][j])cnt[3]++;
   }
   sort(cnt,cnt+4);ans+=cnt[0]+cnt[1];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)
   {
       if(ch1[i][j]!=case2[i][j])ctn[0]++;
       if(ch2[i][j]!=case2[i][j])ctn[1]++;
       if(ch3[i][j]!=case2[i][j])ctn[2]++;
       if(ch4[i][j]!=case2[i][j])ctn[3]++;
   }
  sort(ctn,ctn+4);ans+=ctn[0]+ctn[1];
  cout<<ans;

    return 0;
}