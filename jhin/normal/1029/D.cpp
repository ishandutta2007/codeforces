

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
int m,x,y=1e9,k,z,zero,l,r,pos,t,gd1,gd2,a[200003],b[200003];string s,s2;int n;map<int,int>mp[11];long long ans;
//1 2 3 4 5 6 7
int main()
{
ios_base::sync_with_stdio(false);
cin>>n>>k;
for(int i=0;i<n;i++)
    {cin>>a[i];
     b[i]=log10(a[i])+1;
     a[i]%=k;
     mp[b[i]][a[i]]++;}
 for(int i=0;i<n;i++)
 {


     long long tmp2=a[i];
     for(int j=1;j<=10;j++)
      {
      tmp2=(tmp2*10)%k;
      int ad,ind;
      if(tmp2==0)ind=0;
      else ind=k-tmp2;
if(mp[j].find(ind)!=mp[j].end());
     ad=mp[j][ind];
     if(ind==a[i]&&b[i]==j&&ad)ad--;
     ans+=ad;}
    // cout<<ans<<" "<<ind<<endl;

 }
cout<<ans;

return 0;
}