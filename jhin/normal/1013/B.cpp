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
int n,k,m,x,y,z,a[100001],b[100001];bool ans;


int main()
{
    ios_base::sync_with_stdio(false);
cin>>n>>x;
for(int i=0;i<n;i++){cin>>y;a[y]++;if(a[y]==2)ans=true;}
if(ans)return cout<<0,0;
for(int i=0;i<=100000;i++)if(a[i]&&(i&x)!=i)b[i&x]++;
for(int i=0;i<=100000;i++)if(a[i]==1&&b[i]>0)return cout<<1,0;
for(int i=0;i<=100000;i++)if(b[i]>1)return cout<<2,0;
cout<<-1;


return 0;
}