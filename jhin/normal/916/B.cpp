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
    if(ho<0)ho+=24;if(ho>24)ho-=24;
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
long long n,m,x,y,k,z,l,r,pos,t,gd1,gd2,a[200001],ans;set<double>lis;double tw=1;

int main()
{
ios_base::sync_with_stdio(false);

cin>>x>>k;int j=100000;
while(x){if(x&1)a[j]++,ans++;j++;x/=2;}
if(ans>k)return cout<<"NO",0;
j--;
cout<<"YES"<<endl;
while(1)
{
    if(ans+a[j]>k) break;
    if(ans+a[j]<=k&&a[j]!=0){ans+=a[j];a[j-1]+=a[j]*2;a[j--]=0;}
}
   j=100;
   while(!a[j])j++;
   while(1)
   {  if(ans==k)break;
     a[j]--;a[--j]+=2;ans++;

   }
   for(int j=200000;j>=0;j--)while(a[j]--)cout<<j-100000<<" ";


return 0;
}