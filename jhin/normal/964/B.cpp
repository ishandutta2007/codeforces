// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,cnt1,cnt2,k,n,m,t,d,sum,op,ans, z;
int ho,mi,se;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
int my_pow(int x,int y)
{    ll num=1;
    for(int i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=((num)*i);
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
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}


int a,b,c;
vector<int> ti;


int main()
{
ios_base::sync_with_stdio(false);

   cin>>n>>a>>b>>c>>t;
   for(int i=0;i<n;i++)
   {cin>>x;ti.push_back(x);}
   sort(ti.begin(),ti.end());
   if(b>=c)cout<<n*a;
   else
   {
       for(int i=1;i<t;i++)
        {auto it=upper_bound(ti.begin(),ti.end(),i);
       if(*it>i||it==ti.end())it--;ans+=it-ti.begin()+1;}

   cout<<n*a+(c-b)*ans;}
    return 0;
}