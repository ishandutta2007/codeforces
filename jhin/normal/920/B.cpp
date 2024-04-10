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
int n,m,x,y,k,z,l,r,pos,t,gd1,gd2,a[5001],ans;set<double>lis;double tw=1;vector<int>b;
//1 2 3 4 5 6 7
int main()
{
ios_base::sync_with_stdio(false);
cin>>t;


while(t--)
{
    cin>>n;memset(a,0,sizeof(a));z=0;
    for(int i=0;i<n;i++)
        {cin>>x>>y;
       if(y<=z)a[i]=0;
       else a[i]=max(x,++z),z=a[i];
        }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;

}


return 0;
}