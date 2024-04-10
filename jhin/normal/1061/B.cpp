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

bool prime[1000001],prime2[1000001];
void sieve(){
    for(int i=2;i<=1000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i*i<=1000000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
}
vector<int>vv;int cnt=0;
void pfact(long long x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
    for(long long i=3;i*i<=x;i+=2)
        if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
    if(x>1)p.push_back(x),cnt++,vv.push_back(1);
}
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000];string s,s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
vector<pair<int,char>>r1,r2;
map<int,int> mp;
set<int>myset;

int t;bool used;
int main()
{

ios_base::sync_with_stdio(false);
cin>>n>>m;
for(int i=0;i<n;i++)
{
    cin>>a[i];mx=max(mx,a[i]);v.push_back(a[i]);myset.insert(a[i]);sum+=a[i];
}
sort(v.begin(),v.end());
auto it1=v.begin();
int pr=0;
if(n==1)return cout<<0,0;
for(auto it=myset.begin();it!=myset.end();it++)
{
 int tmp=*it;
 auto it2=lower_bound(v.begin(),v.end(),tmp+1);
 
 it2--;
 int see=(it2-it1)+1;
 long long tmp2=tmp;long long see2=see;
 long long chk=see-(tmp-pr);
 if(chk>=0){ans+=(tmp2-1)*see2;if(chk>=num)ans+=num,num=0;else ans+=chk,num-=chk;}
 else
 {
     long long see2=see;
     ans+=(tmp2-1)*(see2-1);
     ans+=pr+see-1;
     num+=-chk;

 }
pr=tmp;
 it1=++it2;
}
cout<<ans;
return 0;
}