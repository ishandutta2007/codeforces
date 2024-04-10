// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;



#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<long long> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    //if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i);
    return num;
}

bool prime[1000001];
void sieve(){
    for(int i=2;i<=1000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=1000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
}
void pfact(long long x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(long long i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
long long m,x,y,z,l,t,gd1,gd2;string s;pair<long long,long long> a[150001];char ch;int n;bool ans;
long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main()
{
ios_base::sync_with_stdio(false);
     cin>>n;cin>>x>>y;a[0].first=x;a[0].second=y;gd1=x;gd2=y;
     for(int i=1;i<n;i++)
     {
      cin>>x>>y;
      gd1=gcd(gd1,x*y);
      gd2=gcd(gd2,x*y);
     }
    pfact(gd1);if(!p.empty())if(p[0]==1)p.erase(p.begin());
    if(!p.empty())cout<<p[0];
    else {pfact(gd2);if(!p.empty())if(p[0]==1)p.erase(p.begin());
    if(p.empty())cout<<-1;
    else cout<<p[0];}

     /*if(gd==1)return cout<<-1,0;
     for(int i=0;i<p.size();i++)
     {
         ans=0;
         for(int j=0;j<n;j++)
            {if(a[j].first%p[i]!=0&&a[j].second%p[i]!=0)break;
            if(j==n-1)ans=1;}
            if(ans)return cout<<p[i],0;

     }
     //for(int j=0;j<n;j++) cout<<p[j]<<" ";
     cout<<-1;*/
return 0;
}