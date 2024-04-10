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
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
int n,k,m,x,y,l,l2,z,a[200001],b[100001],ans;map<int,int>nums;pair<int,int>p1,p2;


int main()
{
    ios_base::sync_with_stdio(false);
cin>>n;
for(int i=1,j=0;i<=n;i+=2,j++) a[j]=i;
for(int i=0;i<n/4;i++)a[i]++;
if(n%2)
{
    if((n/2)%2==0)
a[n/4-1]--,a[n/2]-=a[n/4-1],ans++;
    else
    a[n/2]-=a[n/2]/2;

}
else{if((n/2)%2)ans++;}
cout<<ans<<endl<<n/2+(n%2!=0)<<" ";
int i=0;
while(a[i]!=0)cout<<a[i++]<<" ";

return 0;
}