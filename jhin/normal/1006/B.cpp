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
    for(long long i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=(num%mod*i%mod)%mod;
    return int(num);
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
int n,k,m,x,b[100001];string s;pair<int,int>a[100001];

int main()
{
    ios_base::sync_with_stdio(false);
cin>>n>>k;
for(int i=0;i<n;i++){cin>>a[i].first;a[i].second=i;}
if(k==1)
    {for(int i=0;i<n;i++)x=max(x,a[i].first);
cout<<x<<endl<<n;return 0;}
sort(a,a+n);
for(int i=n-1,j=0;i>=n-k;i--,j++){x+=a[i].first;b[j]=a[i].second;}
cout<<x<<endl;

sort(b,b+k);
cout<<b[0]+1<<" ";
for(int i=1;i<k-1;i++)cout<<b[i]-b[i-1]<<" ";
cout<<n-b[k-2]-1;



return 0;
}