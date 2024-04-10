// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;



#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    //if(ho<0)ho+=24;if(ho>24)ho-=24;
}
int my_pow(int x,int y)
{    long long num=1;
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


long long  n,m,k,l,r,y,ans;double fr=4.5,x;multiset<double>a;
bool cal(long long x,long long k)
{
   long long cnt=0;
   while(x>9)
   {
       if(k>x){cnt+=x,x=0;break;}
       cnt+=k;
       x-=k;
       x-=x/10;
   }
   cnt+=x;
   if(cnt>=n-cnt)return true;
   return false;
}
int main()
{
cin>>n;
long long lft=1,rit=1e18;
while(lft<=rit)
{   k=lft+(rit-lft)/2;
    if(cal(n,k))rit=k-1;
    else lft=k+1;
}
if(cal(n,k-1)&&k>1)k--;
if(!cal(n,k))k++;
cout<<k;

return 0;
}