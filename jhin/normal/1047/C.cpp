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
    if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i);
    return num;
}

bool prime[16000003];int nums[16000003],pnums[15000003];
void sieve(){
    for(int i=2;i<=16000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=4000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=16000000;j+=2*i)
                prime[j]=false;
}

void pfact(int x)
{
   if(x%2==0){nums[2]++;while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        {if(pnums[x]){nums[pnums[x]]++;break;}
            if(x%i==0){nums[i]++;while(x%i==0)x/=i;}
        if(prime[x])break;
        if(pnums[x]){nums[pnums[x]]++;break;}
        }
    if(prime[x])nums[x]++;
}
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,one,gd,two,mn=1e9,l,r,pos,t,a[300003],b[1003];string s,s2;vector<int>v2;long long ans;



int main()
{
ios_base::sync_with_stdio(false);
sieve();
for(int i=3;i<3873;i++)
{   long long j=i*i;
    if(prime[i])while(j<=15000000)pnums[j]=i,j*=i;
}
cin>>n>>a[0];gd=a[0];
for(int i=1;i<n;i++){cin>>a[i];gd=gcd(gd,a[i]);}
for(int i=0;i<n;i++){a[i]/=gd;pfact(a[i]);}
for(int i=2;i<=15000000;i++)mx=max(mx,nums[i]);
if(!mx)cout<<-1;
else cout<<n-mx;


return 0;
}